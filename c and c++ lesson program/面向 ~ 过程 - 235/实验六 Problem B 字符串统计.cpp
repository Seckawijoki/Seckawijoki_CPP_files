/*
Description
����һ���ַ���ͳ�����д�дӢ����ĸ��СдӢ����ĸ�������ַ��ĸ����������

Input
һ���ַ�

Output
��дӢ����ĸ��СдӢ����ĸ�������ַ��ĸ���

Sample Input
AbcEFg123()*^fHY
Sample Output
5
4
3

*/
# include <iostream>
using namespace std;
int main()
{
	char c;
	int num = 0 , bl = 0 , sl = 0 , space = 0;
	do 
	{
		cin>>c;
		if ( c >= '0' && c <= '9' )
			num++;
		else if ( c >= 'a' && c <= 'z' ) 
			sl++;
		else if	( c >= 'A' && c <= 'Z' )
			bl++;
		if ( c == '#' )
			break;
	}while ( 1 );
	cout<<bl<<endl<<sl<<endl<<num<<endl;	
	return 0;
}

