# include <iostream.h>

int main()

{	
	int x;
	cout<<"请输入一个成绩：";
	cin>>x;
	switch ( x /10 )//有缺陷。不能算带小数的。
	{
		case 10: //101-109会被算进来。
		case 9: cout<<"A\n";break;
		case 8: cout<<"B\n";break;
		case 7: cout<<"C\n";break;
		case 6: cout<<"D\n";break;
		case 5: 
		case 4: 
		case 3: 
		case 2: 
		case 1: 
		case 0: cout<<"E\n";break;
		default:cout<<"???\n";break;
	}

	return 0;
}