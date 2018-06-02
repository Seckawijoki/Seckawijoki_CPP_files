//Çó½×³ËºÍ
#include<iostream.h>
long F(int n)
{
	long f;
	
    if (n==0) f=1;
    	else f=F(n-1)*n;
	return(f);
}

long TotalF(int n)
{
	long f;
    if (n==0) f=1;
	else f=TotalF(n-1)+F(n);
    return(f);
}

int main()
{
	int n,y;
	cout<<"Input a positive integer:";
	cin>>n;
	while (n<0) 
	{
		cout<<"n<0 is error!"<<endl;
		cin>>n;
	}

	for(int i=0;i<=n;i++)
	{
		y=F(i);
		cout<<i<<"!="<<y<<endl;
	}
	y=TotalF(n);
	cout<<"The sum="<<y<<endl;
	return 0;
}