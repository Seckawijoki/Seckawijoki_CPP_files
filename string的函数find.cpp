#include <iostream>
using namespace std;
int main(){
	string strPath = "F:/trunk/env1/client/AppPlay/Proj.Android.Mini";
	cout<<strPath<<endl;
	int firstIndex = strPath.find("env1"); 
	cout<<firstIndex<<endl;
	cout<<strPath.substr(firstIndex+4)<<endl;
	return 0; 
} 
