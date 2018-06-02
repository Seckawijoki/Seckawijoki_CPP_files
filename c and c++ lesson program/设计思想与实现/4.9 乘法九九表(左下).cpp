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
		for ( x = 1 ; x < y + 1 ; x++ )//x <= 9 ±ä³É x < y + 1 ¼´¿É 
				cout<<setw(7)<<x * y;	
		
		cout<<endl;
	}
	return 0;
}