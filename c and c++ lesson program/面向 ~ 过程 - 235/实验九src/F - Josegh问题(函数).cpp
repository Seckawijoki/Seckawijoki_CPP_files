#include<stdio.h>
#include<iostream>
using namespace std;

void Josegh(int m, int n)
{
	int a[100], i, j;
	
	//��С�����         
	for (i = 0; i < m; i++)     
		a[i] = i+1;             
	int k = 1; //��ʶ�����k���뿪��С��         
	i = -1; //�����±�(��һ��ֵ0���ǵ�һ��С�����±�)         
	//�����ʤǰ��С��         
	for(;;)
	{
		for (j = 0; j < n;)
		{
			i=(i+1)%m; //���±��1��ģ
			if(a[i]!=0) //�����Ԫ�ص�С����Ȧ�У������������Ч              
				j++;
		}
		if(k==m)
			break; //��С�������һ��(ʤ����)��         
		cout << a[i] << ' '; //����뿪��С��֮���          
		a[i]=0; //��ʶ��С�����뿪     
		k++; //׼��������һ��Ȧ��С��
	}
	cout << a[i] << endl; //���ʤ����
}

int main()
{
	int t, m, n;

	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		Josegh(m, n);
	}

	return 0;
}