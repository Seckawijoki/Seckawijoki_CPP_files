/*
Description
ƽ��������A(1,3)��B(5,1)�������C�����꣬���㲢��������Φ�ABC����������������λС������

Input
�����c�� x ����

�����c�� y ����

Output
��������ε����

Sample Input
4
4

Sample Output
Area=5.00

HINT
*/
# include <iostream>
# include <iomanip>
# include <cmath>
//�� �� # include <math.h>
using namespace std;
int main()
{
	float x,y,a,b,c,p,s;
	cin>>x>>y;
	a = sqrt( 20 );
	b = sqrt( ( 1 - x ) * ( 1 - x ) + ( 3 - y ) * ( 3 - y ) );
	c = sqrt( ( 5 - x ) * ( 5 - x ) + ( 1 - y ) * ( 1 - y ) );
	p = ( a + b + c ) / 2;
	s = sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
	cout<<"Area="<<fixed<<setprecision(2)<<s<<endl;
						//ָ��ΪС��λ����
		     //��<<setiosflags(ios::showpoint)<<setprecision(3)<<s<<endl;
												//ָ��Ϊ��Чλ����
	return 0;
}
/*
  ���С��λ�����ɡ�
  <<fixed<<setprecision(2)//ָ��ΪС��λ����
  <<setiosflags(ios::fixed)<<setprecision(2)//ָ��ΪС��λ����
  <<setiosflags(ios::showpoint)<<setprecision(3)//ָ��Ϊ��Чλ����
*/