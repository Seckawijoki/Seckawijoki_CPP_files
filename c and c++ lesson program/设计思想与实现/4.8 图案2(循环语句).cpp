# include <iostream.h>

int main()

{
	int x,y,z;

	for ( z = 1 ; z <= 40 ; z++ )
	{	

		for ( x = 1 ; x <= z ; x = x + 1 )//x��������z�йء�
		{
			cout<<' ';	
		}

		for ( y =  40 - z ; y >= 1; y = y - 1 )//y��������z�йء�
		{
			cout<<"��";	
		}

		cout<<endl;
	}


	return 0;
}