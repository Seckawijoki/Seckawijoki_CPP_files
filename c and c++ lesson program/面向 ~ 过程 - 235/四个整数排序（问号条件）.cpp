/*
��Ŀ����
����4��������Ҫ�󰴴�С�����˳�����

����
����4�����������

���
����������4������

��������
90 -2 6 45
�������
-2 6 45 90
*/
# include <iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	a > b ? a = a + b , b = a - b , a = a - b : a = a ;
	a > c ? a = a + c , c = a - c , a = a - c : a = a ;
	a > d ? a = a + d , d = a - d , a = a - d : a = a ;

	b > c ? b = b + c , c = b - c , b = b - c : b = b ;
	b > d ? b = b + d , d = b - d , b = b - d : b = b ;

	c > d ? c = c + d , d = c - d , c = c - d : c = c ;

	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

	return 0;
}