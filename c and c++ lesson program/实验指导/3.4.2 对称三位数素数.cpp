# include <iostream.h>
# include <iomanip.h>
# include <cstdio>
# include <math.h>
int main()
{
	int x;
	printf("������һЩ��λ�������ж������Ƿ�Ϊ�Գ���λ��������");
	int prime( int x );
	while ( 1 )
	{
		scanf("%d",&x);
		if ( x / 100 != 0 && x / 100 == x %10 )
			prime(x);
		else
			printf("NO������׼�ĶԳ���λ������\n");
	}
	return 0;
}
//	���˺ܶ�2��
int prime( int x )
{
	int i,y;
	if ( x %2 == 0 )
		printf("NO��������������������\n");
	else
	{
		y = sqrt(x);//������������������
		for ( i = 3 ; i <= y ; i = i + 2 )//������ż����
		{
			if ( x %i == 0 )
			{
				printf("No��������������\n");
				break;
			}
		}
		if ( x %i != 0 )
			printf("Yes���ǶԳ���λ����������\n");
	}
	return 1;
}
