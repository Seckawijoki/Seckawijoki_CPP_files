# include <stdio.h>
# include <string.h>
int connection( char a[] , char b[] )
{
	char c[33];
	strcpy(c,a);
	int i,k = strlen(a),l = strlen(b);
	for ( i = 0 ; i < l; i++ )
		c[i+k] = b[i];
	c[i+k] = '\0';
	printf("%s\n",c);
	return 1;
}
int main()
{
	char a[33],b[33];
	scanf("%s%s",a,b);
	connection(a,b);
	return 0;
}