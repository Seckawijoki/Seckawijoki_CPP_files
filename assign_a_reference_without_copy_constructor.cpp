#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
	
enum ACTOR_MODEL_TYPE
{
	DEFAUT_MODEL = -1,
	HUMAN_MODEL,			//人型
	QUADRUPED_MODEL,		//四肢生物
	SINGLE_BONE_MODEL,		//单一骨骼生物
};

struct CustomActorModelData
{
	std::map<std::string, std::vector<CustomAvatarModelData> > models;
	std::string modelmark;
	ACTOR_MODEL_TYPE type;
	bool leaveworlddel;		//退出存档时删除
	std::string modelname;
	bool skindisplay;		//默认子模型是否显示
	short usedownloadcmnum; //使用的下载微缩模型数量
	int authuin;		//作者
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
