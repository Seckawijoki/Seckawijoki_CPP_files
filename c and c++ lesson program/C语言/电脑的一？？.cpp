# include <stdio.h>
# include <time.h>
int main()
{
	int s,min,h,day,week,z;
	s = min = h = 0;
	day = week = 1;
	clock_t start,end;
	printf("输入回车键来让电脑经历人类的一个月吧。");
	if ( getchar() == '\n' )
	{
		start = clock();
		while ( week <= 4 )
		{
			printf("第%d周：星期%d： %d时：%d分：%d秒\n",week,day,h,min,s);
			s++;
			s >= 60   ?  min++ , s -= 60   : 1 ;
			min >= 60 ?    h++ , min -= 60 : 1 ;
			h >= 24   ?  day++ , h -= 24   : 1 ;
			day >= 8  ? week++ , day -= 7  : 1 ;

		}
		end = clock();
	}
	z = (end-start)/1000;
	printf("哇，电脑一共运行了%d次\n",z*1000);//58秒刷完了一周。
	printf("电脑用了%d时：%d分：%d秒时间过了人类一个月的生活！！\n",z/3600,(z%3600)/60,z%60);
	return 0;
}
