# include <iostream>
using namespace std;
int InterestingDigit( int number[1001], int digit )
{
	int i, j;
	bool attendance[4] = {false,false,false,false};
	for ( j = 3 ; j >= 0 ; --j )
	{
		for ( i = 1 ; i <= digit ; ++i )if ( number[i] == j )
		{
			attendance[j] = true;
			break;
		}
		if ( attendance[j] == false )break;
	}
	if ( attendance[3] && attendance[1] && attendance[2] && attendance[0] )
	{
	//	for ( i = digit ; i >= 1 ; --i )cout<<number[i];cout<<"   ";
		bool frontalzero, frontaltwo;
		for ( i = 1 ; i <= digit ; ++i )
		{
			frontalzero = true;
			frontaltwo = true;
			if ( number[i] == 0 )
			{
				for ( j = i + 1 ; j <= digit ; ++j )if ( number[j] == 1 )
				{
					frontalzero = false;
					break;
				}
			}
			else if ( number[i] == 1 )
			{
				for ( j = 1 ; j < i ; ++j )if ( number[j] == 0 )
				{
					frontalzero = false;
					break;
				}
			}
			else if ( number[i] == 2 )
			{
				for ( j = i + 1 ; j <= digit ; ++j )if ( number[j] == 3 )
				{
					frontaltwo = false;
					break;
				}
			}
			else if ( number[i] == 3 )
			{
				for ( j = 1 ; j < i ; ++j )if ( number[j] == 2 )
				{
					frontaltwo = false;
					break;
				}
			}
			else
			{
				frontalzero = false;
				frontaltwo = false;
				break;
			}
			if ( !frontalzero )break;
			if ( !frontaltwo  )break;
		}
		if ( frontalzero && frontaltwo )return 1;
		else return 0;
	}
	else
		return 0;
}
int main()
{
	int  i, n, result;
	long long sum = 0;
	int number[1001] = {0};
	cin>>n;
	number[n] = 1;
	while ( number[n+1] == 0 )
	{
		result = InterestingDigit(number,n);
		sum += result;
	//	if ( result )cout<<sum<<endl;
		++number[1];
		for ( i = 1 ; i <= n ; ++i )if ( number[i] >= 4 )
		{
			number[i] -= 4;
			++number[i+1];
		}
	}
	cout<<sum %1000000007<<endl;
	return 0;
}
/*
�����ţ�	4
�������ƣ�	��Ȥ����
ʱ�����ƣ�	1.0s
�ڴ����ƣ�	256.0MB
����������	
��������
���ǰ�һ������Ϊ��Ȥ�ģ����ҽ�����
1. ��������ֻ����0, 1, 2, 3�������ĸ����ֶ����ֹ�����һ�Ρ�
2. ���е�0�����������е�1֮ǰ�������е�2�����������е�3֮ǰ��
3. ���λ���ֲ�Ϊ0��
��ˣ��������Ƕ������С����Ȥ������2013���������⣬4λ����Ȥ��������������2031��2301��
�����ǡ����nλ����Ȥ�����ĸ��������ڴ𰸿��ܷǳ���ֻ��Ҫ����𰸳���1000000007��������

�����ʽ
����ֻ��һ�У�����ǡ��һ��������n (4 �� n �� 1000)��

�����ʽ
���ֻ��һ�У�����ǡ��n λ����������Ȥ�����ĸ�������1000000007��������

��������
4

�������
3
*/
