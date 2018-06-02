# include <iostream>
using namespace std;
int InterestingDigit( int number[1001], int digit )
{
	int i, j;
	bool attendance[4] = {false,false,false,false};
	for ( j = 3 ; j >= 0 ; --j )
	{
		for ( i = 1 ; i <= digit ; ++i )if ( number[i] == j )
		{
			attendance[j] = true;
			break;
		}
		if ( attendance[j] == false )break;
	}
	if ( attendance[3] && attendance[1] && attendance[2] && attendance[0] )
	{
	//	for ( i = digit ; i >= 1 ; --i )cout<<number[i];cout<<"   ";
		bool frontalzero, frontaltwo;
		for ( i = 1 ; i <= digit ; ++i )
		{
			frontalzero = true;
			frontaltwo = true;
			if ( number[i] == 0 )
			{
				for ( j = i + 1 ; j <= digit ; ++j )if ( number[j] == 1 )
				{
					frontalzero = false;
					break;
				}
			}
			else if ( number[i] == 1 )
			{
				for ( j = 1 ; j < i ; ++j )if ( number[j] == 0 )
				{
					frontalzero = false;
					break;
				}
			}
			else if ( number[i] == 2 )
			{
				for ( j = i + 1 ; j <= digit ; ++j )if ( number[j] == 3 )
				{
					frontaltwo = false;
					break;
				}
			}
			else if ( number[i] == 3 )
			{
				for ( j = 1 ; j < i ; ++j )if ( number[j] == 2 )
				{
					frontaltwo = false;
					break;
				}
			}
			else
			{
				frontalzero = false;
				frontaltwo = false;
				break;
			}
			if ( !frontalzero )break;
			if ( !frontaltwo  )break;
		}
		if ( frontalzero && frontaltwo )return 1;
		else return 0;
	}
	else
		return 0;
}
int main()
{
	int  i, n, result;
	long long sum = 0;
	int number[1001] = {0};
	cin>>n;
	number[n] = 1;
	while ( number[n+1] == 0 )
	{
		result = InterestingDigit(number,n);
		sum += result;
	//	if ( result )cout<<sum<<endl;
		++number[1];
		for ( i = 1 ; i <= n ; ++i )if ( number[i] >= 4 )
		{
			number[i] -= 4;
			++number[i+1];
		}
	}
	cout<<sum %1000000007<<endl;
	return 0;
}
/*
试题编号：	4
试题名称：	有趣的数
时间限制：	1.0s
内存限制：	256.0MB
问题描述：	
问题描述
我们把一个数称为有趣的，当且仅当：
1. 它的数字只包含0, 1, 2, 3，且这四个数字都出现过至少一次。
2. 所有的0都出现在所有的1之前，而所有的2都出现在所有的3之前。
3. 最高位数字不为0。
因此，符合我们定义的最小的有趣的数是2013。除此以外，4位的有趣的数还有两个：2031和2301。
请计算恰好有n位的有趣的数的个数。由于答案可能非常大，只需要输出答案除以1000000007的余数。

输入格式
输入只有一行，包括恰好一个正整数n (4 ≤ n ≤ 1000)。

输出格式
输出只有一行，包括恰好n 位的整数中有趣的数的个数除以1000000007的余数。

样例输入
4

样例输出
3
*/
