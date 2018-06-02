# include <iostream>
using namespace std;
void ShellInsert( int array[], int length, int dk )
{
	int i, j;
	for ( i = dk + 1 ; i <= length ; ++i )
	{
		if ( array[i] < array[i-dk] )
		{
			array[0] = array[i];
			for ( j = i - dk ; j > 0 && array[0] < array[j] ; j -= dk )
				array[j+dk] = array[j];
			array[j+dk] = array[0];
		}
	}
}
int main()
{
	int t, n, i, j;
	int array[512], delta[256] = {0};
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		delta[0] = n;
		for ( i = 1 ; i <= n ; ++i )
			cin>>array[i];
		for ( i = 0 ; delta[i] != 1 ; ++i )
			if ( delta[i] %2 )delta[i+1] = delta[i] /2 + 1;
			else			  delta[i+1] = delta[i] /2;
		cout<<i<<endl;
		for ( i = 0 ; delta[i] ; ++i )cout<<delta[i]<<' ';cout<<endl;
		for ( j = 1 ; j <= i ; ++j )ShellInsert(array,n,delta[j]);
		for ( j = 1 ; j <= n ; ++j )cout<<array[j]<<' ';cout<<endl;
	}
	return 0;
}
/*
题目描述
给出一个数据序列，使用希尔排序算法进行从小到大的排序
间隔gap使用序列长度循环除2直到1

输入
第一行输入t，表示有t个测试示例
第二行输入n，表示第一个示例有n个数据
第三行输入n个数据，都是正整数，数据之间用空格隔开
以此类推

输出
每行输出每个示例排序后，从小到大的结果


样例输入
2
6
111 22 6 444 333 55
8
77 555 33 1 444 77 666 2222

样例输出
6 22 55 111 333 444 
1 33 77 77 444 555 666 2222 
*/
