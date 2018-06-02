
#include <iostream>
using namespace std;
int main(){
	int *p;
	int a[] = {0,1,2};
	cout<<(p=a)<<endl;
	cout<<(*p=a[0])<<endl;
	cout<<(p=&a[0])<<endl;
//	cout<<(p=&a)<<endl;
}
