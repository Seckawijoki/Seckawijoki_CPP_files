# include <iostream.h>

int main()

{
	int x,i = 2;
	cout<<"请输入一个整数：";
	cin>>x;
	while ( i <= ( x - 1 ) )
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