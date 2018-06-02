/*
题目描述
在一个二维矩阵中，如果某个位置的数值是该行最大值，
同时也是该列最小值，我们则称该位置是矩阵的鞍点。
鞍点在工业控制，建筑力学等方面有着广泛应用。
鞍点可能有多个，也可能没有。

请编写程序找出矩阵的鞍点。

输入
第一行输入T表示有T个测试实例

第二行输入两个参数A和B，分别表示矩阵的行数和列数

第三行输入二维矩阵的数据，假定数据都是正整数

以此类推输入下个实例

输出
输出鞍点所在的行号和列号，行号和列号都是从0开始编号。

本题目无需考虑存在多个鞍点的情况，假设如果有鞍点则只有唯一个

如果鞍点不能存在则输出-1

样例输入
2
3 3
11 77 33
44 66 55
22 88 99
4 2
22 11
33 44
55 66
11 88
样例输出
1 1
-1

*/
# include <iostream>
# define ok    1
# define fake  0
using namespace std;
int get_max( int *array , int size )
{
	int i,max = array[0];
	for ( i = 1 ; i < size ; i++ )if ( max < array[i] )
		max = array[i];
	return max;
}
int main()
{
	int t,m,n,i,j,value,array_max,ii,jj;
	int matrix[99][99];
	cin>>t;
	while ( t-- )
	{
		cin>>m>>n;
		for ( i = 0 ; i < m ; i++ )
		for ( j = 0 ; j < n ; j++ )
			cin>>matrix[i][j];

		for ( i = 0 ; i < m ; i++ )
		{
			ii = i;
			array_max = get_max(matrix[i],n);
			for ( j = 0 ; j < n ; j++ )
				if ( array_max == matrix[i][j])
					jj = j;

			for ( j = 0 ; j < m ; j++ )
				if ( array_max > matrix[j][jj] )
				{
					value = fake;
					break;
				}
				else
					value = ok;
			if ( value == ok )
				break;
		}
		if ( value == ok )
			cout<<ii<<' '<<jj<<endl;
		else
			cout<<"-1\n";

	}
	return 0;
}