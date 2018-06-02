/*==================================*
	  求和：1！+ 2！+ 3！+ …… +12！
		试用调用函数。

	  2014年11月18日 16:56:43：
  		试用自调函数。
*==================================*/
# include <iostream.h>

int main()
{
	int i,sum = 0;
	int mul( int i );
	for ( i = 1 ; i <= 12 ; i++ )
		sum += mul( i );
	cout<<"求和：1！+ 2！+ 3！+ …… +12！="<<sum<<endl;
	return 1;
}
/*--------------似乎不可用-------------------
int sum( int n )
{
	int mul( int n );
	if ( n == 1 )
		return 1;
	return sum( mul( n - 1 ) ) + mul( n );
}
*/
int mul( int i )
{
	if ( i <= 1 )
		return 1;
	return mul( i - 1 ) * i;
}