/*
Description
每个箱子都有长宽高，我们需要判断一个箱子能否放入另一个箱子中。
例如有箱子A的尺寸是 3 x 4 x 5，箱子B的尺寸 是 5 x 6 x 4，
经过比较判断，可以知道箱子A能够放入箱子B中，我们就说箱子A匹配箱子B。
注意，当两个箱子尺寸相等，我们也认为它们匹配。

Input
第一行输入参数T，表示有T个测试实例
第二行输入第1组实例的箱子A的长、宽、高，输入数值为小于1000的自然数
第三行输入第1组实例的箱子B的长、宽、高，输入数值为小于1000的自然数
以此类推

Output
如果两个箱子匹配，输出Yes，否则输出No。逐行输出每一组的箱子匹配结果。

Sample Input
3
3 4 5
5 6 4
5 6 4
3 4 5
5 6 7
7 4 7

Sample Output
Yes
Yes
No

HINT

注意输出结果的大小写

*/
# include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,v1,v2,n;
	cin>>n;
	while ( n-- )
	{
		cin>>a>>b>>c>>d>>e>>f;
		v1 = a * b * c;
		v2 = d * e * f;
		if ( v1 > v2 )
		{
			a = a + d ; d = a - d ; a = a - d;
			b = b + e ; e = b - e ; b = b - e;
			c = c + f ; f = c - f ; c = c - f;
		}
		if ( a <= d && b <= e && c <= f )
			cout<<"Yes\n";
		else if ( a <= e && b <= f && c <= d )
			cout<<"Yes\n";
		else if ( a <= f && b <= d && c <= e )
			cout<<"Yes\n";
		else
			cout<<"No\n";		
	}
	return 0;
}

//-----------------旧错误：

/*		a > b ?  a = a + b , b = a - b , a = a - b : 1 ;
		a > c ?  a = a + c , c = a - c , a = a - c : 1 ;
		b > c ?  b = c : 1 ;//从小到大
		smin = a * b;
		
		d < e ?  d = d + e , e = d - e , d = d - e : 1 ;
		d < f ?  d = d + f , f = d - f , d = d - f : 1 ;
		e < f ?  e = f : 1 ;//从大到小
		smax = d * e;
*/

//		if ( (a * b <= d * e && v1 <= v2 ) || ( b * c >= e * f && v1 >= v2 ) 
	