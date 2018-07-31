#pragma once
#include "ui_common.h"
#include "OgreInputHandler.h"
#include <string>

enum eCursorType
{
	eCursorMoveChange = 0,	//在鼠标移动的时候会改变。
	eCursorOnlyOnUi,		//只会在UI上
	eCursorNoMoveChange,			//在鼠标移动的时候不会改变
};

const int MAX_LEVEL_CAN_MOVE = eCursorNoMoveChange;
class XMLManager;


static int s_CursorLevel[] =
{
	eCursorMoveChange,		//普通
	eCursorMoveChange,		//无法点击
	eCursorMoveChange,			//攻击
	eCursorMoveChange,		//拾取
	eCursorMoveChange,		//NPC购买
	eCursorNoMoveChange,		//交易
	eCursorNoMoveChange,		//禁止交易的状态
	eCursorMoveChange,			//谈话
	eCursorNoMoveChange,		//修理
	eCursorMoveChange,		//挖矿
	eCursorMoveChange,		//学习技能
	eCursorMoveChange,		//抓宠物
	eCursorOnlyOnUi,		//超链接
	eCursorMoveChange,		//drag
	eCursorOnlyOnUi,		//拾取按钮指针

	eCursorMoveChange,		//无法攻击
	eCursorMoveChange,		//无法购买
	eCursorMoveChange,		//无法拾取
	eCursorMoveChange,		//无法邮件
	eCursorMoveChange,		//无法挖矿
	eCursorMoveChange,		//无法修理
	eCursorMoveChange,		//无法谈话
	eCursorMoveChange,		//无法训练
};

typedef const char *(*GET_GAMESTRING_FUNC)(int id);
typedef std::pair<std::string, std::string> pairString;
//-----------------------------------------------------------------------------
//  客户端可调用UI的函数接口
//-----------------------------------------------------------------------------
class _OgreExport GameUI : public Ogre::InputHandler
{
//对客户端的接口函数
public:
	GameUI();
	~GameUI();

	virtual int onInputEvent(const Ogre::InputEvent &event);

	bool Create(const char *uires, int default_width, int default_height, int screenw, int screenh, Ogre::UIRenderer* pDisplay, Ogre::ScriptVM *pscriptvm, UI_PLATFORM platform, UI_LANG_VER lang_ver); //
	void resetScreenSize(int width, int height);

	//void Destroy();
	void Update( float deltatime );
	void Render();
	void SendEvent(const char *event);
	void SetCurrentCursor(const char *state);
	void ShowCursor(bool bShow);
	bool isCursorDrag();
	const char *getCurrentCursor();

	void ShowUIPanel(const char *frameName);
	void HideUIPanel(const char *frameName);

	void HideAllRootFrame();

	void SetGameStringFunc(GET_GAMESTRING_FUNC func);

	void UIReceiveMessage(bool bReceive);
//供UI编辑器调用的接口函数
public:
	void SetEditMode(bool editmode);
	bool GetEditMode();
	void SetEditingFrame(const char *framename);

	bool NewXMLFile(const char *uires);
	bool LoadXMLFile(const char *path);
	bool LoadXMLString(const char *str);
	bool SaveXMLFile(const char *path);
	bool AppendTOCFile(const char *path);
	int  readTOCList(const char *path);
	bool parseSingleTOCFile(int index);

private:
	bool FindFile(std::string, std::string&, std::string&);
	bool CopyFile(std::string, bool);
	std::vector<std::string>  m_tocFileList;
	std::vector<pairString>  m_usedTextureInGame;
	XMLManager *m_pXmlmgr;
	bool m_bReceiveMsg;
};

extern  bool g_enableReloadTest;
extern GET_GAMESTRING_FUNC g_func;