/*
题目描述
完成如下所示的CDate类中构造函数和其它成员函数的定义，
并编写程序实现按下列格式打印某个日期的功能：mm/dd/yyyy, 星期。
(提示：计算某个日期(day, month, year)为星期几的公式如下：
week = (day + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1;
其中，如果month实际为1或2,则计算时公式里month的值取13或14, 且year的值取其实际值减1的值）。

class CDate
{
public:
     void print();
     void getWeekofDay();
private:
        int month;
        int day;
        int year;
        int week;
};
输入
日期个数
第一个日期
第二个日期
.......

输出
日期1月/日期1日/日期1年, 日期1星期
日期2月/日期2日/日期2年, 日期2星期
......

样例输入
3
1949 10 1
2015 1 1
2011 11 11
样例输出
10/1/1949, Saturday
1/1/2015, Thursday
11/11/2011, Friday
*/
# include <stdio.h>
# include <string.h>
class Hizuke//日付(ひずけ)
{
private:
	int nen;
	int getsu;
	int nichi;
	int youbi;
public:
	Hizuke()
	{
		nen = 2015;
		getsu = 5;
		nichi = 9;
		youbi = 1;
	}
	Hizuke(int year,int month,int day)
	{
		nen = year;
		getsu = month;
		nichi = day;
	}
	void Toru(int year,int month,int day)
	{
		nen = year;
		getsu = month;
		nichi = day;
	}
	void ToruYoubi()
	{
		int month,year;
		     if ( getsu == 1 )
		{
			month = 13;
			year = nen - 1;
		}
		else if ( getsu == 2 )
		{
			month = 14;
			year = nen - 1;
		}
		else 
		{
			month = getsu;
			year = nen;
		}
		youbi = (nichi + 2*month + 3*(month+1)/5 + year + year/4 - year/100 + year/400) % 7 + 1;
	}
	void Miseru()
	{
		char nanyoubi[10];
		switch ( youbi )
		{
		case 1 : strcpy(nanyoubi,"Monday\0");   break;
		case 2 : strcpy(nanyoubi,"Tuseday\0");  break;
		case 3 : strcpy(nanyoubi,"Wednesday\0");break;
		case 4 : strcpy(nanyoubi,"Thursday\0"); break;
		case 5 : strcpy(nanyoubi,"Friday\0");   break;
		case 6 : strcpy(nanyoubi,"Saturday\0"); break;
		case 7 : strcpy(nanyoubi,"Sunday\0");   break;
		default:break;
		}
		printf("%d/%d/%d, %s\n",getsu,nichi,nen,nanyoubi);
	}
};
int main()
{
	int t,year,month,day;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d%d",&year,&month,&day);
		Hizuke date(year,month,day);
		date.ToruYoubi();
		date.Miseru();
	}
	return 0;
}