# include <iostream.h>

int main()

{	
	int x;
	cout<<"������һ���ɼ���";
	cin>>x;
	switch ( x /10 )//��ȱ�ݡ��������С���ġ�
	{
		case 10: //101-109�ᱻ�������
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