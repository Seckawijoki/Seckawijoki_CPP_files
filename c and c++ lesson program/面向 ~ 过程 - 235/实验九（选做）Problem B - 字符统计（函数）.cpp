/*
Description
��дһ��������ʵ�δ���һ���ַ�����
ͳ�ƴ��ַ�������ĸ�����֡��ո�������ַ��ĸ�����
���������������ַ����Լ������������� 
ֻҪ����������ʲô��ʾ��Ϣ��

Input
һ���ַ���

Output
ͳ�����ݣ�4�����֣��ո�ֿ���

Sample Input
!@#$%^QWERT    1234567
Sample Output
5 7 4 6 
*/
# include <iostream>
# include <cstring>
# include <cstdio>
using namespace std;
int letter = 0,number = 0,space = 0,others = 0;
int panduan( char a[33] )
{
	int n = strlen(a);
	for ( int i = 0 ; i < n ; i++ )
	{
		if ( a[i] == ' ' )
			space++;
		else if ( '0' <= a[i] && a[i] <= '9' )
			number++;
		else if ( ( 'a' <= a[i] && a[i] <= 'z' )||
				  ( 'A' <= a[i] && a[i] <= 'Z' ) )
			letter++;
		else
			others++;		
	}
	return 1;
}
int main()
{
	char a[33];
	gets(a);
	panduan(a);
	cout<<letter<<' '
		<<number<<' '
		<<space <<' '
		<<others<<" \n";
	return 0;
}