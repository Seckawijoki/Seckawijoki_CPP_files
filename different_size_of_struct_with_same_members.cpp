#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

class Vector3
{ 
public:
	union 
	{
		struct 
		{
			float x, y, z;
		};
		struct 
		{
			float pitch, yaw, roll;
		};
	};
};
class Quaternion
{
public:
	float x, y, z, w;
};

class CustomMotionData{
}; 
	
enum ACTOR_MODEL_TYPE
{
	DEFAUT_MODEL = -1,
	HUMAN_MODEL,			//人型
	QUADRUPED_MODEL,		//四肢生物
	SINGLE_BONE_MODEL,		//单一骨骼生物
};

struct FCMMoveFileLoadData
{
	int moveFromLibType;
	long long owid;
	std::string classname;
	int folderindex;
};

struct FCMMoveFileLoadData2
{
	long long owid;
	std::string classname;
	int moveFromLibType;
	int folderindex;
};


int main(){
	FCMMoveFileLoadData d1;
	FCMMoveFileLoadData2 d2;
//	FullyCustomBoneData c1;
//	FullyCustomBoneData2 c2;
	string s;
	long long ll;
	vector<int> v1;
	vector<FCMMoveFileLoadData2> v2;
	CustomMotionData d3;
	CustomMotionData* d4 = new CustomMotionData(); 
	map<int,int> m1;
	Vector3 vector3;
	Quaternion quaternion;
	printf("main(): sizeof(s) = %d\n", sizeof(s));
	printf("main(): sizeof(ll) = %d\n", sizeof(ll));
	printf("main(): sizeof(v1) = %d\n", sizeof(v1));
	printf("main(): sizeof(v2) = %d\n", sizeof(v2));
	printf("main(): sizeof(d1) = %d\n", sizeof(d1));
	printf("main(): sizeof(d2) = %d\n", sizeof(d2));
	printf("main(): sizeof(d3) = %d\n", sizeof(d3));
	printf("main(): sizeof(d4) = %d\n", sizeof(d4));
	printf("main(): sizeof(m1) = %d\n", sizeof(m1));
	printf("main(): sizeof(vector3) = %d\n", sizeof(vector3));
	printf("main(): sizeof(quaternion) = %d\n", sizeof(quaternion));
//	printf("main(): sizeof(c1) = %d\n", sizeof(c1));
//	printf("main(): sizeof(c2) = %d\n", sizeof(c2));
	
	return 0;
}
