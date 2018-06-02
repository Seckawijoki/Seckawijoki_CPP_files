/*
Description
输入一串字符，统计其中大写英文字母、小写英文字母、数字字符的个数，并输出

Input
一串字符

Output
大写英文字母、小写英文字母、数字字符的个数

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

