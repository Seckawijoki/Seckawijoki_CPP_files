/*
��100g��ҩƷ������ƽ����������ֻ��1g��2g��5g��3�֣��ʣ� 
��Ҫ��ӵ���������Ϊ50�����м��ֲ�ͬ�ļӷ�����Ҫ������
Ϊ30���أ���������������⡣
*/
# include <stdio.h>
void sum( int x );
void main()
{
	int n;
	while ( 1 )
	{
		printf("��ѡ������������\n1.50��\n2.30��\n");
		scanf("%d",&n);
		if ( n == 1 )
			sum(50);
		else if ( n == 2 )
			sum(30);
		else
		{
			printf("��������\n��һ��");
			continue;
		}
	}
}

void sum( int x )
{
	int a,b,c;
	for ( c = 1 ; c <= 20 ; c++ )
		for ( b = 1 ; b <= 50 ; b++ )
			if ( x - 5 * c - 2 * b >= 0 )
				printf("%d��1g��%d��2g��%d��5g\n",x - 5 * c - 2 * b,b,c);
}