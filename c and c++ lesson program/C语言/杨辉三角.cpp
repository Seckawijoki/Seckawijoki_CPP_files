# include <iostream.h>
# include <iomanip.h>

int main(void)

{
	int n,m,line;
	int combination( int n , int m );
	cout<<"������Ҫ��ʾ������ǵ�������";//����13�У�14�п�ʼ�㲻���ۡ�
	while ( 1 )
	{
		cin>>line;
		for ( m = 1 ; m <= line ; m++ )
		{
			cout<<setw( 3 * line - 2 * m )<<' ';
			for ( n = 1 ; n <= m ; n++ )
				cout<<setw(4)<<combination( n - 1 , m - 1 );
			cout<<endl;
		}
	}
	return 0;
}

int combination( int n , int m )
{
	int i;
	float Cnm = 1;//ԭ����int�������м��������С��������float��
	for ( i = 1 ; i <= n ; i++ )
		Cnm = Cnm * ( m + 1 - i ) / i;//ԭ����ĸ����( n + i - 1 )��

	return int(Cnm);
}