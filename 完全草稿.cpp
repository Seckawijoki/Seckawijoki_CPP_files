# include <iostream>
# include <cstring>
# include <cstdio>
# include <typeinfo>
using namespace std;
/*
	Name: 
	Copyright: 
	Author: 
	Date: 17/05/18 11:35
	Description: 
*/

void print(int a[], int length){
  for (int i = 0 ; i < length; ++i){
  	cout<<a[i]<<' ';
  }
  cout<<endl;
}
void maopao(int a[], int length){
	for (int i = 0 ; i < length; ++i){
		bool sorted = false;
		for (int j = 1 ; j < length - i ; ++j){
			if (a[j-1] > a[j]){
				int temp = a[j-1];
				a[j-1] = a[j];
				a[j] = temp;
				sorted = true;
			}
		}
	  print(a, length);
		if (!sorted)break;
	}
}
int main(){
	const char* const TAG = "JNIMsg";
	cout<<TAG<<endl; 
	int n = 2;
	n+=n-=n*n;
//	cout<<n<<endl;
	n = 123; 
	int m=0123;
//  printf("%o %o\n", m, n);
  
  int a0=0xabcd1234;
	char b0=((char*)&a0)[0];
  cout<<b0<<endl;
  cout<<((char*)&a0)[0]<<endl;
//	float a[2][3] = {{-1,1,2},{3,4,5}};
//	printf("%f\n", *(a[0]+2)); //a[0][2]
//	printf("%f\n", *((a+1)[2])); //地址为a[1][2]的值 
//	printf("%f\n",  a[0][0]); //
//	printf("%f\n", *(a[1]+2)); //a[1][2]
//	printf("%f\n", *(a[1]+3)); //?
//	printf("%f\n", (*(a+1))[2]); //a[1][2]
	
	
//	char*m ="hello"; //编译错误 
//	*(m+1) ='s'; 
//	for(;*m !='\0';m++){	  printf("%c\n",*m); 	}
	
//	int a[] = {45,457,679,23,75,235,12,76,9,0};
//	int length;
//	maopao(a,  length = sizeof(a)/sizeof(int));
//	print(a, length);

  const char * p1;
	char const * p2 = "abc";
	char * const p3 = new char[5];
//	*p1 = 'd';
	p2 = "def";
	*p3 = 'c';
//	cout<<*p1<<endl;
//	cout<<*p2<<endl;
//	cout<<*p3<<endl;
}

