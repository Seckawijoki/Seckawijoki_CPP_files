//��Ǯ��ټ�-2 �Ż��㷨
//����һֵǮ�壬��ĸһֵǮ����������ֵǮһ������Ǯ��ټ����ʼ��̣�ĸ�����������Σ�

#include <iostream.h>

int main()
{
	int n=100,k;
	cout<<"cock     hen      chicken\n";
	for (int i=0; i<=20; i++)
	  for (int j=0; j<=33; j++)
	  { 
		k=100-i-j;
		if ((n==5*i+3*j+k/3)&&(k%3==0))
		   // printf("%d cocks, %d hens, %d chickens\n",i,j,k);
		    cout<<i<<" cocks "<<j<<" hens "<<k<<" chickens"<<endl; 
	  }
	return 0;
}