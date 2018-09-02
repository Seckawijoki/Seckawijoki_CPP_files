#include<iostream>
#include<map>
#define MyMap std::map<int, int*> 
using namespace std;
int main(){
	MyMap mymap;
	for(int i = 0; i < 10; ++i){
		mymap.insert(std::map<int, int*>::value_type(i, new int(i*i)));
	}
	MyMap::iterator it;
	for(it = mymap.begin(); it != mymap.end(); ++it){
		cout<<it->first<<" "<<*(it->second)<<" "<<it->second<<endl;
	}
	it = mymap.begin();
	for (; it != mymap.end(); ++it){
		delete it->second;
	}
	for(it = mymap.begin(); it != mymap.end(); ++it){
		cout<<it->first<<" "<<*(it->second)<<" "<<it->second<<endl;
	}
	return 0;
}
