# include <stdio.h>
# include <string.h>
int isPalindrome ( char s[] )
{
	int i,len,tg = 1;
	len = strlen(s);
	for ( i = 0 ; i <= len / 2 - 1 ; i++ )
	{
		if ( s[i] != s[len-1-i] )//头尾问题需精确。
		{
			tg--;
			break;
		}
	}
	if ( tg == 1 )
		printf("Yes\n");
	else if ( tg == 0 )
		printf("No\n");
	return 1;
}
int main()
{
	int n;
	char s[55];
	scanf("%d",&n);
	while ( n-- )
	{
		scanf("%s",s);
		isPalindrome(s);
	}
	return 0;
}