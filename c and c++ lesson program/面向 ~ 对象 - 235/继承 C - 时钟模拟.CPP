/*
题目描述
定义计数器类，包含保护数据成员value，公有函数increment计数加1。

定义循环计算器继承计数器类，
增加私有数据成员：最小值min_value，max_value，

重写公有函数increment，
使得value在min_value~max_value区间内循环+1。

定义时钟类，数据成员是私有循环计数器对象
小时hour、分钟minute、秒second，
公有函数time(int s)计算当前时间经过s秒之后的时间，
即hour，minute，second的新value值。

定义时钟类对象，输入当前时间和经过的秒数，
调用time函数计算新时间。

根据题目要求，增加必要的构造函数、析构函数和其他所需函数。

输入
第一行测试次数n

2行一组，第一行为当前时间（小时 分钟 秒），
第二行为经过的秒数。

输出

输出n行
每行对应每组当前时间和经过秒数后计算得到的新时间
（小时：分钟：秒）。

样例输入
2
8 19 20
20
23 30 0
1801

样例输出
8:19:40
0:0:1
*/
# include <iostream>
# include <cmath>
using namespace std;
class Counter
{
protected:
	int value;
public:
	Counter(){ value = 0; }
	Counter( int x ){ value = x; }
	int GetValue(){ return value; }
	void Increment(){ value++; }
	~Counter(){}
};
class LoopCounter:public Counter
{
private:
	int minimum , maximum;
public:
	LoopCounter()
	{
		minimum = 0;
		maximum = 0;
	}
	LoopCounter( int x , int min , int max ):Counter(x)
	{
		minimum = min;
		maximum = max;
	}
	void Increment()
	{
		value = minimum + (value+1) %maximum;
	}
	~LoopCounter(){}
};
class Clock
{
private:
	LoopCounter hour , minute , second;
public:
	Clock():hour(0,0,23),minute(0,0,59),second(0,0,59){}
	Clock( int ji , int bun , int byou ):hour(ji,0,24),minute(bun,0,60),second(byou,0,60){}
	void Time( int jikan )
	{
		int i,time,m,s;
		m = minute.GetValue();
		s = second.GetValue();
		time = jikan %1440;
		for ( i = 0 ; i < time ; i++ )
			second.Increment();
		time = ( jikan - time ) /60   + ( s + time ) /60;
		for ( i = 0 ; i < time ; i++ )
			minute.Increment();
		time = ( jikan - time ) /3600 + ( m + time ) /60;
		for ( i = 0 ; i < time ; i++ )
			hour.Increment();
	}
	void Display()
	{
		cout<<hour.GetValue()<<':'
			<<minute.GetValue()<<':'
			<<second.GetValue()<<'\n';
	}
	~Clock(){}
};
int main()
{
	int t,ji,bun,byou,jikan;
	cin>>t;
	while ( t-- )
	{
		cin>>ji>>bun>>byou>>jikan;
		Clock tokei(ji,bun,byou);
		tokei.Time(jikan);
		tokei.Display();
	}
	return 0;
}