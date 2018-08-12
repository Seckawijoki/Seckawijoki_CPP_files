#include<iostream>
#include<cstring>
using namespace std;
int isNotEmptyCstr(const char*);
int isNotEmptyCstr2(const char*);

#define IS_NOT_EMPTY(cstr) isNotEmptyCstr2(cstr)

inline int isNotEmptyCstr(const char* cstr){
	if (cstr){
		return 1;
	} else {
		return 0;
	}
}
inline int isNotEmptyCstr2(const char* cstr){
	if (strcmp(cstr, "") != 0){
		return 1;
	} else {
		return 0;
	}
}

int main(){
	const char* cstrEmpty = "";
	const char* cstr = "const char*";
	if (IS_NOT_EMPTY(cstrEmpty) != 0)
		cout<<"cstrEmpty is NOT empty\n";
	if (IS_NOT_EMPTY(cstr) != 0){
		cout<<"cstr is NOT empty\n";
	}
	
	return 0;
} 
