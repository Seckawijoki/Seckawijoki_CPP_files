# include <iostream.h>

int main()

{
	int x,y,z;

	for ( z = 1 ; z <= 40 ; z++ )
	{	

		for ( x = 1 ; x <= z ; x = x + 1 )//x须于行数z有关。
		{
			cout<<' ';	
		}

		for ( y =  40 - z ; y >= 1; y = y - 1 )//y须于行数z有关。
		{
			cout<<"井";	
		}

		cout<<endl;
	}


	return 0;
}