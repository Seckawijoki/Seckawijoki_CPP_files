/*
题目描述
下面是一个日期类的定义，请在类外实现其所有的方法，
并在主函数中生成对象测试之。
输入
测试数据的组数t
第一组测试数据的年 月 日
..........
输出
输出今天的日期
输出明天的日期

样例输入
4
2012 1 3
2012 2 28
2012 3 31
2012 4 30
样例输出
Today is 2012/01/03
Tomorrow is 2012/01/04
Today is 2012/02/28
Tomorrow is 2012/02/29
Today is 2012/03/31
Tomorrow is 2012/04/01
Today is 2012/04/30
Tomorrow is 2012/05/01
*/
# include <stdio.h>
# include <math.h>
class Date
{
private:
	int nen,getsu,nichi;
public:
	Date(){nen = 1900;getsu = 1;nichi = 1;}
	Date( int year , int month , int day );
	int getNen (){ return nen  ; }
	int getGetsu(){ return getsu ; }
	int getNichi(){ return nichi ; }
	void setDate( int year , int month , int day )
	{nen = year;getsu = month;nichi = day;}
	void kyou();
	void ashita();
};
//类定义与类实现分开。
void Date::kyou()
{
	int nen,getsu,nichi;
	nen = getNen();
	getsu = getGetsu();
	nichi = getNichi();
	     if ( getsu <  10 && nichi <  10 )
		printf("%d/0%d/0%d\n",nen,getsu,nichi);
	else if ( getsu <  10 && nichi >= 10 )
		printf("%d/0%d/%d\n" ,nen,getsu,nichi);
	else if ( getsu >= 10 && nichi <  10 )
		printf("%d/%d/0%d\n" ,nen,getsu,nichi);
	else
		printf("%d/%d/%d\n"  ,nen,getsu,nichi);
}
void Date::ashita()//直接动作。
{
	int nen,getsu,nichi;
	nen = getNen();
	getsu = getGetsu();
	nichi = getNichi();
	switch ( nichi )//先判断日，再月。
	{
		case 31://是否有12月。
		{
			if ( getsu == 12 ){setDate(nen+1,      1,1);break;}
			else			  {setDate(nen  ,getsu+1,1);break;}
		}
		case 30:
		{
			switch ( getsu )
			{
				case  4:
				case  6:
				case  9:
				case 11:{setDate(nen  ,getsu+1, 1);break;}
				case  1:
				case  3:
				case  5:
				case  7:
				case  8:	
				case 10:
				case 12:{setDate(nen  ,getsu  ,31);break;}
				default:break;
			}
			break;
		}
		case 29:
		{
			if ( getsu == 2 ){setDate(nen,getsu+1, 1);break;}
			else			 {setDate(nen,getsu  ,30);break;}
		}
		case 28:
		{
			if ( getsu == 2 )
			{
				if ( ( nen %4 == 0 && nen %100 != 0 )|| nen %400 == 0 )
					{	setDate(nen,getsu  ,     29);break;}
				else{	setDate(nen,getsu+1,      1);break;}
			}
			else	{	setDate(nen,getsu  ,     30);break;}
		}
		default:	{	setDate(nen,getsu  ,nichi+1);break;}
			//不是很规范的难则反~~
	}
}
int main()
{
	int y,m,d;
	int t;
	scanf("%d",&t);
	Date ngn;
	while ( t-- )
	{
		scanf("%d %d %d",&y,&m,&d);
		ngn.setDate(y,m,d);
		printf("Today is ");
		ngn.kyou();
		ngn.ashita();
		printf("Tomorrow is ");
		ngn.kyou();
	}
	return 0;
}
