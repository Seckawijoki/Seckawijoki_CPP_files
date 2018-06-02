/*
题目描述
定义一个学生类Student，包含该学生的姓名、出生年、月、日 ，
重定义 “-”号实现两个学生之间相差多少天的比较。
并利用重载的“-”运算符，求所有学生中年龄相差最大的两个人的名字以及相差天数。

输入
第一行：输入所需要输入的学生个数；
第二行开始，依次输入每个学生的姓名、出生年、月、日。

输出
输出年龄相差最大的两个人的名字以及相差天数。

样例输入
3
Tom 1995 1 1
Joe 1995 2 28
Jimmy 1996 1 8

3
aaaaaa 1996 2 29
cccccc 1996 3 1
dddddd 1997 2 28

样例输出
Tom和Jimmy年龄相差最大，为372天。
*/
# include <iostream>
# include <string>
# include <cmath>
using namespace std;
class Student;
int CalculatingDaysOfDate( Student & , int );
int CalculatingLeapYear( int start , int end );
int abstract( int );
class Student
{
private:
	string name;
	int year;
	int month;
	int day;
public:
	Student()
	{
		name = '\0';
		year = 1;
		month = 1;
		day = 1;
	}
	Student( string n, int y = 0, int m = 0, int d = 0 )
	{
		name = n;
		year = y;
		month = m;
		day = d;
	}
	void SetNameYearMonthDay( string n = NULL, int y = 0, int m = 0, int d = 0 )
	{
		name = n;
		year = y;
		month = m;
		day = d;
	}
	string GetName()
	{
		return name;
	}
	int operator - ( Student &obj )
	{
		int start;
		if ( year <= obj.year )
			start = year;
		else 
			start = obj.year;
		return abstract( CalculatingDaysOfDate(*this,start) - CalculatingDaysOfDate(obj,start) );
	}
	friend int CalculatingDaysOfDate( Student & , int );
	friend int CalculatingLeapYear( int start , int end );
	friend int abstract( int );
};
int CalculatingDaysOfDate( Student &obj , int start )
{
	int y = obj.year;
	int m = obj.month;
	int d = obj.day;
	int sum = ( m - 1 ) * 28 + d;
	switch ( m - 1 )
	{
	case 1 :sum +=  3;break;
	case 2 :sum +=  3;break;
	case 3 :sum +=  6;break;
	case 4 :sum +=  8;break;
	case 5 :sum += 11;break;
	case 6 :sum += 13;break;
	case 7 :sum += 16;break;
	case 8 :sum += 19;break;
	case 9 :sum += 21;break;
	case 10:sum += 24;break;
	case 11:sum += 26;break;
	default:break;
	}
	if ( m == 2 && d == 29 )
		sum++;
	if ( m > 2 )
	{
		if ( y %400 == 0 || ( y %4 == 0 && y %100 != 0 ) )
			sum += 2;
	}
	sum += ( y - start ) * 365 + CalculatingLeapYear(start,y);
	sum--;
//	cout<<y<<'.'<<m<<'.'<<d<<"的天数是"<<sum<<endl;
	return sum;
}
int CalculatingLeapYear( int start , int end )
{
	int i,number = 0;
	for ( i = start ; i < end ; i++ )
		if ( i %400 == 0 || ( i %4 == 0 && i %100 != 0 ) )
			number++;
	return number;
}
int abstract( int x )
{
	return ( x > 0 ? x : -x );
}
int main()
{
	int t,i,j;
	int **days,max = 0,u,v;
	Student *gakusei;
	string n;
	int y,m,d;
	cin>>t;
	gakusei = new Student [t];
	days = new int *[t];
	for ( i = 0 ; i < t ; i++ )
		days[i] = new int [t];
	for ( i = 0 ; i < t ; i++ )
	{
		cin>>n>>y>>m>>d;
		gakusei[i].SetNameYearMonthDay(n,y,m,d);
	}
	for ( i = 0 ; i < t ; i++ )
	{
		for ( j = i + 1 ; j < t ; j++ )
		{
			days[i][j] = abstract( gakusei[i] - gakusei[j] );
			if ( max < days[i][j] )
			{
				u = i;
				v = j;
				max = days[i][j];
			}
//			cout<<"days["<<i+1<<"]["<<j+1<<"] = "<<days[i][j]<<endl;
		}
	}
	cout<<gakusei[u].GetName()<<"和"<<gakusei[v].GetName()
		<<"年龄相差最大，为"<<max<<"天。\n";
	delete [] days;
	delete [] gakusei;
	return 0;
}