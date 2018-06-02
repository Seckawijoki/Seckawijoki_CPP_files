/*
Description
计算并输出时间hh:mm:ss 经历了n秒后的新时间，hh、mm、ss、n从键盘输入。

Input
输入当前时间

输入经历的秒数n

Output
输出n秒后的时间

Sample Input
12 58 58
121

Sample Output
13:0:59

*/
# include <iostream>
using namespace std;

int main()
{
	int hh,mm,ss,n;
	cin>>hh>>mm>>ss>>n;
/*	
-------------用两个if的传统方法。-------------
	ss = ss + n;
	if ( ss >= 60 )
	{
		mm = mm + ss / 60;
		ss = ss%60;
		if ( mm >= 60 )
		{
			hh = hh + mm / 60;
			mm = mm%60;
		}
	}
----------------------------------------------
	*/
	ss = ss + n;
	mm = mm + ss / 60;
	ss = ss %60;
	hh = hh + mm / 60;
	mm = mm %60;

	cout<<hh<<":"<<mm<<":"<<ss<<endl;
	return 0;
}

/*
	10次左右的算法错误。
	取商：直接除。
*/