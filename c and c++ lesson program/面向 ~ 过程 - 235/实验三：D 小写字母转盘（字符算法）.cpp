/*
Description
�û�����һ��Сд��ĸ���������ĸ��ǰ���ַ������ַ������ַ�c��ǰ���ַ���b������ַ���d���ַ�z��ǰ���ַ���y������ַ���a��

Input
����һ��Сд��ĸ

Output
�������ĸ��ǰ����ĸ
�������ĸ�ĺ����ĸ


Sample Input
g


Sample Output
f
h
*/
# include <iostream>
using namespace std;

int main()
{
	char c;
	while ( 1 )
	{
		cin>>c;
		cout<<char( 'z' - ( 'z' -  c  + 1 ) %26 )<<endl;//	��aǰ���z��Ч��
		cout<<char( 'a' + (  c  - 'a' + 1 ) %26 )<<endl;//	��z�����a��Ч��
	}
	return 0;
}