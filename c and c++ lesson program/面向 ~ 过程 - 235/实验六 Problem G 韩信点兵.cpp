/*
Description
韩信有一队兵，至少有M人，他想知道有多少人，便让士兵排队报数，
按从1到5报数，记下最末一个士兵报的数为1；
再按从1到6报数，记下最末一个士兵报的数为5；
按从1到7报数，记下最末一个士兵报的数为4；
最后按从1到11报数，最末一个士兵报的数为10。
问，韩信至少有多少兵？

Input
输入M

Output
输出M以上最少的人数

Sample Input
1000

Sample Output
2111
*/
# include <iostream>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while ( 1 )
	{
		if ( x %5 == 1 &&  x %6 == 5 &&  x %7 == 4 &&  x %11 == 10 )
			break;
		x++;
	}
	cout<<x<<endl;
	return 0;
}