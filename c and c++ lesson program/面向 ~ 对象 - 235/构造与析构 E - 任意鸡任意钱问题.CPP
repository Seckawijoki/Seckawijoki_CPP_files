/*
题目描述
百鸡百钱问题描述为：用100元钱买100只鸡，
已知每只公鸡5元，每只母鸡3元，3只小鸡1元，
问能买多少只公鸡、母鸡和小鸡？
试将该类问题用一个类来表示，
百鸡百钱问题只是这个类如CChickProblem的一个实例，
假设各种鸡的价格不变，类中数据成员有总钱数、要买的总的鸡数、
能买到的母鸡、小鸡和公鸡的数量。
成员函数有构造和析构函数，求问题解的函数findSolution，
打印问题解的函数printSolution。
(要求用动态数组保存问题的所有解)
编写程序求解该类问题。

输入
测试数据的组数 t
第一组 鸡数 钱数
第二组 鸡数 钱数
.......

输出
第一组解个数
第一组第一个解公鸡数 母鸡数 小鸡数
第一组第二个解公鸡数 母鸡数 小鸡数
.........

第二组解个数
第二组第一个解公鸡数 母鸡数 小鸡数
第二组第二个解公鸡数 母鸡数 小鸡数
.........

样例输入
2
100 100
200 200
样例输出
3
4 18 78
8 11 81
12 4 84
7
4 43 153
8 36 156
12 29 159
16 22 162
20 15 165
24 8 168
28 1 171
*/
# include <stdio.h>
class ChickenProblem
{
private:
	int number;
	int amount;
	int *cock;
	int *hen;
	int *chick;
	int solution;
public:
	ChickenProblem()
	{
		number = 0;
		amount = 0;
		cock = new int (0);
		hen = new int (0);
		chick = new int (0);
		solution = 0;
	}
	ChickenProblem( int quantity , int money )
	{
		number = quantity;
		amount = money;
		cock = new int [amount/5];
		hen = new int [amount/5];
		chick = new int [amount/5];
		solution = 0;
	}
	~ChickenProblem()
	{
		delete [] cock;
		delete [] hen;
		delete [] chick;
	}
	void SolvingProblem()
	{
		int i , j;
		cock = new int [amount];
		hen = new int [amount];
		chick = new int [amount];
		for ( i = 1 ; i < amount/5 ; i++ )
		{
			for ( j = 1 ; j < amount/3 ; j++ )
			{
				if ( (number-i-j) > 0 && (number-i-j) %3 == 0 && (5*i+3*j+(number-i-j)/3) == amount )
				{//= =!判断条件一直在错= =！
					cock[solution] = i;
					hen[solution] = j;
					chick[solution] = number - i - j;
					solution++;
				}
			}
		}
	}
	void DisplayingSolution()
	{
		int k;
		printf("%d\n",solution);
		for ( k = 0 ; k < solution ; k++ )
			printf("%d %d %d\n",cock[k],hen[k],chick[k]);
	}
};
int main()
{
	int t,quantity,money;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d",&quantity,&money);
		ChickenProblem questionOne(quantity,money);
		questionOne.SolvingProblem();
		questionOne.DisplayingSolution();
	}
	return 0;
}