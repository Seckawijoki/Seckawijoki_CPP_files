#include "ui_gameui.h"
#include "ui_common.h"
#include "ui_frame.h"
#include "ui_framemgr.h"
#include "ui_framemgreditor.h"
#include "OgreLog.h"
#include "xml_uimgr.h"
#include "OgreTimer.h"
#include "OgreRoot.h"
#include "ui_texture.h"
#include <iostream>
#include <cstring>
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
#include <io.h>
#include <direct.h>
#include <string>
using std::string;
using std::cout;
using std::endl;
#endif
bool g_enableReloadTest = false;

extern int tolua_UITolua_open (lua_State* tolua_S);

using namespace Ogre;

extern FrameManager *g_pFrameMgr;

#ifdef _DEBUG
FrameManagerEditor *g_pFrameMgrEditor;
#endif

GET_GAMESTRING_FUNC g_func;

//-----------------------------------------------------------------------------
//  客户端可调用UI的函数接口
//-----------------------------------------------------------------------------

extern void ShowUIPanel(const char *frameName);
extern void HideUIPanel(const char *frameName);

GameUI::GameUI()
{
	g_pFrameMgr = new FrameManager;
	m_bReceiveMsg = true;
	m_pXmlmgr = new XMLManager;

#ifdef _DEBUG
	g_pFrameMgrEditor = new FrameManagerEditor(g_pFrameMgr);
#endif
}

GameUI::~GameUI()
{
#ifdef _DEBUG
	delete(g_pFrameMgrEditor);
#endif
	delete(m_pXmlmgr);
	delete(g_pFrameMgr);
}

//int getglobal(lua_State *ls)
//{
//	if( lua_isstring(ls,1) == false )
//	{
//		lua_pushnil( ls );
//	}
//	else 
//		lua_getglobal( ls,lua_tostring( ls,1 ) );
//	return 1;
//}

bool GameUI::Create( const char *uires, int default_width, int default_height, int screenw, int screenh, Ogre::UIRenderer* pDisplay, Ogre::ScriptVM *pscriptvm, UI_PLATFORM platform, UI_LANG_VER lang_ver)
{
	CUR_UI_PLATFORM = platform;
	CUR_UI_LANG_VER = lang_ver;
	DEFAULT_UI_WIDTH = default_width;
	DEFAULT_UI_HEIGHT = default_height;
	if(uires)
	{
		g_pDisplay = pDisplay;
		g_pUIScriptVM = pscriptvm;

		resetScreenSize(screenw, screenh);

		tolua_UITolua_open(g_pUIScriptVM->getLuaState());
		pscriptvm->setUserTypePointer("UIFrameMgr", "FrameManager", g_pFrameMgr);
	
		return NewXMLFile(uires);
	}
	
	return false;
}

void GameUI::resetScreenSize(int width, int height)
{
	g_pFrameMgr->setScreenParam(width, height, Ogre::Root::getSingleton().getScreenEdge());
	g_pFrameMgr->ForceUpdateFramePos();

	g_pUIScriptVM->callFunction("ResetScreenSize", "ii", width, height);
}


void GameUI::Update( float deltatime )
{
#ifdef _DEBUG
	if (g_pFrameMgrEditor)
	{
		g_pFrameMgrEditor->Update(deltatime);
		return;
	}
#endif

	g_pFrameMgr->Update(deltatime);
}

void GameUI::Render()
{
#ifdef _DEBUG
	if (g_pFrameMgrEditor)
	{
		g_pFrameMgrEditor->Render();
		return;
	}
#endif

	g_pFrameMgr->Render();
}

