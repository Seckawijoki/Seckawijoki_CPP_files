/*
题目描述
定义一个字符串类str，用来存放不定长的字符串，
重载运算符"=="、"<"、">",用于两个字符窜的等于、小于和大于的比较运算。

要求如下：
1.实现str类；
2.编写main函数，初始化三个str对象A、B、C，然后用这三个对象去测试重载的运算符。
如果A  > B，则输出A的字符串；否则输出B的字符串。
如果A  < C，则输出A的字符串；否则输出C的字符串。
如果B == C，则输出B的字符串；否则输出C的字符串。

输入
输入3行，每行为一个字符串，初始化三个str对象。

输出
输出比较之后的结果字符串，每个比较的结果一行。

样例输入
i am a student
i love China
i love China

样例输出
i love China
i am a student
i love China
*/
# include <stdio.h>
# include <string.h>
class ZiFuChuan;
int operator  > ( ZiFuChuan & , ZiFuChuan & );
int operator  < ( ZiFuChuan & , ZiFuChuan & );
int operator == ( ZiFuChuan & , ZiFuChuan & );
class ZiFuChuan
{
private:
	char *str;
public:
	ZiFuChuan()
	{
		str = NULL;
	}
	ZiFuChuan( char *s )
	{
		str = new char [strlen(s)+1];
		strcpy(str,s);
	}
	void SetString ( char *s )
	{
		str = new char [strlen(s)+1];
		strcpy(str,s);
	}
	void Display()
	{
		printf("%s\n",str);
	}
	friend int operator  > ( ZiFuChuan & , ZiFuChuan & );
	friend int operator  < ( ZiFuChuan & , ZiFuChuan & );
	friend int operator == ( ZiFuChuan & , ZiFuChuan & );
};
int operator  < ( ZiFuChuan &s1 , ZiFuChuan &s2 )
{
	int sum1 = 0, sum2 = 0, i;
	for ( i = 0 ; i < strlen(s1.str) ; i++ )
		sum1 += s1.str[i];
	for ( i = 0 ; i < strlen(s2.str) ; i++ )
		sum2 += s2.str[i];
	if ( sum1  > sum2 )
		return 1;
	else
		return 0;
}
int operator  > ( ZiFuChuan &s1 , ZiFuChuan &s2 )
{
	int sum1 = 0, sum2 = 0, i;
	for ( i = 0 ; i < strlen(s1.str) ; i++ )
		sum1 += s1.str[i];
	for ( i = 0 ; i < strlen(s2.str) ; i++ )
		sum2 += s2.str[i];
	if ( sum1  < sum2 )
		return 1;
	else
		return 0;
}
int operator == ( ZiFuChuan &s1 , ZiFuChuan &s2 )
{
	int sum1 = 0, sum2 = 0, i;
	for ( i = 0 ; i < strlen(s1.str) ; i++ )
		sum1 += s1.str[i];
	for ( i = 0 ; i < strlen(s2.str) ; i++ )
		sum2 += s2.str[i];
	if ( sum1 == sum2 )
		return 1;
	else
		return 0;
}
int main()
{
	char s1[55],s2[55],s3[55];
	gets(s1);
	gets(s2);
	gets(s3);
	ZiFuChuan str1(s1),str2(s2),str3(s3);

	if ( str1  > str2 )
		str1.Display();
	else
		str2.Display();

	if ( str1  < str3 )
		str1.Display();
	else
		str3.Display();

	if ( str2 == str3 )
		str2.Display();
	else
		str3.Display();
	
	return 0;
}
