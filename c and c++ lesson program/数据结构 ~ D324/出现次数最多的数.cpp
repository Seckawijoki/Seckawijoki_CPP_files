# include <iostream>
using namespace std;
int Function( int array[1000], int n )
{
	int i, j, number, index, maxtimes, minimum;
	int copy[10000] = {0};
	int *types = new int [n];
	int *times = new int [n];
	for ( i = 0 ; i < n ; ++i )
		++copy[array[i]];
	for ( i = 0, j = 0 ; i < 10000 ; ++i )if ( copy[i] )
	{
		types[j] = i;
		times[j] = copy[i];
		++j;
	}
	maxtimes = times[0];
	for ( i = 0 ; i < j ; ++i )
		if ( maxtimes < times[i] )
		{
			maxtimes = times[i];
			index = i;
		}
	number = 0;
	for ( i = 0 ; i < j ; ++i )if ( maxtimes == times[i] )
		copy[number++] = types[i];
	minimum = copy[0];
	for ( i = 0 ; i < number ; ++i )if ( minimum > copy[i] )
		minimum = copy[i];
	return minimum;
}
int main()
{
		int i, n;
		int array[1000];
		cin>>n;
		for ( i = 0 ; i < n ; ++i )
			cin>>array[i];
		cout<<Function(array,n)<<endl;
	return 0;
} 
/*
试题编号： 1 
试题名称： 出现次数最多的数 
时间限制： 1.0s 
内存限制： 256.0MB 
问题描述： 问题描述
给定n个正整数，找出它们中出现次数最多的数。【如果这样的数有多个，请输出其中最小的一个。】 

输入格式
输入的第一行只有一个正整数n(1 ≤ n ≤ 1000)，表示数字的个数。
输入的第二行有n个整数s1, s2, …, sn (1 ≤ si ≤ 10000, 1 ≤ i ≤ n)。相邻的数用空格分隔。

输出格式
输出这n个次数中出现次数最多的数。如果这样的数有多个，输出其中最小的一个。

样例输入
6
10 1 10 20 30 20

样例输出
10
*/