void FindTextureFileName(Frame* pFrame, std::vector<pairString>& fileList)
{
	if (pFrame->m_bShow)
	{
		for (size_t i = 0; i < pFrame->m_DrawRegions.size(); ++i)
		{
			LayoutFrame* pLayout = pFrame->m_DrawRegions[i].pregion;
			if (pFrame->m_DrawRegions[i].pregion->m_bShow && strcmp(pFrame->m_DrawRegions[i].pregion->GetTypeName(), "Texture") == 0)
			{
				::Texture* pTexture = static_cast<::Texture *>(pFrame->m_DrawRegions[i].pregion);
				pairString pair;
				pair.first = pTexture->m_UVName;
				pair.second = pTexture->m_FilePath;
				std::vector<pairString>::iterator it = std::find(fileList.begin(), fileList.end(), pair);
				if (it == fileList.end())
					fileList.push_back(pair);
			}

		}

		for (size_t i = 0; i < pFrame->m_Children.size(); ++i)
		{
			Frame* frame = pFrame->m_Children[i];
			if (frame->m_bShow)
			{
				for (size_t j = 0; j < frame->m_DrawRegions.size(); ++j)
				{
					if (frame->m_DrawRegions[j].pregion->m_bShow && strcmp(frame->m_DrawRegions[j].pregion->GetTypeName(), "Texture") == 0)
					{
						::Texture* pTexture = static_cast<::Texture *>(frame->m_DrawRegions[j].pregion);
						pairString pair2;
						pair2.first = pTexture->m_UVName;
						pair2.second = pTexture->m_FilePath;
						std::vector<pairString>::iterator it = std::find(fileList.begin(), fileList.end(), pair2);
						if (it == fileList.end())
							fileList.push_back(pair2);
					}
				}
				FindTextureFileName(frame, fileList);
			}
		}

	}
}
bool GameUI::FindFile(std::string folderPath, std::string &fileName, std::string &foundPath)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	_finddata_t fileInfo;
	std::string strFind = folderPath + "/*";
	long handle = _findfirst(strFind.c_str(), &fileInfo);
	if (handle == -1L)
	{
		return false;
	}
	do
	{
		if (fileInfo.attrib & _A_SUBDIR)
		{
			if ((strcmp(fileInfo.name, ".") != 0) && (strcmp(fileInfo.name, "..") != 0))
			{
				std::string newPath = folderPath + "/" + fileInfo.name;
				if (FindFile(newPath, fileName, foundPath))
					return true;
			}
		}
		else
		{
			cout << folderPath << "/" << fileInfo.name << endl;
			if (strcmp(fileInfo.name, fileName.c_str()) == 0)
			{
				cout << "找到文件" << fileInfo.name << endl;
				foundPath = folderPath + "/" + fileInfo.name;
				return true;
			}
		}
	} while (_findnext(handle, &fileInfo) == 0);
	_findclose(handle);
#endif
	return false;
}
bool GameUI::CopyFile(std::string src, bool isInGame)
{
#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	char* des = isInGame ? "f:/uitexture_in_game" : "f:/uitexture_in_client";
	mkdir(des);
	string foundPath;
	bool found = FindFile("res", src, foundPath);
	if (found == false)
	{
		cout << "文件" << src << "不存在\n";
		return false;
	}
	FILE* fSrc = fopen(foundPath.c_str(), "rb");
	if (!fSrc)
	{
		cout << "打开文件" << src << "失败。\n";
		return false;
	}
	FILE* fDes = fopen(des, "wb");
	if (!fDes)
	{
		cout << "创建文件" << des << "失败。\n";
		return false;
	}
	unsigned char* buf;
	unsigned int length;
	fseek(fSrc, 0, SEEK_END);
	length = ftell(fSrc);
	buf = new unsigned char[length + 1];
	memset(buf, 0, length + 1);
	fseek(fSrc, 0, SEEK_SET);
	fread(buf, length, 1, fSrc);
	fwrite(buf, length, 1, fDes);
	fclose(fSrc);
	fclose(fDes);
	delete[]buf;
#endif
	return true;
}

int GameUI::onInputEvent(const Ogre::InputEvent &event)
{
#ifdef _DEBUG
	if (g_pFrameMgrEditor)
	{
		return g_pFrameMgrEditor->OnInputMessage(event);
	}
		
#endif
	if (event.msg == GIE_KEYDOWN && event.key.vkey == VK_F6)
	{
		m_usedTextureInGame.clear();
		for (size_t i = 0; i < g_pFrameMgr->m_RootFrames.size(); ++i)
		{
			FindTextureFileName(g_pFrameMgr->m_RootFrames[i], m_usedTextureInGame);
		}
		TiXmlDocument doc;

		TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "utf-8", "yes");
		doc.LinkEndChild(decl);

		for (size_t j = 0; j < m_usedTextureInGame.size(); ++j)
		{
			TiXmlElement * texture = new TiXmlElement("Texture");
			doc.LinkEndChild(texture);
			texture->SetAttribute("Name", m_usedTextureInGame[j].first.c_str());
			texture->SetAttribute("Path", m_usedTextureInGame[j].second.c_str());
			CopyFile(m_usedTextureInGame[j].second.c_str(), true);
		}
		doc.SaveFile("res/ui/filelist.xml");
	}
	if (event.msg == GIE_KEYDOWN && event.key.vkey == VK_F7)
	{
		m_usedTextureInGame.clear();
		for (size_t i = 0; i < g_pFrameMgr->m_RootFrames.size(); ++i)
		{
			FindTextureFileName(g_pFrameMgr->m_RootFrames[i], m_usedTextureInGame);
		}
		for (size_t j = 0; j < m_usedTextureInGame.size(); ++j)
		{
			CopyFile(m_usedTextureInGame[j].second.c_str(), false);
		}
	}
	

	if(g_pFrameMgr && m_bReceiveMsg)
	{
		return g_pFrameMgr->OnInputMessage(event);
	}
	else 
	{
		return INPUTMSG_PASS;
	}
}

void GameUI::SendEvent(const char *event)
{
	if (event)
	{
		g_pFrameMgr->SendEvent(event);
	}
}

void GameUI::SetCurrentCursor(const char *state)
{
	g_pFrameMgr->setCursor(state);
}

