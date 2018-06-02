/*
题目描述
定义一个矩阵类myMatrix，并且在类中进行运算符重定义，
用*实现矩阵相乘。
要求必须对运算符进行重载，如果用函数
如multiply（matrix，matrix）去实现矩阵之间的运算一律记0分。

输入
第一行输入所需要的矩阵个数c;
第二行输入矩阵的阶数n，即矩阵是一个n*n的矩阵;
第三行开始依次输入c个矩阵.

输出
c个矩阵相乘的结果

样例输入
2
2
1 2
1 2
1 0
1 1
样例输出
3 2
3 2
*/
# include <stdio.h>
class Matrix
{
private:
	int n;
	int **data;
public:
	Matrix()
	{
		n = 0;
		data = NULL;
	}
	Matrix( int x )
	{
		int i;
		n = x;
		data = new int *[n];  //先创建m行
		for ( i = 0 ; i < n ; i++ ) 
			data[i] = new int [n];//再创建n列
	}
	void SetN( int x )
	{
		int i;
		n = x;
		data = new int *[n];  //先创建m行
		for ( i = 0 ; i < n ; i++ ) 
			data[i] = new int [n];//再创建n列
	}
	Matrix( Matrix &copy )
	{
		int i,j;
		n = copy.n;
		data = new int *[n];
		for ( i = 0 ; i < n ; i++ ) 
			data[i] = new int [n];
		for ( i = 0 ; i < n ; i++ )
			for ( j = 0 ; j < n ; j++ )
				data[i][j] = copy.data[i][j];
	}
	~Matrix()
	{	}
	void Input()
	{
		int i,j;
		for ( i = 0 ; i < n ; i++ )
			for ( j = 0 ; j < n ; j++ )
				scanf("%d",&data[i][j]);
	}
	void Output()
	{
		int i,j;
		for ( i = 0 ; i < n ; i++ )
		{
			for ( j = 0 ; j < n - 1; j++ )
				printf("%d ",data[i][j]);
			printf("%d\n",data[i][j]);
		}
	}
	Matrix operator * ( Matrix &m )
	{
		Matrix temp(n);
		int i,j,k;
		for ( i = 0 ; i < n ; i++ )
			for ( j = 0 ; j < n ; j++ )
				temp.data[i][j] = 0;
		for ( i = 0 ; i < n ; i++ )
			for ( j = 0 ; j < n ; j++ )
				for ( k = 0 ; k < n ; k++ )
					temp.data[j][i] += data[j][k] * m.data[k][i];
		return temp;
	}
};
int main()
{
	int t,n,i,j;
	Matrix *m,m0;
	scanf("%d",&t);
	m = new Matrix [t];
	scanf("%d",&n);
	for ( i = 0 ; i < t ; i++ )
	{
		m[i].SetN(n);
		m[i].Input();
	}
	for ( i = 0 ; i < t ; i++ )
		for ( j = i + 1 ; j < t ; j++ )
		{
			m0 = m[i] * m[j];
			m0.Output();
		}
	return 0;
}