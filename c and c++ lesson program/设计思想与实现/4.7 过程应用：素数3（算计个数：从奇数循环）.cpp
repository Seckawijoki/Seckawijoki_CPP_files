# include <iostream.h>
# include <iomanip.h>
# include <math.h>

int main()

{
	long a,b,l = 0;
	cout<<"��������������";
	cin>>a>>b;
	cout<<"������prime����"<<a<<"��"<<b<<"�� : \n";

	//���ж�ż����
	if ( a == 2 )
		cout<<"2 ";
	if ( a %2 == 0)//ȷ����������ʼѭ����
		a++;

	for ( long m = a ; m <= b ; m += 2 )
	{
		int x = sqrt(m);//ԭ�����ж�С�ڸ��ţ�m����
		int i;
		for ( i = 2 ; i <= x ; i++ )
			if ( m %i == 0 )
				break;

		if ( i > x )
		{	if ( l++ %10 == 0 )
				cout<<'\n';
		
			cout<<setw(7)<<m;
		}
	}
		
		
	return 0;
}