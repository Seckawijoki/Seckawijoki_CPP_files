 #include <iostream.h>
	#include <iomanip.h>
	void main()
	{
		int		num , sum , temp;
		for ( num =50 ; num < 100 ; num++)
		{
			temp = num , sum = 0;
			while(temp)
			{
				sum = temp %10 + sum *10;
				temp /= 10;
			}
			if (sum != num)
				continue;
			cout << setw(4) << num ;
		}
		cout << endl;
	}
