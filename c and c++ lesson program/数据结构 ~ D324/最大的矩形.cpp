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
�����ţ�	3
�������ƣ�	���ľ���
ʱ�����ƣ�	1.0s
�ڴ����ƣ�	256.0MB
����������	
��������
�ں����Ϸ���n�����ڵľ��Σ�ÿ�����εĿ����1��
����i��1 �� i �� n�������εĸ߶���hi��
��n�����ι�����һ��ֱ��ͼ��
���磬��ͼ���������εĸ߶Ⱦͷֱ���3, 1, 6, 5, 2, 3��
���ҳ��ܷ��ڸ���ֱ��ͼ��������ľ��Σ�
���ı�Ҫ��������ƽ�С�
����������������ӣ�����������ͼ��ʾ����Ӱ���֣�
�����10��

�����ʽ
��һ�а���һ������n�������ε�����(1 �� n �� 1000)��
�ڶ��а���n ������h1, h2, �� , hn�����ڵ���֮���ɿո�ָ���(1 �� hi �� 10000)��hi�ǵ�i�����εĸ߶ȡ�

�����ʽ
���һ�У�����һ��������������ֱ��ͼ�ڵ������ε������

��������
6
3 1 6 5 2 3

�������
10
*/
