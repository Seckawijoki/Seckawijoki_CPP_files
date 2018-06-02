# include <stdio.h>
int main()
{
	printf("请输入多个正方形的边长：");
	int i;
	int a;
	while ( 1 )
	{
		scanf("%d",&a);
		printf("%d\n",4 * a);
	}
	return 0;
}