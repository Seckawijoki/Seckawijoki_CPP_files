/*
Description
��̼���a+aa+aaa+��+aa..a(n��a)��ֵ��
a��ȡֵ��ΧΪ0��9��n��ȡֵ��ΧΪ0��5��
n��a��ֵ���ɼ������룬��Ϊ������

Input
��������a��n

Output
���

Sample Input
2
4
Sample Output
2468

*/
# include <iostream>
using namespace std;
int main()
{
	int a,n,i,s = 0,t = 0;
	cin>>a>>n;
	for ( i = 1 ; i <= n ; i++ )
	{
		t += a;
		s += t;
		t *= 10;
	}
	cout<<s<<endl;
	return 0;
}