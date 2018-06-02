
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int a[9989899],p[1005];
__int64 j,i;
int b,c,d,n,m,k;
int f(int c)
{
	b=c;
	d=0;
	while(c)
	{
		d=d*10+c%10;
		c=c/10;

	}
	if(d==b)
		return 1;
	else
		return 0;

}

int main()
{

	memset(a,0,sizeof(a));
	a[1]=1;
	for(i=2;i<9989899;i=i+2)
	{
		a[i]=1;	
	}
	for(i=3;i<=3161;i++)
	{
		if(a[i]!=1)
		{
			for(j=i*i;j<=9989899;j+=i)
			{
				a[j]=1;
			}
		}
	}
	k=2;
	p[0]=5;
	p[1]=7;
	printf("%d\n",a[9989899]);

	for(i=11;i<=9989899;i+=2)
	{
		printf("%d\n",a[9989899]);
		if(f(i)==1&&a[i]==0)
			p[k++]=i;
			  
	}
			
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0; i<k; i++)  
        {  
            if(p[i]<n)  
                continue;  
            else if(p[i]>m)  
                break;  
            else  
                printf("%d\n",p[i]);  
        }  
		printf("\n");
	}
	return 0;
}

