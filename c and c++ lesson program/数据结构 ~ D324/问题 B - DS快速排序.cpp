# include <iostream>
using namespace std;
int Partition( int *array, int low, int high )
{
	int pivotkey = array[low];
	array[0] = array[low];
	while ( low < high )
	{
		while ( low < high && array[high] >= pivotkey )--high;
		array[low] = array[high];
		while ( low < high && array[low]  <= pivotkey )++low;
		array[high] = array[low];
	}
	array[low] = array[0];
	return low;
}
void QuickSort( int *array, int low, int high )
{
	int pivotlocation;
	if ( low < high )
	{
		pivotlocation = Partition(array,low,high);
		QuickSort(array,low,pivotlocation-1);
		QuickSort(array,pivotlocation+1,high);
	}
}
int main()
{
	int t, n, i, j, low, high;
	int array[512];
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		for ( i = 1 ; i <= n ; ++i )
			cin>>array[i];
		QuickSort(array,1,n);
		for ( j = 1 ; j <= n ; ++j )cout<<array[j]<<' ';cout<<endl;
	}
	return 0;
}
/*
题目描述
给出一个数据序列，使用快速排序算法进行从小到大的排序

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
