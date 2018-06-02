# include <iostream.h>
# include <iomanip.h>
# include <math.h>

int main()

{
	long a,b,l = 0;
	cout<<"请输入两个数：";
	cin>>a>>b;
	cout<<"素数（prime）从"<<a<<"到"<<b<<"是 : \n";

	//先判断偶数。
	if ( a == 2 )
		cout<<"2 ";
	if ( a %2 == 0)//确保从奇数开始循环。
		a++;

	for ( long m = a ; m <= b ; m += 2 )
	{
		int x = sqrt(m);//原来的判断小于根号（m）。
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