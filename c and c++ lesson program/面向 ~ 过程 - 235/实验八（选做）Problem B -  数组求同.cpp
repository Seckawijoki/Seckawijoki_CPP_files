/*
Description

输入两个数组（数组元素个数6和8），输出在两个数组中都出现的元素
（如a[6]={2,3,4,5,6,7},b[8]={3,5,7,9,11,13,15,19},则输出3、5、7）。

Input
Output
Sample Input
2 3 4 5 6 7
3 5 7 9 11 13 15 19
Sample Output
3
5
7

*/
# include <iostream>
using namespace std;
int main()
{
	int a[6],b[8],i,j;
	for ( i = 0 ; i < 6 ; i++ )
		cin>>a[i];
	for ( i = 0 ; i < 8 ; i++ )
		cin>>b[i];
	for ( i = 0 ; i < 6 ; i++ )
	{
		for ( j = 0 ; j < 8 ; j++ )
		{
			if ( a[i] == b[j] )
				{
					cout<<a[i]<<endl;
					break;
				}
		}
	}
	return 0;
}