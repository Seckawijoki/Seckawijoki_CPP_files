/*
【练习2】
字符串字母大小写转换
输入一个长度不超过40字符串，
要求将小写字母全部转换成大写字母，把大写字母全部转换成小写字母，其它字符不变。

输入格式：
输入在一行中给出一个长度不超过40的非空字符串。 
输出格式： 
在一行中按照要求输出转换后的字符串。 

输入样例：
Hello World! 123
输出样例：
hELLO wORLD! 123

*/
# include <stdio.h>

int main(void)
{
	int i = 0;
	char ch;//未发现数组的作用。
	while ( 1 )
	{
		scanf("%c",&ch);
	   	if ( ch >= 65 && ch <=  90 )
			ch += 32;
		else if ( ch >= 97 && ch <= 122 )
			ch -= 32;
		printf("%c",ch);
	}
	return 0;
}