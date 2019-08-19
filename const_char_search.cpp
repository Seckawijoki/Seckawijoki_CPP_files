#include <iostream>
using namespace std;
#include <string.h>
#include <cstdio>
int main(){
	const char* funcname = "AAA.BBB.CCC.DDD:constructor";
	int length = strlen(funcname);
	cout<<funcname<<endl;
	printf("%x\n", funcname);
	cout<<length<<endl;
	void* point = memchr(funcname, '.', length);
	cout<<point<<endl;
	return 0;
}
