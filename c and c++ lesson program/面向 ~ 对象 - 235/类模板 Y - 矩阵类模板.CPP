/*
题目描述
设计一个矩阵类模板Matrix，支持任意数据类型的数据。

要求至少包含2个成员函数：矩阵转置函数transpose、以及打印输出函数print

编写main函数进行测试，调用类的成员函数完成转置和输出。

输入
第一行先输入t，表示有t个测试用例

从第二行开始输入每个测试用例的数据。

首先输入数据类型，I表示int，D表示double，C表示char，接着输入两个参数m和n，分别表示矩阵的行和列

接下来输入矩阵的元素，一共m行，每行n个数据

输出
输出转置后的矩阵

样例输入
2
I 2 3
1 2 3
4 5 6
C 3 3
a b c
d e f
g h i
样例输出
1 4
2 5
3 6
a d g
b e h
c f i

*/
# include <iostream>
using namespace std;
template < class T >
class Matrix
{
private:
	T element[88][88];
	int line;
	int row;
public:
	Matrix()
	{
		line = 0;
		row = 0;
	}
	Matrix( T initial[88][88] , int l , int r )
	{
		line = l;
		row = r;
		int i,j;
		for ( i = 0 ; i < line ; i++ )
	    	for ( j = 0 ; j < row ; j++ )
				element[i][j] = initial[i][j];
	}
	void Transpose()
	{
		T reserve[88][88];
		int i,j,temp;
		for ( i = 0 ; i < line ; i++ )
	    	for ( j = 0 ; j < row ; j++ )
				reserve[i][j] = element[i][j];
		for ( i = 0 ; i < line ; i++ )
	    	for ( j = 0 ; j < row ; j++ )
				element[j][i] = reserve[i][j];
		temp = line;
		line = row;
		row = temp;
	}
	void Print()
	{
		int i,j;
		for ( i = 0 ; i < line ; i++ )
		{
			for ( j = 0 ; j < row - 1; j++ )
				cout<<element[i][j]<<' ';
			cout<<element[i][j]<<endl;
		}
	}
};
int main()
{
	int t,line,row,i,j;
	char type;
	cin>>t;
	while ( t-- )
	{
		cin>>type>>line>>row;
		if ( type == 'I' )
		{
			int array[88][88];
			for ( i = 0 ; i < line ; i++ )
				for ( j = 0 ; j < row; j++ )
					cin>>array[i][j];
			Matrix<int> puggy(array,line,row);
			puggy.Transpose();
			puggy.Print();
		}
		else if ( type == 'D' )
		{
			double array[88][88];
			for ( i = 0 ; i < line ; i++ )
				for ( j = 0 ; j < row; j++ )
					cin>>array[i][j];
			Matrix<double> puggy(array,line,row);
			puggy.Transpose();
			puggy.Print();
		}
		else if ( type == 'C' )
		{
			char array[88][88];
			for ( i = 0 ; i < line ; i++ )
				for ( j = 0 ; j < row; j++ )
					cin>>array[i][j];
			Matrix<char> puggy(array,line,row);
			puggy.Transpose();
			puggy.Print();
		}
	}
	return 0;
}