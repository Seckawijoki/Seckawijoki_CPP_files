# include <stdio.h>

int main(void)
{
	int n;
	int sum( int n );
	printf("�ֶ�����1 + 2 + 3 + ���� + ( n - 1 )+ n��͡�\n");
	printf("������n��ֵ��");
	while ( 1 )
	{
		scanf("%d",&n);
		printf("����1 + 2 + 3 + ���� + %d + %d = %d\n", n - 1 , n , sum(n));
		printf("\n�����ظ���ͣ�n = ");
	}
	return 0;
}
int sum( int n )//�Ե��������á�
{
	if ( n == 1 )
		return 1;
	return sum( n - 1 ) + n;
}