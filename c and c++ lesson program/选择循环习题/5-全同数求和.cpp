/*
5. ��д������a+aa+aaa+��+aa��a,����a��һ�����֡����磺 
3+33+333+3333+33333����ʱnΪ5����Ҫ��a��n�Ӽ������룬
�����ʽΪ3+33+333+3333+33333=37035��
*/
# include <stdio.h>
# include <math.h>
void sum( int a , int n );
void main()
{
	int a,n;
	printf("����a+aa+aaa+...+aa...a��n��֮�͡�\n");
	printf("��ֱ�����a��n��ֵ��");
	while ( 1 )
	{
		scanf("%d %d",&a,&n);
		if ( a > 0 && a < 10 )
			sum( a , n );
		else
			printf("�����������������룺");	
	}
}
void sum( int a , int n )
{
	int i,b = 0;
	long s = 0;
	for ( i = 0 ; i < n ; i++ )
	{
		b += a * pow( 10 , i );
		s += b;
		i ? printf("+%d",b) : printf("%d",b);
	}
	printf("=%ld\n",s);
}