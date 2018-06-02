# include <stdio.h>
# include <string.h>
int fz( char b[] , char c[] )
{
	int i,k = strlen(c);
	for ( i = 0 ; i < k ; i++ )
		b[i] = c[k-1-i];
	b[i] = '\0';
	return 1;
}
int main()
{
	char b[33],c[33];
	scanf("%s",c);
	fz(b,c);
	printf("%s\n",b);
	return 0;
}