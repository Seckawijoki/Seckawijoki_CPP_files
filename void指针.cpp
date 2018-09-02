#include<iostream>
using namespace std;
#include<cstdio>
#include<stdlib.h>
int main()
{
	void* p = malloc(280); 
	printf("%d\n",p);
	p=p+1;
	printf("%d\n",p);
	return 0;	
} 
