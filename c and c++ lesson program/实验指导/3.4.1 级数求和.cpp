/*============================*
	求下列通项公式的前n项和：
	              x^n
	(-1)^(n+1) * -----
	              n !

*============================*/

# include <iostream.h>
# include <iomanip.h>
# include <math.h>
int main()
{
	int i = 1 , x , n , mul = 1 , k = 1 ;
	double y = 1 , z = 0 ;
	cout<<"对下面的通项公式求和：\n";
	cout<<"              x^n\n";
	cout<<"(-1)^(n+1) * -----\n";
	cout<<"              n !\n";
	cout<<"\n请输入x和n：";
	cin>>x>>n;
	while ( i <= n )
	{
		for ( int j = 1 ; j <= i ; j++ )
			mul = mul * j ;
		//cout<<mul<<endl;//测试阶乘时。
		y = y + ( k * pow( x , i ) ) / double(mul) ;
		i++;
		k *= -1;
		mul = 1;
	}
	cout<<"\n结果：\n"<<setiosflags(ios::showpoint)
		<<setiosflags(ios::fixed)<<setprecision(8)<<y<<endl;
	return 0;
}
/*
	多次错误：
	1.误以long为long double。
	2.阶乘求不准。
	3.阶乘值没有返回1。
	4.定义变量为0时带来的逻辑顺序问题。
*/