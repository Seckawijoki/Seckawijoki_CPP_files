# include <iostream.h>
# include <iomanip.h>

int main()

{
	int x,y,z;

	for ( z = 1 ; z <= 40 ; z++ )
	{	

		for ( x = 40 - z ; x >= 1 ; x = x - 1 )//x须于行数z有关。
		{
			cout<<' ';	
		}

		for ( y =  1 ; y <= 2 * z - 1 ; y = y + 1 )//y须于行数z有关。
		{
			cout<<"#";	
		}

		cout<<endl;
	}

	return 0;
}