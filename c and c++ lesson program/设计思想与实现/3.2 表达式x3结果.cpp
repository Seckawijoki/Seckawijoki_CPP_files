# include <iostream.h>
# include <math.h>
# include <cstdio>

int main()

{
	//(1)
	int e = 1 , f = 4 , g = 2 ;
	float m = 10.5 , n = 4.0 , k ;
	k = ( e + f ) / g + sqrt((double) n ) * 1.2 / g + m ;
	printf("(1) k = %f\n\n",k);

	//(2)
	float x = 2.5 , y = 4.7 ;
	int a = 7;
	cout<<"(2) "<<x + a %3 * (int) ( x + y ) %2 / 4<<endl<<endl;

	//(3)
	a = 2 ;
	int b = 5;
	a++;
	b++;
	cout<<"(3) "<<a+b<<endl<<endl;


	return 0;
}