/*
题目描述

江湖中有一个传言，只要倚天剑和屠龙刀中暗藏的秘密拼到一起，就能得到天下无敌的内功秘笈。
设计一个函数模板，完成拼凑的功能（将倚天剑的秘密连接到屠龙刀的后面），
并将秘笈输出. 其中每个秘密由n个元素组成，类型为T。

输入

第一行输入t表示有t个测试实例

第二行先输入一个大写字母表示数据类型，
I表示整数类型，D表示双精度数类型，C表示字符型；
然后输入n表示数据个数。

第三行输入倚天剑的n个数据
第四行输入屠龙刀的n个数据
依次输入t个实例

输出

每行输出一个结果

样例输入
2
I 5
5 3 51 27 9
27 0 0 5 1
C 5
kitty
hello

样例输出
2700515351279
hellokitty

*/
# include <iostream>
using namespace std;
template < class T >
T *connection(  T *ytj , T *tld , int number )
{
	int i;
	for ( i = 0 ; i < number ; i++ )
		tld[i+number] = ytj[i];
	return tld;
}
int main()
{
	int t,n,i;
	char type;
	cin>>t;
	while ( t-- )
	{
		cin>>type>>n;
		if ( type == 'I' )
		{
			int *mj1 = new int [2*n];
			int *mj2 = new int [2*n];
			int *mj;
			for ( i = 0 ; i < n ; i++ )
				cin>>mj1[i];
			for ( i = 0 ; i < n ; i++ )
				cin>>mj2[i];
			mj = connection(mj1,mj2,n);
			for ( i = 0 ; i < 2 * n ; i++ )
				cout<<mj[i];
			cout<<endl;
			delete [] mj1;
			delete [] mj2;
		}
		else if ( type == 'D' )
		{
			double *mj1 = new double [2*n];
			double *mj2 = new double [2*n];
			double *mj;
			for ( i = 0 ; i < n ; i++ )
				cin>>mj1[i];
			for ( i = 0 ; i < n ; i++ )
				cin>>mj2[i];
			mj = connection(mj1,mj2,n);
			for ( i = 0 ; i < 2 * n ; i++ )
				cout<<mj[i];
			cout<<endl;
			delete [] mj1;
			delete [] mj2;
		}
		else if ( type == 'C' )
		{
			char *mj1 = new char [2*n];
			char *mj2 = new char [2*n];
			char *mj;
			for ( i = 0 ; i < n ; i++ )
				cin>>mj1[i];
			for ( i = 0 ; i < n ; i++ )
				cin>>mj2[i];
			mj = connection(mj1,mj2,n);
			for ( i = 0 ; i < 2 * n ; i++ )
				cout<<mj[i];
			cout<<endl;
			delete [] mj1;
			delete [] mj2;
		}
	}
	return 0;
}


