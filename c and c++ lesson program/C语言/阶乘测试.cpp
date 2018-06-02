# include <stdio.h>

int main(void)

{
	printf("请输入3个阶乘测试数：");
	int a,b,c,i,mul;
	scanf("%d %d %d",&a,&b,&c);

	i = 1;
	mul = 1;
	for ( i = 1 ; i <= a ; i++ )
	{	
		mul = mul * i;
	}
	printf("\n阶乘1结果：%d\n\n",mul);

	i = 1;
	mul = 1;
	for ( i = 1 ; i <= b ; i++ )
	{
		mul = mul * i;
	}
	printf("阶乘2结果：%d\n\n",mul);

	i = 1;
	mul = 1;
	for ( i = 1 ; i <= c ; i++ )
	{
		mul = mul * i;
	}
	printf("阶乘3结果：%d\n\n",mul);

	return 0;
}