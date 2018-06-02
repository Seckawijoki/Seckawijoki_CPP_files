/*
Description
输入一行字符，分别统计出其中英文字母、空格、数字和其他字符的个数。
Input
一行字符
Output
统计值

Sample Input
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123

Sample Output
23 16 2 4
*/
# include <iostream.h>
# include <iomanip.h>
# include <cstdio>
int main()
{
	char c;
	int num = 0 , letter = 0 , point = 0 ,space = 0 , cr = 0;
	for (;;)
	{
		do 
		{
			scanf("%c",&c);
			if ( c >= '0' && c <= '9' )
				num++;
			else if ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) )
				letter++;
			else if ( c == ' ' )
				space++;
			else 
				point++;
			if ( c == '\n' )//靠这个来跳出循环。
				break;
		}while ( 1 );
		cout<<"统计结果：\n"
			<<"数字："<<num<<endl
			<<"字母："<<letter<<endl
			<<"空格："<<space<<endl
			<<"其它："<<point<<endl<<endl;
	}
	return 0;
}

