# include <iostream.h>
# include <math.h>

int main()

{
	long x;
	int i = 2;
	cout<<"������һ��������";
	cin>>x;
	while ( i <= sqrt( x ) )//�Ľ���i<=���ţ�x��
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