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

  a = a + b
  b = a - b
  a = a - b
*/
# include <iostream>
using namespace std;

int main()
{
	int a,b,c,d;
	cout<<"�������ĸ�������";
	cin>>a>>b>>c>>d;
	a > b ? a = a + b , b = a - b , a = a - b : 1 ;
	a > c ? a = a + c , c = a - c , a = a - c : 1 ;
	a > d ? a = a + d , d = a - d , a = a - d : 1 ;

	b > c ? b = b + c , c = b - c , b = b - c : 1 ;
	b > d ? b = b + d , d = b - d , b = b - d : 1 ;

	c > d ? c = c + d , d = c - d , c = c - d : 1 ;

	cout<<"\n���ĸ�������С���������Ϊ��"<<a<<" "<<b<<" "<<c<<" "<<d<<endl;

	return 0;
}