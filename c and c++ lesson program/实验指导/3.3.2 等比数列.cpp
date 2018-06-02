# include <iostream.h>
# include <cstdio>
# include <iomanip.h>
# include <math.h>
int main()
{
	float i,q,sum;//带小数的数可不需要太高的精确度。
	int n;
	while ( 1 )
	{
		scanf("%d %f",&n,&q);
		sum = 0;
		for ( i = 0 ; i <= n ; i++ )//n = 项数 - 1
			sum += pow( q , i );//直接用指数函数。

		cout<<"公比为"<<q<<",项数为"<<n<<"的等比数列的前"<<n<<"项和为："
			<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl;
	}
	return 0;
}
