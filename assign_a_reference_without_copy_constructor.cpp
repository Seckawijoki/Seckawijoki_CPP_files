#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
	
enum ACTOR_MODEL_TYPE
{
	DEFAUT_MODEL = -1,
	HUMAN_MODEL,			//����
	QUADRUPED_MODEL,		//��֫����
	SINGLE_BONE_MODEL,		//��һ��������
};

struct CustomActorModelData
{
	std::map<std::string, std::vector<CustomAvatarModelData> > models;
	std::string modelmark;
	ACTOR_MODEL_TYPE type;
	bool leaveworlddel;		//�˳��浵ʱɾ��
	std::string modelname;
	bool skindisplay;		//Ĭ����ģ���Ƿ���ʾ
	short usedownloadcmnum; //ʹ�õ�����΢��ģ������
	int authuin;		//����
};

class CustomModelMgr{
public:
	setCurEditActorModelData(CustomActorModelData &data){
		m_CurEditActorModel = data;
	}
	CustomActorModelData m_CurEditActorModel; 
};

int main(){
	CustomActorModelData data;
	CustomModelMgr mgr;
} 
