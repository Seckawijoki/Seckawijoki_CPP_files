/*
Description
ÿ�����Ӷ��г���ߣ�������Ҫ�ж�һ�������ܷ������һ�������С�
����������A�ĳߴ��� 3 x 4 x 5������B�ĳߴ� �� 5 x 6 x 4��
�����Ƚ��жϣ�����֪������A�ܹ���������B�У����Ǿ�˵����Aƥ������B��
ע�⣬���������ӳߴ���ȣ�����Ҳ��Ϊ����ƥ�䡣

Input
��һ���������T����ʾ��T������ʵ��
�ڶ��������1��ʵ��������A�ĳ������ߣ�������ֵΪС��1000����Ȼ��
�����������1��ʵ��������B�ĳ������ߣ�������ֵΪС��1000����Ȼ��
�Դ�����

Output
�����������ƥ�䣬���Yes���������No���������ÿһ�������ƥ������

Sample Input
3
3 4 5
5 6 4
5 6 4
3 4 5
5 6 7
7 4 7

Sample Output
Yes
Yes
No

HINT

ע���������Ĵ�Сд

*/
# include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,v1,v2,n;
	cin>>n;
	while ( n-- )
	{
		cin>>a>>b>>c>>d>>e>>f;
		v1 = a * b * c;
		v2 = d * e * f;
		if ( v1 > v2 )
		{
			a = a + d ; d = a - d ; a = a - d;
			b = b + e ; e = b - e ; b = b - e;
			c = c + f ; f = c - f ; c = c - f;
		}
		if ( a <= d && b <= e && c <= f )
			cout<<"Yes\n";
		else if ( a <= e && b <= f && c <= d )
			cout<<"Yes\n";
		else if ( a <= f && b <= d && c <= e )
			cout<<"Yes\n";
		else
			cout<<"No\n";		
	}
	return 0;
}

//-----------------�ɴ���

/*		a > b ?  a = a + b , b = a - b , a = a - b : 1 ;
		a > c ?  a = a + c , c = a - c , a = a - c : 1 ;
		b > c ?  b = c : 1 ;//��С����
		smin = a * b;
		
		d < e ?  d = d + e , e = d - e , d = d - e : 1 ;
		d < f ?  d = d + f , f = d - f , d = d - f : 1 ;
		e < f ?  e = f : 1 ;//�Ӵ�С
		smax = d * e;
*/

//		if ( (a * b <= d * e && v1 <= v2 ) || ( b * c >= e * f && v1 >= v2 ) 
	