# include <stdio.h>

int main(void)

{
	printf("������3���׳˲�������");
	int a,b,c,i,mul;
	scanf("%d %d %d",&a,&b,&c);

	i = 1;
	mul = 1;
	for ( i = 1 ; i <= a ; i++ )
	{	
		mul = mul * i;
	}
	printf("\n�׳�1�����%d\n\n",mul);

	i = 1;
	mul = 1;
	for ( i = 1 ; i <= b ; i++ )
	{
		mul = mul * i;
	}
	printf("�׳�2�����%d\n\n",mul);

	i = 1;
	mul = 1;
	for ( i = 1 ; i <= c ; i++ )
	{
		mul = mul * i;
	}
	printf("�׳�3�����%d\n\n",mul);

	return 0;
}