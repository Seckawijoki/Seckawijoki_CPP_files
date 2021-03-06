/*
题目描述
定义并实现三个函数：

第一个函数是整数函数，返回类型为整数，
参数是一个整数变量，操作是求该变量的平方值

第二个函数是浮点数函数，返回类型为浮点数，
参数是一个浮点数变量，操作是求该变量的平方根值。
求平方根可以使用函数sqrt（浮点参数），
将返回该参数的平方根，在VC中需要头文件cmath。

第三个函数是字符串函数，无返回值，参数是一个字符串指针，
操作是把这个字符串内所有小写字母变成大写。

要求：定义三个函数指针分别指向这三个函数，
然后根据调用类型使用函数指针来调用这三个函数。
不能直接调用这三个函数。

如果类型为I，则通过指针调用整数函数；
如果类型为F，则通过指针调用浮点数函数；
如果类型为S，则通过指针调用字符串函数

输入
第一行输入一个t表示有t个测试实例
每行先输入一个大写字母，表示调用类型，然后再输入相应的参数
依次输入t行

输出
每行输出调用函数后的结果

样例输入
5
S shenzhen
I 25
F 6.25
I 31
S China

样例输出
SHENZHEN
625
2.5
961
CHINA
*/
# include <iostream.h>
# include <math.h>
# include <string.h>
char *fS( char *str )
{
	int i,length = strlen(str);
	for ( i = 0 ; i < length ; i ++ )
		if ( *(str+i) >= 'a' && *(str+i) <= 'z' )
			*(str+i) = *(str+i) - 32;
	return str;
}
int fI( int x )
{
	return x * x;
}
float fF( float f )
{
	return sqrt(f);
}
int main()
{
	int t,x;
	char ch,s[99];
	float f;

	int (*pi)( int  );
	char *(*ps)( char * );
	float (*pf)( float );

	pi = fI;
	ps = fS;
	pf = fF;

	cin>>t;
	while ( t-- )
	{
		cin>>ch;
		/**/ if ( ch == 'S' )
		{
			cin>>s;
			ps(s);
			cout<<s<<endl;
		}
		else if ( ch == 'I' )
		{
			cin>>x;
			cout<<pi(x)<<endl;
		}
		else if ( ch == 'F' )
		{
			cin>>f;
			cout<<pf(f)<<endl;
		}
	}
	return 0;
}