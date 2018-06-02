# include <stdio.h>
# include <string.h>
int main()
{
	int i,n,sum;
	char a[20],b[20];
	scanf("%d",&n);
	while ( n-- )
	{
		sum = 0;
		scanf("%s",a);
		scanf("%s",b);
		if ( strlen(a) > strlen(b) )
			printf("1\n");
		else if ( strlen(a) < strlen(b) )
			printf("-1\n");
		else if ( strlen(a) == strlen(b) )
		{
			for ( i = 0 ; i < strlen(a) ; i++ )
				sum += a[i] - b[i];
			if ( sum > 0 )
				printf("1\n");
			else if ( sum < 0 )
				printf("-1\n");
			else if ( sum == 0 )
				printf("0\n");
		}
	}
	return 0;
}