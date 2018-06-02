# include <iostream.h>

int main()

{
	int x;
//	int a,b,c;
//	a = b = c = 0;
	cin>>x;
/*	switch ( x %3 )
	{
		case 1:
		case 2:break;
		case 0:a = 3;break;
		default:break;
	}
	switch ( x %5 )
	{
		case 1:
		case 2:
		case 3:
		case 4:break;
		case 0:b = 5;break;
		default:break;
	}
	switch ( x %7 )
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:break;
		case 0:c = 7;break;
		default:break;
	}
*/
	if ( x %3 == 0 && x %5 == 0 && x %7 == 0 )
		cout<<"能同时被3,5,7整除\n";

	if ( x %3 != 0 && x %5 == 0 && x %7 == 0 )
		cout<<"能同时被5,7整除\n";
	if ( x %3 == 0 && x %5 != 0 && x %7 == 0 )
		cout<<"能同时被3,7整除\n";
	if ( x %3 == 0 && x %5 == 0 && x %7 != 0 )
		cout<<"能同时被3,5整除\n";

	if ( x %3 != 0 && x %5 != 0 && x %7 == 0 )
		cout<<"能被7整除\n";
	if ( x %3 != 0 && x %5 == 0 && x %7 != 0 )
		cout<<"能被5整除\n";
	if ( x %3 == 0 && x %5 != 0 && x %7 != 0 )
		cout<<"能被3整除\n";

	if ( x %3 != 0 && x %5 != 0 && x %7 != 0 )
		cout<<"不能同时被3,5,7任一个整除\n";


	return 0;
}