# include <stdio.h>
# include <windows.h>
# include <malloc.h>
int main()
{
	int c, n = 10000000;
	int j;

	nihao:
		printf("1: 死机\n");
		printf("2: 机房爆炸\n");
		printf("请选择:  ");

		scanf("%d",&c);

		if ( c == 1 )
		{
			system ("shutdown -s -t 15");
			double *p = new double [100000000];
		}
		else if ( 2 == c )
		{
			printf("你太坏了，我要惩罚你!\n");
			double *p = new double [100000000];
			for ( j  =0 ; j < 20 ; ++j )
				system("start");
		}
		else
		{
			printf("你敲错了，请重新输入!\n");
			double *p = new double [100000000];
			goto nihao;
	}

	return 0;
}
