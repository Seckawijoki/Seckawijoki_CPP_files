# include <stdio.h>
int main()
{
	signed int a,b;
	while ( 1 )
	{
		scanf("%d %d",&a,&b);
		printf("%d\n",a - b);
	}
	return 0;
}