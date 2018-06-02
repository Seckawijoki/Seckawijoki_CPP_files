/*
题目描述
把一个字符串中包含的空格全部删除掉

输入
第一行输入T表示有T个测试实例
第二行起，每行输入一串字符（至少包含一个非空格字符），输入T行

输出
输出删除空格后的字符串

样例输入
4
Shen Zhen
  China  Go
          A
AB    CD  EF

样例输出
ShenZhen
ChinaGo
A
ABCDEF
*/
# include <stdio.h>
# include <string.h>
int space_delete( char str[] )
{
	int i,j = 0 ,l = strlen(str);
	char ch[55];
	for ( i = 0 ; i <= l ; i ++ )
		if ( str[i] != ' ' )
			ch[j++] = str[i];
	ch[j] = '\0';
	printf("%s\n",ch);
	return 1;
}
int main()
{
	int t;
	char str[55];
	scanf("%d",&t);	
	getchar();		//于此。不于下。
	while ( t-- )
	{
		gets(str);
		space_delete(str);
	}
	return 0;
}