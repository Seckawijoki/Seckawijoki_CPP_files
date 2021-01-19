#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Object {
public:
	Object(){
		printf("Object(): this = %d\n", this);
	}
};

void print(const vector<Object>& v){
	printf("\nprint(): &v = %d\n", &v);
	size_t size = v.size();
	for (size_t i = 0; i < size; ++i){
		printf("print(): &v[%d] = %d\n", i, &v[i]);
	}
}

int main(){
	vector<Object> v;
	vector<Object> a;
	vector<Object> equal;
	vector<Object> something;
	vector<Object> constructAssign;
	
	v.resize(3);
	vector<Object> construct(v);
	equal = v;
	something.resize(5);
	a.assign(v.begin(), v.end());
	printf("\nmain(): v");
	print(v);
	printf("\nmain(): a");
	print(a);
	printf("\nmain(): equal");
	print(equal);
	printf("\nmain(): construct");
	print(construct);
	printf("\nmain(): something");
	print(something);
	something.assign(v.begin(), v.end());
	printf("\nmain(): something");
	print(something);
	
	printf("\nmain(): constructAssign");
	constructAssign = vector<Object>(v);
	print(constructAssign);
} 
