#include<iostream>
#include<set>
using namespace std;
static set<int> getContainerList(){
	static int ids[] = {801, 717, 839, 1032};
	static set<int> s(ids, ids+4);
	return s;
}
static set<int>& getContainerList2(){
	static int ids[] = {801, 717, 839, 1032};
	static set<int> s(ids, ids+4);
	return s;
}
static set<int>* getContainerList3(){
	static int ids[] = {801, 717, 839, 1032};
	static set<int> s(ids, ids+4);
	return &s;
}
static void printSet(set<int>* blockList){
	for (set<int>::iterator it = blockList->begin() ; it != blockList->end(); ++it ){
		cout<<*it<<' ';
	}
	cout<<endl;
}
class AIStoreItem{
public:
	void willRun(){
		set<int> tempSet = getContainerList();
		printSet(&tempSet);
		printSet(&getContainerList2());
		printSet(getContainerList3());
	}
};
int main(){
	AIStoreItem item;
	item.willRun();
	return 0;
}
