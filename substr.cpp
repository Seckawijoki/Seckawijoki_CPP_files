#include<iostream>
#include<cstring>
#include<string> 
using namespace std;
int main(){
	const char* schemejson = "{\"type\":\"join_room\",\"uin\":0,\"password\":\"\",\"wid\":57389820924557}";
	string temp = string(schemejson);
	cout<<temp<<endl;
	temp = temp.substr(temp.find("wid"));
	cout<<temp<<endl;
	char* temp2;
	sscanf(schemejson, "%[0-9]", temp2);
	cout<<temp2<<endl;
	return 0;
}
