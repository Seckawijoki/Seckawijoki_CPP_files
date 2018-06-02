/*
题目描述
如下所示为类对象构造和析构过程中产生的输出,试完成类的定义和主函数的编写.
输入
测试数据的组数t
第一组对象个数n1
第二组对象个数n2
.......

输出
Constructing object 1
Constructing object 2
......
Constructing object n1
Destructing object n1
......
Destructing object 2
Destructing object 1
Constructing object 1
Constructing object 2
......
Constructing object n2
Destructing object n2
......
Destructing object 2
Destructing object 1
......
样例输入
2
3
4
样例输出
Constructing object 1
Constructing object 2
Constructing object 3
Destructing object 3
Destructing object 2
Destructing object 1
Constructing object 1
Constructing object 2
Constructing object 3
Constructing object 4
Destructing object 4
Destructing object 3
Destructing object 2
Destructing object 1
提示
定义一个整型全局变量对构造和析构的对象进行计数
*/
# include <stdio.h>
class Objection
{
private:
	int number;
public:
	Objection()
	{
		number = 0;
	}
	void DisplayConstructing( int n )
	{
		number = n;
		printf("Constructing object %d\n",n);
	}
	~Objection()
	{
		printf("Destructing object %d\n",number);
		number--;
	}
};
int main()
{
	int i,t,n;
	Objection *target;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d",&n);
		target = new Objection [n];
		for ( i = 0 ; i < n ; i ++ )
			target[i].DisplayConstructing(i+1);
		delete [] target;
	}
	return 0;
}