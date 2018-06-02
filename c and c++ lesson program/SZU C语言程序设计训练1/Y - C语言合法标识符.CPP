/*
Description
输入一个字符串，判断其是否是C的合法标识符。

Input
输入数据包含多个测试实例，
数据的第一行是一个整数n,表示测试实例的个数，
然后是n行输入数据，每行是一个长度不超过50的字符串。

Output
对于每组输入数据，输出一行。
如果输入数据是C的合法标识符，则输出"yes"，否则，输出“no”。

Sample Input
3 
12ajf 
fi8x_a 
ff ai_2

Sample Output
no 
yes 
no 
*/
# include <stdio.h>
int main()
{
	int i,j,k,n,tage;
	char c[50][50];
	while ( scanf("%d%*c",&n) != EOF )
	{
		for ( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; ; j++ )//需要解决过滤回车问题
			{
				scanf("%c",&c[i][j]);
				if ( c[i][0] == '\n' )
					break;
				if ( c[i][j] == '\n' )
					break;
			}
		}
		for ( i = 0 ; i < n ; i++ )
		{
			tage = 0;
			for ( k = 0 ; k < j ; k++ )
			{	
				if ( c[i][1] == '\n'  )
					break;
				if ( ( c[i][0] >= '0' && c[i][0] <= '9' ) || c[i][0] == '_'  )
				{
					tage++;
					printf("no\n");//[数字开头],[下划线开头]
					break;
				}
				if (( c[i][k] >= '0' && c[i][k] <= '9' )||( c[i][k] >= 'A' && c[i][k] <= 'Z' )||
					( c[i][k] >= 'a' && c[i][k] <= 'z' )||( c[i][k] == '_' )||( c[i][k] == '\n' ) );
				else
				{
					tage++;
					printf("no\n");//[非法字符]
					break;
				}
			}
			tage ? 1 : printf("yes\n") ;//[自然]
		}
	}
	return 0;
}

