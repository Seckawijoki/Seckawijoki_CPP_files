# include <iostream.h>
const size = 5;
  void findmax1( int *a , int &n , int i , int *pk )
//void findmax1( int *a , int  n , int i , int *pk )
{
	if ( i < n )
	{
		if ( a[i] > a[*pk] )
			*pk = i;
		findmax1(a,n,i+1,&(*pk));
	  //findmax1(a,n,i+1,&(*pk));
	}
}
void findmax2( int *a , int  n , int *pk )
{
	int i;
	for ( i = 1 ; i < n ; i ++ )
		if ( a[0] < a[i])
		{
			*pk = i;
			a[0] = a[i];
		}
}
int main()
{
	int a[size];
	int n = 0;
	cout<<"Please input "<<size<<" dates : \n";
	for ( int i = 0 ; i < size ; i ++ )
		cin>>a[i];
	int rsize = size,
		rn = n;
	findmax1(a,rsize,0,&n);
  //findmax1(a, size,0,&n);
	cout<<"After findmax1 : \n"
		<<"The maximum is "<<a[n]<<endl
		<<"It's index is "<<n<<endl<<endl;

	findmax2(a,rsize,&n);
	cout<<"After findmax2 : \n"
		<<"The maximum is "<<a[0]<<endl
		<<"It's index is "<<n<<endl<<endl;
	return 0;
}
