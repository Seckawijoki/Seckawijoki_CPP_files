# include <iostream.h>
# include <cstdio>
int main()
{
	int i,n,m;
	float sum;
	printf("��������������n����n������");
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
		printf("��%d������ƽ����Ϊ��%.3f\n\n",n,sum / n);
	}

	return 0;
}