# include <iostream.h>

int main()
{
	int a,b,c,d,x;
	a = c = 0;
	b = 1;
	d = 20;
	if ( a )
		d = d - 10;
	else if ( !b )

		if ( !c )
			x = 15;
		else
			x = 25;
	
	cout<<d<<endl;

	return 0;
}
/*
	在Vc6.0的运行结果是：
	20
*/