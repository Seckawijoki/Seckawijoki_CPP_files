# include <stdio.h>
# include <time.h>
int main()
{
	int s,min,h,day,week,z;
	s = min = h = 0;
	day = week = 1;
	clock_t start,end;
	printf("����س������õ��Ծ��������һ���°ɡ�");
	if ( getchar() == '\n' )
	{
		start = clock();
		while ( week <= 4 )
		{
			printf("��%d�ܣ�����%d�� %dʱ��%d�֣�%d��\n",week,day,h,min,s);
			s++;
			s >= 60   ?  min++ , s -= 60   : 1 ;
			min >= 60 ?    h++ , min -= 60 : 1 ;
			h >= 24   ?  day++ , h -= 24   : 1 ;
			day >= 8  ? week++ , day -= 7  : 1 ;

		}
		end = clock();
	}
	z = (end-start)/1000;
	printf("�ۣ�����һ��������%d��\n",z*1000);//58��ˢ����һ�ܡ�
	printf("��������%dʱ��%d�֣�%d��ʱ���������һ���µ������\n",z/3600,(z%3600)/60,z%60);
	return 0;
}
