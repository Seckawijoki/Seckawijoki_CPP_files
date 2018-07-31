#pragma once
#include "ui_common.h"
#include "OgreInputHandler.h"
#include <string>

enum eCursorType
{
	eCursorMoveChange = 0,	//������ƶ���ʱ���ı䡣
	eCursorOnlyOnUi,		//ֻ����UI��
	eCursorNoMoveChange,			//������ƶ���ʱ�򲻻�ı�
};

const int MAX_LEVEL_CAN_MOVE = eCursorNoMoveChange;
class XMLManager;


static int s_CursorLevel[] =
{
	eCursorMoveChange,		//��ͨ
	eCursorMoveChange,		//�޷����
	eCursorMoveChange,			//����
	eCursorMoveChange,		//ʰȡ
	eCursorMoveChange,		//NPC����
	eCursorNoMoveChange,		//����
	eCursorNoMoveChange,		//��ֹ���׵�״̬
	eCursorMoveChange,			//̸��
	eCursorNoMoveChange,		//����
	eCursorMoveChange,		//�ڿ�
	eCursorMoveChange,		//ѧϰ����
	eCursorMoveChange,		//ץ����
	eCursorOnlyOnUi,		//������
	eCursorMoveChange,		//drag
	eCursorOnlyOnUi,		//ʰȡ��ťָ��

	eCursorMoveChange,		//�޷�����
	eCursorMoveChange,		//�޷�����
	eCursorMoveChange,		//�޷�ʰȡ
	eCursorMoveChange,		//�޷��ʼ�
	eCursorMoveChange,		//�޷��ڿ�
	eCursorMoveChange,		//�޷�����
	eCursorMoveChange,		//�޷�̸��
	eCursorMoveChange,		//�޷�ѵ��
};

typedef const char *(*GET_GAMESTRING_FUNC)(int id);
typedef std::pair<std::string, std::string> pairString;
//-----------------------------------------------------------------------------
//  �ͻ��˿ɵ���UI�ĺ����ӿ�
//-----------------------------------------------------------------------------
class _OgreExport GameUI : public Ogre::InputHandler
{
//�Կͻ��˵Ľӿں���
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
//��UI�༭�����õĽӿں���
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