# include <iostream.h>

int main()

{
	int x,i = 2;
	cout<<"������һ��������";
	cin>>x;
	while ( i <= ( x - 1 ) )
	{
		if ( x %i == 0 )
		{
			cout<<"�Ǹ�������\n";
			break;
		}
		else if ( x == x )
		{	
			cout<<"�Ǹ�������\n";
			break;
		}
		else
			i++;
	}
	return 0;
}