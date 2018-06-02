# include <stdio.h>
# include <string.h>
long change ( char s[] )
{
	long sum = 0,k = 1;
	int i,len = strlen(s);
	for ( i = len-1 ; i >= 0 ; i-- )//µ¹ÐòÏà¼Ó¡£
	{
		if ( s[i] >= '0' && s[i] <= '9' )
			sum += k * ( s[i] - '0' );
		else if ( s[i] >= 'A' && s[i] <= 'F' )
			sum += k * ( s[i] - 'A'  + 10);//¼ÆËã´íÎó£¡£¡
		k *= 16;
	}
	return sum;
}
int main()
{
	int n;
	char s[13];
	scanf("%d",&n);
	while ( n-- )
	{
		scanf("%s",s);
		printf("%ld\n",change(s));
	}
	return 1;
}