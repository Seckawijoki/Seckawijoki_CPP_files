/*
Description
用户输入一个小写字母，输出该字母的前驱字符与后继字符，如字符c的前驱字符是b，后继字符是d；字符z的前驱字符是y，后继字符是a。

Input
输入一个小写字母

Output
输出该字母的前驱字母
输出该字母的后继字母


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
		cout<<char( 'z' - ( 'z' -  c  + 1 ) %26 )<<endl;//	对a前面的z有效。
		cout<<char( 'a' + (  c  - 'a' + 1 ) %26 )<<endl;//	对z后面的a有效。
	}
	return 0;
}