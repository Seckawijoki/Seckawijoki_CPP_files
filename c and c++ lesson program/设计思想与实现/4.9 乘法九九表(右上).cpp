# include <iostream.h>
# include <iomanip.h>

int main()

{
	int x,y;
	cout<<setw(7)<<'*';
	for ( x = 1 ; x <= 9 ; x++ )	
		cout<<setw(7)<<x;	

	cout<<endl;
	for ( x = 1 ; x <= 76 ; x++ )	
		cout<<'-';	

	cout<<endl;
	for ( y = 1 ; y <= 9 ; y++ )
	{	
		cout<<setw(7)<<y;
		for ( x = 1 ; x < y ; x++ )	
			cout<<setw(7)<<' ';				//出了很多错。

		for ( x = 9 ; x >= y ; x-- )	
			cout<<setw(7)<<( 9 - x + y ) * y;//出了很多错。
		
		cout<<endl;
	}
	return 0;
}