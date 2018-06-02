# include <iostream.h>
# include <math.h>

int main()

{
	long x;
	int i = 2;
	cout<<"请输入一个整数：";
	cin>>x;
	while ( i <= sqrt( x ) )//改进：i<=根号（x）
	{
		if ( x %i == 0 )
		{
			cout<<"是个合数。\n";
			break;
		}
		else if ( x == x )
		{	
			cout<<"是个素数。\n";
			break;
		}
		else
			i++;
	}
	return 0;
}