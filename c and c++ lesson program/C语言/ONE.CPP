#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[200];
int main()
{
	int t,i,j,n;
	scanf("%d",&n);
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<(n-i)*2;j++)
			printf(" ");
		for(j=0;j<=i;j++)
		{
			if(j!=0)
			printf(" %d",j);
			else
			printf("0");
		}
		for(t=j-2;t>=0;t--)
			printf(" %d",t);
		printf("\n");
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<(i+1)*2;j++)
			printf(" ");
		for(j=0;j<=n-i-1;j++)

			printf(" %d",j);
		for(t=j-2;t>=0;t--)
			printf(" %d",t);
		if(i!=n-1)
			printf("\n");
	}
	return 0;
}
 
