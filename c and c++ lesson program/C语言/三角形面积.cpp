/*
Description
平面上两点A(1,3)、B(5,1)，输入点C的坐标，计算并输出三角形ΔABC的面积（结果保留两位小数）。

Input
输入点c的 x 坐标

输入点c的 y 坐标

Output
输出三角形的面积

Sample Input
4
4

Sample Output
Area=5.00

HINT
*/
# include <iostream>
# include <iomanip>
# include <cmath>
//或 ： # include <math.h>
using namespace std;
int main()
{
	float x,y,a,b,c,p,s;
	cin>>x>>y;
	a = sqrt( 20 );
	b = sqrt( ( 1 - x ) * ( 1 - x ) + ( 3 - y ) * ( 3 - y ) );
	c = sqrt( ( 5 - x ) * ( 5 - x ) + ( 1 - y ) * ( 1 - y ) );
	p = ( a + b + c ) / 2;
	s = sqrt( p * ( p - a ) * ( p - b ) * ( p - c ) );
	cout<<"Area="<<fixed<<setprecision(2)<<s<<endl;
						//指定为小数位数。
		     //或<<setiosflags(ios::showpoint)<<setprecision(3)<<s<<endl;
												//指定为有效位数。
	return 0;
}
/*
  搞好小数位数即可。
  <<fixed<<setprecision(2)//指定为小数位数。
  <<setiosflags(ios::fixed)<<setprecision(2)//指定为小数位数。
  <<setiosflags(ios::showpoint)<<setprecision(3)//指定为有效位数。
*/