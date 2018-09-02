#include<iostream>
using namespace std;
#include<string>
#include<fstream>
#include<sstream>
#include"jsonxx.h"
bool get(long long& fromowid, long long owid){
	char szPath[] = "minibox.fb";
	string szRead;
	ifstream inputfile(szPath);
	if (!inputfile) return false;
	 
	ostringstream buf;
	char c;
	while (buf && inputfile.get(c)){
		buf.put(c);
	}
	szRead = buf.str();
	cout<<szRead<<endl;
	string szFromowid;
//	jsonxx::Object* jsonobj = new jsonxx::Object();
//	jsonobj->parse(szRead);
//	szFromowid = jsonobj->get<jsonxx::String>("fromowid");
//	cout<<szFromowid<<endl;
//	sscanf(szFromowid.c_str(), "%lld", &fromowid);
	cout<<szFromowid<<endl;
	return true;
}
int main(){
	long long fromowid;
	get(fromowid, 0);
	cout<<fromowid<<endl;
	
	std::string szFromowid = "76785851513140";
	sscanf(szFromowid.c_str(), "%lld", &fromowid);
	cout<<fromowid<<endl;
	return 0;
}
