# include <iostream.h>
# include <math.h>

int main()

{
	double a,x, y1,y2,y3;
	cin>>a>>x;
	y1 = sqrt( pow( sin(x) , 2.5 ) );
	y2 = ( a * x + ( a + x ) / 4 / a ) / 2;
	y3 = ( exp( x * x ) ) / sqrt( 2 * 3.14 );//±‰–Œ°£
	cout<<y1<<endl<<y2<<endl<<y3<<endl;

	return 0;
}