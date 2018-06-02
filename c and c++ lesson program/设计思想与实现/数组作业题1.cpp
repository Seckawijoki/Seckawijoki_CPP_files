/*
1. 任意输入15个正整数，将这15个数排成一圈，
编程找出其中的连续4个数，使得它们的和最大(不小于任意其他连续4个数的和)。
*/
#include <iostream.h>
void main()
{
	const int n=15;
	int i,a[n];
	cout<<"Input"<<n<<"positive integers:"<<endl;
	for(i=0;i<n;i++)
		cin>>a[i];
	int max4=0,s4,start,t1,t2,t3,t4;
	for(i=0;i<n;i++)
	{
		//连续的关键。
		t1=i%n;
		t2=(i+1)%n;
		t3=(i+2)%n;
		t4=(i+3)%n;
		s4=a[t1]+a[t2]+a[t3]+a[t4];
		if(s4>max4)
		{
			max4=s4;
			start=i;
		}
	}
	t1=start;
	t2=(start+1)%n;
	t3=(start+2)%n;
	t4=(start+3)%n;
	cout<<"max4="<<a[t1]<<"+"<<a[t2]<<"+"<<a[t3]<<"+"<<a[t4]<<
		"最大，这四个数的下标为"<<t1<<','<<t2<<','<<t3<<','<<t4<<endl;
}
