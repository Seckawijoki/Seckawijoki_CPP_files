#include<iostream>
using namespace std;

void cows( int n )
{
	int one , two , three , four ;
	one = 1;
	two = three = four = 0;

     for ( int i = 1 ; i <= n ; i++ )
	 {
             four = three + four;//	不死之躯。
             three = two;//	进化。
             two = one;//	进化。
             one = four;//	多少母牛即多少小牛。
     }
             cout<<"~~~~~~~~~~~~~~~~~~生成报告~~~~~~~~~~~~~~~~~~~~~~\n";
             cout<<"          "<<n<<"年以后共产生牛牛："<<(one+two+three+four)<<"只\n";
             cout<<"          其中有一岁的小牛："<<one<<"只\n";
             cout<<"          其中有两岁的小牛："<<two<<"只\n";
             cout<<"          其中有三岁的小牛："<<three<<"只\n";
             cout<<"          其中有牛牛究极体："<<four<<"只\n";
             cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

int main()
{
	cout<<"          牛生牛产业链计划正式启动\n";
	cout<<"我们美丽的草原上有一只小母牛（一岁），它自愿的加入了牛牛产业计划。^_^让我们给它一些热烈的掌声，为它加油！\n";
	cout<<"你想知道n年以后草原上的牛牛盛况吗？请输入n的值吧：";
	while( 1 )
	{
		int n;
		cin>>n;
		if( n > 57 )
		{
			cout<<"(由于计算机整数上限问题，以及个人水平问题，该程序不能输出过大的n值)敬请原谅^_^\n";
			continue;
		} 
		if( n < 0 )
		{
			cout<<"请输入合理的n的值\n";
			continue;
		}
		cows( n );
		cout<<"好一个美丽的大草原啊~~~~~~~~\n\n";
	}
	return 0;
}