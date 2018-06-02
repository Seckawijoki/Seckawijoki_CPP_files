/*
题目描述
定义一个字符串类str，该类中包含2个属性，
字符串长度和一个char型指针保存字符串内容。
增加以下运算符的重载：+、- 。
+运算符表示把2个字符串拼接成一个字符串。
-运算符表示例如a2-a1，则删除a2中出现的a1字符串。

要求如下：
1.实现str类；
2.编写main函数，初始化2个str对象A、B，
输出这2个对象相加后的对象C的结果信息。
输出C与B之间相减后的结果信息。
(提示:strstr(char *a,char*b)可以从a字符串中查找出b首次出现的地址)

输入
第1行：输入一个字符串，初始化第一个str对象。
(提示:通过cin. getline(char *,int strCount)可以输入一个字符串到char数组中)
第2行：输入一个字符串，初始化第二个str对象。

输出
第1行：输出两个字符串相加后的长度和字符串。
第2行：输出两个字符串相减后的长度和字符串。

样例输入
i am a 
student!
样例输出
length=15 i am a student!
length=7 i am a 
*/
# include <stdio.h>
# include <string.h>
class STR
{
private:
	int length;
	char *p;
public:
	STR()
	{
		length = 0;
		p = NULL;
	}
	STR( char *ch )
	{
		length = strlen(ch);
		p = new char [strlen(ch) + 1];
		strcpy(p,ch);
	}
	STR( const STR &obj )
	{
		length = strlen(obj.p);
		p = new char [length + 1];
		strcpy(p,obj.p);
	}
	~STR()
	{
		length = 0;
		delete [] p;
	}
	friend STR operator + ( const STR &s1 , const STR &s2 );
	friend STR operator - ( const STR &s1 , const STR &s2 );
	STR operator = ( const STR &obj )
	{
		length = strlen(obj.p);
		p = new char [length + 1];
		strcpy(p,obj.p);
		return *this;
	}
	void Display()
	{
		printf("length=%d %s\n",length,p);
	}
};
STR operator + ( const STR &s1 , const STR &s2 )
{
	char *ps;
	ps = new char [s1.length + s2.length + 1];
	strcpy(ps,s1.p);
	strcat(ps,s2.p);
	STR s0(ps);
	return s0;
}
STR operator - ( const STR &s1 , const STR &s2 )
{
	STR s0;
	int i,j;
	char *site;
	site = strstr(s1.p,s2.p);
	s0.length = s1.length;
	s0.p = new char [s0.length + 1];
	strcpy(s0.p,s1.p);
	for ( i = site - s1.p , j = i + s2.length ; j < s0.length ; j++ )
		s0.p[i] = s0.p[j];
	s0.p[i] = '\0';
	return s0;
}
int main()
{
	char ch1[88],ch2[88];
	gets(ch1);
	gets(ch2);
	STR s0,s1(ch1),s2(ch2);
	s0 = s1 + s2;
	s0.Display();
	s0 = s0 - s2;
	s0.Display();
	return 0;
}