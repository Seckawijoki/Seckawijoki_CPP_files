/*==========================================*
	"完数"是指一个数恰好等于它的因子之和。
	如6 = 1 + 2 + 3
*==========================================*/
# include <iostream.h>
# include <iomanip.h>
int main()
{
	cout<<"\"完数\"是指一个数恰好等于它的因子之和。\n"
		<<"现求1000之内的所有结果：\n";
	int n;
	int cplt( int n );
	for ( n = 1 ; n <= 1000 ; n++ )
		cplt( n );
	cout<<endl;
	return 0;
}
/*
	结果：
	6		28		496
*/
int cplt( int n )//判断完数
{
	int i = 1 , sum = 0;
	for ( i = 1 ; 2 * i <= n ; i++ )//i超n的一半就没有约数了。
		if ( n %i == 0 )//约数之和。
			sum += i;
	if ( sum == n )
		cout<<setw(6)<<n;

	return 1;
}