# include <iostream.h>

int main()

{
	int x,y;
	cout<<"������һ�������зֶκ����ļ��㣺";
	cin>>x;
	if ( x > 2 && x <= 10 )
		y = x * ( x + 2 );
	else if ( x > -1 && x <= 2 )
		y = 2 * x;
	else
		y = x - 1;
	cout<<y<<endl;

	return 0;
}