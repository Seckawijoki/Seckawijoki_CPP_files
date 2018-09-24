#include<iostream>
#include<stdarg.h>
using namespace std;
void callFunction(const char* funcName, const char* argsFormat, va_list args){
	cout<<"callFunction():\n";
	
	va_arg(args, int);
}
void callLuaFunction(const char* funcName, const char* argsFormat, int count, ...){
	cout<<funcName<<endl<<argsFormat<<endl<<count<<endl;
	va_list p;
	va_start(p, count);
	callFunction(funcName, argsFormat, p);
	va_end(p);
}
int main(){
	callLuaFunction("GetS","d",1,123);
	return 0;
} 
