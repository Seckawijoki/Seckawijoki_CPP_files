/*
Description
�Ӽ��������������������жϸ����Ƿ��ǻ�������
��ν���������Ǵ����Ҷ����������ҵ�����������һ���ġ�����12321��1221���ǻ�������

Input
���԰����ĸ���n
��һ������ֵ
�ڶ�������ֵ
.......
��n������ֵ

Output
��������ֵ�Ƿ��ǻ��������ǣ������Yes�����ǣ������No

Sample Input
3
4554
123
121

Sample Output
Yes
No
Yes
*/
#include<iostream>
using namespace std;
int main()
{
	int i,n,a,m,sum; 
	cin>>n;
	for ( i = 1 ; i <= n ; i++ )
	{
		sum = 0;
		cin>>a;
//		cout<<"a = "<<a<<endl;continue;
		m = a;
		while ( m )
		{
			sum = sum*10 + m%10;
			m /= 10;
		}
		if( sum == a )
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}


