# include <stdio.h>
int main()
{
	int i,j,itvl,a[10];
	while ( 1 )
	{
		for ( i = 0 ; i < 10 ; i++ )
			a[i] = i + 1;
		printf("请输入一个数小孩的整数 ：");
		scanf("%d",&itvl);

		for ( i = 0 ; i < 10 ; i++ )
			printf("%d,",a[i]);
		printf("\n");

		int k = 1;
		i = -1;

		while ( 1 )
		{
			for ( j = 0 ; j < itvl ; )
			{
				i = (i+1) %10;
				if ( a[i] )
					j++;
			}
			if ( k == 10 )
				break;
			printf("%d,",a[i]);
			a[i] = 0;
			k++;
		}
		printf("\n第%d个男孩获胜！\n",a[i]);
	}
	return 0;
}	