#include <stdio.h>
//compilation needs C++11
template<typename... Args>
void passTemplateParams(const char* f, Args... args){
	printf(f, args...);
}
int main(){
	int a = 2;
	passTemplateParams("%s\n", "passTemplateParams");
	passTemplateParams("%s %d %d %p\n", "second string", 2, a, &a);
	return 0;
}
