# include <iostream>
using namespace std;
int SelectMaximum( int array[], int low, int high )
{
	int i;
	int maximum = array[low];
	for ( i = low + 1 ; i <= high ; ++i )if ( maximum < array[i] )
		maximum = array[i];
	return maximum;
}
int SelectMinimum( int array[], int low, int high )
{
	int i;
	int minimum = array[low];
	for ( i = low + 1 ; i <= high ; ++i )if ( minimum > array[i] )
		minimum = array[i];
	return minimum;
}
int main()
{
	int i, bottom, low, high, n, number;
	int height[1001] = {0};
	int area[1001] = {0};
	int rectangle[1001] = {0};
	cin>>n;
	for ( i = 1 ; i <= n ; ++i )
		cin>>height[i];
	rectangle[1] = SelectMaximum(height,1,n);
	for ( bottom = 2 ; bottom <= n ; ++bottom )
	{
		number = 1;
		for ( low = 1, high = low + bottom - 1 ; high <= n ; ++low, ++high )
			area[number++] = SelectMinimum(height,low,high) * bottom;
		rectangle[bottom] = SelectMaximum(area,1,number-1);
	}
	cout<<SelectMaximum(rectangle,1,bottom-1)<<endl;
	return 0;
}
/*
试题编号：	3
试题名称：	最大的矩形
时间限制：	1.0s
内存限制：	256.0MB
问题描述：	
问题描述
在横轴上放了n个相邻的矩形，每个矩形的宽度是1，
而第i（1 ≤ i ≤ n）个矩形的高度是hi。
这n个矩形构成了一个直方图。
例如，下图中六个矩形的高度就分别是3, 1, 6, 5, 2, 3。
请找出能放在给定直方图里面积最大的矩形，
它的边要与坐标轴平行。
对于上面给出的例子，最大矩形如下图所示的阴影部分，
面积是10。

输入格式
第一行包含一个整数n，即矩形的数量(1 ≤ n ≤ 1000)。
第二行包含n 个整数h1, h2, … , hn，相邻的数之间由空格分隔。(1 ≤ hi ≤ 10000)。hi是第i个矩形的高度。

输出格式
输出一行，包含一个整数，即给定直方图内的最大矩形的面积。

样例输入
6
3 1 6 5 2 3

样例输出
10
*/
