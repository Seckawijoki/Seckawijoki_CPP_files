/*
Description

�����������飨����Ԫ�ظ���6��8������������������ж����ֵ�Ԫ��
����a[6]={2,3,4,5,6,7},b[8]={3,5,7,9,11,13,15,19},�����3��5��7����

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