/*
题目描述
某个类包含一个整型数据成员。
程序运行时若输入0表示用缺省方式定义一个类对象；
输入1及一个整数表示用带一个参数的构造函数构造一个类对象；
输入2及一个整数表示构造2个类对象，
一个用输入的整数构造，另一个用前一个对象构造。
试完成该类的定义和实现。
输入
测试数据的组数 t
第一组数
第二组数
......
输出
第一个对象构造输出
第二个对象构造输出
......
样例输入
3
0
1 10
2 20
样例输出
Constructed by default, value = 0
Constructed using one argument constructor, value = 10
Constructed using one argument constructor, value = 20
Constructed using copy constructor, value = 20
*/
# include <stdio.h>
class Objection
{
private:
	int value;
public:
	Objection()
	{
		value = 0;
		printf("Constructed by default, value = %d\n",value);
	}
	Objection( int x )
	{
		value = x;
		printf("Constructed using one argument constructor, value = %d\n",value);
	}
	Objection( Objection &target )
	{
		value = target.value;
		printf("Constructed using copy constructor, value = %d\n",value);
	}
};
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d",&n);
		if ( n == 0 )
			Objection target0;
		else if ( n == 1 )
		{
			scanf("%d",&x);
			Objection target1(x);
		}
		else if ( n == 2 )
		{
			scanf("%d",&x);
			Objection target2(x);
			Objection target3 = target2;
		}
	}
	return 0;
}