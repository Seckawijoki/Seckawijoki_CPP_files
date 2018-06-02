/*
题目描述
一开始未知数组长度，根据要求创建不同类型的指针，
并且使用指针创建相应长度的数组，然后再完成不同的要求

若要求创建整数数组，计算数组内所有数据的平均值
若要求创建字符数组，找出数组内的最大字母
若要求创建浮点数数组，找出数组的最小值

要求程序整个过程不能使用数组下标，
从数组创建、输入到搜索、比较、计算，到输出都必须使用指针

输入
第一行输入t表示有t个测试实例
第二行先输入一个大写字母表示数组类型，
I表示整数类型，C表示字符类型，F表示浮点数类型；

然后输入n表示数组长度。

第三行输入n个数据
依次输入t个实例

输出
每个根据不同的数组类型输出相应的结果

样例输入
3
C 5
A D E B C
I 6
22 55 77 33 88 55
F 4
3.1 1.9 6.5 4.8

9
I 6
22 55 77 33 88 55

样例输出
E
55
1.9
*/
# include <iostream>
using namespace std;
int main()
{
	int t,n,i;
	char ch;
	cin>>t;
	while ( t-- )
	{
		cin>>ch>>n;//还是用C++好~~
		if ( ch == 'C' )
		{
			char *pch = new char[n];
			for ( i = 0 ; i < n ; i++ )
				cin>>*(pch + i);//输入cin>>*(pch++)已经改变了地址，导致下面的错误。
			for ( i = 1 ; i < n ; i++ )
				if ( *pch < *(pch + i) )
					*pch = *(pch + i);//不能覆盖地址。
			cout<<*pch<<endl;
			delete [] pch;
		}
		else if ( ch == 'I' )
		{
			int sum = 0,*px = new int[n];//sum初始0~~
			for ( i = 0 ; i < n ; i++ )
				cin>>*(px + i);//输入cin>>*(px++)已经改变了地址，导致下面的错误。
			for ( i = 0 ; i < n ; i++ )
				sum += *(px + i);
			cout<<sum/n<<endl;
			delete [] px;
		}
		else if ( ch == 'F' )
		{
			float *pf = new float[n];
			for ( i = 0 ; i < n ; i++ )
				cin>>*(pf + i);//输入cin>>*(pf++)已经改变了地址，导致下面的错误。
			for ( i = 1 ; i < n ; i++ )
				if ( *pf > *(pf + i) )
					*pf = *(pf + i);
			cout<<*pf<<endl;
			delete [] pf;
		}
	}
	return 1;
}