void GameUI::ShowCursor(bool bShow)
{
	if (bShow)
	{
		g_pFrameMgr->m_pCurCursor->ShowCursor();
	}
	else
	{
		g_pFrameMgr->m_pCurCursor->HideCursor();
	}
}

bool GameUI::isCursorDrag()
{
	return g_pFrameMgr->m_pCurCursor->IsInDragState();
}

const char *GameUI::getCurrentCursor()
{
	return g_pFrameMgr->m_pCurCursor->getCursor();
}

void GameUI::ShowUIPanel(const char *frameName)
{
	if (frameName)
	{
		::ShowUIPanel(frameName);
	}
}

void GameUI::HideUIPanel(const char *frameName)
{
	if (frameName)
	{
		::HideUIPanel(frameName);
	}
}

void GameUI::HideAllRootFrame()
{
	for(size_t i=0; i<g_pFrameMgr->m_RootFrames.size(); i++)
	{
		g_pFrameMgr->m_RootFrames[i]->Hide();
	}
}

void GameUI::SetGameStringFunc(GET_GAMESTRING_FUNC func)
{
	g_func = func;
}

void GameUI::UIReceiveMessage(bool bReceive)
{
	m_bReceiveMsg = bReceive;
}

void GameUI::SetEditMode(bool mode)
{
	g_pFrameMgr->SetEditMode(UI_MODE_DEBUG);
}

void GameUI::SetEditingFrame(const char *framename)
{
	g_pFrameMgr->SetEditFrame(framename);
}

bool GameUI::GetEditMode()
{
	return g_pFrameMgr->GetEditMode() > 0;
}

bool GameUI::NewXMLFile(const char *uires)
{
	LOG_INFO( "NewXMLFile file name=[%s]", uires );

	g_pFrameMgr->m_ObjectTable.clear();
	g_pFrameMgr->m_TemplateTable.clear();
	g_pFrameMgr->m_RootFrames.clear();

	const char *pdot = strrchr(uires, '.');
	assert(pdot);

	unsigned int t1 = Timer::getSystemTick();

	bool ret = false;
	if(stricmp(pdot, ".toc") == 0) ret = m_pXmlmgr->LoadTOCFile(uires);
	else if(stricmp(pdot, ".xml") == 0) ret = m_pXmlmgr->LoadUIFromXml(uires);

	if(!ret)
	{
		return false;
	}
	unsigned int t2 = Timer::getSystemTick();
	LOG_INFO( "LoadTOCFile file time=[%d]", t2-t1 );

	g_pFrameMgr->m_TocFileName = uires;
	g_pFrameMgr->InitRootFrames();

	unsigned int t3 = Timer::getSystemTick();
	LOG_INFO( "InitRootFrames file time=[%d]", t3-t2 );

	return true;
}


bool GameUI::AppendTOCFile(const char *uires)
{
	LOG_INFO( "AppendTOCFile file name=[%s]", uires );

	unsigned int t1 = Timer::getSystemTick();
	if (!m_pXmlmgr->LoadTOCFile(uires))
	{
		return false;
	}
	unsigned int t2 = Timer::getSystemTick();
	LOG_INFO( "LoadTOCFile2 file time=[%d]", t2-t1 );

	g_pFrameMgr->ForceUpdateFramePos();
	g_pFrameMgr->InitRootFrames();
	unsigned int t3 = Timer::getSystemTick();
	LOG_INFO( "InitRootFrames2 file time=[%d]", t3-t2 );
	return true;
}


int GameUI::readTOCList(const char *uires)
{
	m_tocFileList.clear();
	return m_pXmlmgr->getTOCList(uires, m_tocFileList );
}


bool GameUI::parseSingleTOCFile(int index)
{
	size_t i = size_t(index);
	assert(i < m_tocFileList.size());
	bool ret = m_pXmlmgr->parseSingleTOCFile( m_tocFileList[i]);

	if(i == m_tocFileList.size()-1)
	{
		//加载正好完成
		g_pFrameMgr->ForceUpdateFramePos();
		g_pFrameMgr->InitRootFrames();
	}

	return ret;
}



bool GameUI::LoadXMLFile(const char *path)
{
	if (path)
	{
		g_pFrameMgr->m_RootFramesReload.clear();

		if (!m_pXmlmgr->LoadUIFromXml(path))
		{
			return false;
		}

		g_pFrameMgr->InitRootFramesReload();
		return true;
	}

	return false;
}

bool GameUI::LoadXMLString(const char *str)
{
	if(str)
	{
		g_pFrameMgr->m_RootFramesReload.clear();

		if (!m_pXmlmgr->LoadUIFromXml(str, true))
		{
			return false;
		}

		g_pFrameMgr->InitRootFramesReload();
		return true;
	}

	return false;
}

bool GameUI::SaveXMLFile(const char *path)
{
	if (path)
	{
		if (!m_pXmlmgr->SaveUIToXml(path))
		{
			return false;
		}

		return true;
	}

	return false;
}


