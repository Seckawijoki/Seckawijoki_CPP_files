/*
1. ��������15��������������15�����ų�һȦ��
����ҳ����е�����4������ʹ�����ǵĺ����(��С��������������4�����ĺ�)��
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
		//�����Ĺؼ���
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
		"������ĸ������±�Ϊ"<<t1<<','<<t2<<','<<t3<<','<<t4<<endl;
}
