# include <iostream.h>
# include <string.h>
template < class T >
T QuestingMinimum( T a , T b )
{
	return ( a < b ? a : b );
}
char * QuestingMinimum( char *a , char *b )
{
	/**/ if ( strlen(a) <  strlen(b) )
		return a;
	else if ( strlen(a) >  strlen(b) )
		return b;
	else if ( strlen(a) == strlen(b) )
	{
		int sum1 = 0;
		int sum2 = 0;
		int i;
		for ( i = 0 ; i < strlen(a) ; i++ )
			sum1 += a[i];
		for ( i = 0 ; i < strlen(b) ; i++ )
			sum2 += b[i];
		/**/ if ( sum1 <  sum2 )
			return a;
		else if ( sum1 >  sum2 )
			return b;
		else if ( sum1 == sum2 )
		{
			for ( i = 0 ; i < strlen(a) ; i++ )
			{
				/**/ if ( a[i] <  b[i] )
					return a;
				else if ( a[i] >  b[i] )
					return b;
				else if ( a[i] == b[i] )
					continue;
			}
		}
	}
	return a;
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<QuestingMinimum(a,b)<<endl;

	double c,d;
	cin>>c>>d;
	cout<<QuestingMinimum(c,d)<<endl;

	char e,f;
	cin>>e>>f;
	cout<<QuestingMinimum(e,f)<<endl;

	char g[55],h[55];
	cin>>g>>h;
	cout<<QuestingMinimum(g,h)<<endl;

	return 0;
}
/*
55 13 2.5 1.9 h a aeturyidtyid chjxjdryfjdy
*/