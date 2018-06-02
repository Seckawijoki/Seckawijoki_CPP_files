# include <iostream.h>
int main()
{
	char c;
	cout<<"ÇëÊäÈëÒ»¸ö×Ö·û£º";
	cin>>c;
	int i,j;
	for ( i = 1 ; i <= 7 ; i++ )
	{
		for ( j = 7 - i ; j >= 1 ; j-- )
			cout<<' ';
		for ( j = 1 ; j <= ( 2 * i - 1 ) ; j++ )
			cout<<c;
		cout<<endl;
	}
	return 0;
}