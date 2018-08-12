#include<iostream>
using namespace std;
int main(){
	char* cstr;
	long long uid = 123456789123456789;
	sprintf(cstr, "%lld", uid);
	cout<<cstr<<endl;
	
	const char* cstr2 = "987654321987654321";
	long long uid2 = 0;
	sscanf(cstr2, "%lld", &uid2);
	cout<<uid2<<endl;
	return 0;
} 
