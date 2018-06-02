# include <iostream.h>
# include <cstdio>
int main()
{
	int i,n,m;
	float sum;
	printf("请输入整数个数n和这n个数：");
	while ( 1 )
	{
		scanf("%d",&n);
		printf("\n ");
		sum = 0;
		for ( i = 1 ; i <= n ; i++ )
		{
			scanf("%d",&m);
			sum += m;
			printf("%d ",m);
		}
		printf("这%d个数的平均数为：%.3f\n\n",n,sum / n);
	}

	return 0;
}