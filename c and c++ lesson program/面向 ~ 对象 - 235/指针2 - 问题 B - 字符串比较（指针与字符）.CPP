/*
题目描述

编写一个函数比较两个字符串，参数是两个字符指针
（要求显式定义，例如char *S, char *T)，
比较字符串S和T的大小。
如果S大于T，则返回1，
如果S小于T则返回-1，
如果S与T相等则返回0。

比较规则：
1.把两个字符串的相同位置上的字符进行比较，
字符的大小比较以ASCII值为准

2.在比较中，
如果字符串S的字符大于字符串T的字符的数量
超过小于的数量，则认为S大于T，
如果等于则S等于T，
如果小于则S小于T

例如S为aaccdd，T为eebbbb，
每个位置比较得到S前两个字母都小于T，
但后4个字母都大于T，最终认为S大于T

3.如果两个字符串长度不同，则更长的字符串为大

在主函数中输入两个字符串，并调用该函数进行判断，
在判断函数中必须使用函数参数的指针进行字符比较

输入
输入t表示有t个测试实例
接着每两行输入两个字符串
依次输入t个实例

输出
每行输出一个实例的比较结果

样例输入
3
aaccdd
eebbbb
AAbb++
aaEE*-
zznnkk
aaaaaaa

样例输出
1
0
-1
*/
# include <stdio.h>
# include <string.h>
int contrast( char *str1 , char *str2 )
{
	int long1 = strlen(str1),
		long2 = strlen(str2);
	     if ( long1 > long2 )
		return 1;
	else if ( long1 < long2 )
		return -1;
	else if ( long1 == long2 )
	{
		int i,cmp1 = 0,
			  cmp2 = 0;
		for ( i = 0 ; i < long1 ; i++ )
		{
			     if ( *(str1+i) > *(str2+i) )
				cmp1++;
			else if ( *(str1+i) < *(str2+i) )
				cmp2++;
			else if ( *(str1+i) == *(str2+i) )
				continue;
		}
			 if ( cmp1  > cmp2 )
			return 1;
		else if ( cmp1  < cmp2 )
			return -1;
		else if ( cmp1 == cmp2 )
			return 0;
	}
}
int main()
{
	int t;
	char *str1 , *str2,
		ch1[99],ch2[99];
	str1 = ch1;
	str2 = ch2;
	scanf("%d",&t);
	getchar();
	while ( t-- )
	{
		scanf("%s%s",str1,str2);
		printf("%d\n",contrast(str1,str2));
	}
	return 0;
}
