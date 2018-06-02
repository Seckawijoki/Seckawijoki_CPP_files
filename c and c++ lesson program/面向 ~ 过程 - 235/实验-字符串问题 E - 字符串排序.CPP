# include <stdio.h>
# include <string.h>
int main()
{
	int t,n,i,j;
	char a[10][20],ch[20];
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d",&n);
		for ( i = 0 ; i < n ; i++ )
			scanf("%s",a[i]);
		for ( i = 0 ; i < n ; i++ )
			for ( j = i + 1 ; j < n ; j++ )
				if ( strcmp(a[i],a[j]) <= -1 )//字符串比较大小。
				{
					strcpy(ch,a[i]);
					strcpy(a[i],a[j]);
					strcpy(a[j],ch);
				}
		for ( i = 0 ; i < n-1 ; i++ )
			printf("%s ",a[i]);
		printf("%s\n",a[i]);
	}	
	return 0;
}

