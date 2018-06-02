/*
题目描述
编写程序，实现某旅馆的客人住宿记录功能。

定义一个Customer类，要求输入客人的姓名，
创建一个Customer对象。类声明如下：

调用类的Display函数输出客人ID
（输出顺序号占4位，如第1位为0001，第2位为0002，
依此类推）、姓名、总人数。
总人数和客人租金用静态成员，
其他属性采用普通的数据成员。
<!--[endif]--> 
<!--[if !supportAnnotations]-->
<!--[endif]-->

输入
输入测试次数t
对于每次测试，首先输入当前年份，
接下来依次输入顾客姓名，0表示输入结束。

输出
每行依次输出顾客信息和旅馆信息。
包括顾客姓名，顾客编号，
旅馆入住总人数，旅馆当前总收入。

样例输入
2
2014
张三 李四 王五 0
2015
Cindy David 0
样例输出
张三 20140001 1 150
李四 20140002 2 300
王五 20140003 3 450
Cindy 20150004 4 600
David 20150005 5 750
*/
# include <iostream>
# include <iomanip>
# include <cstring>
using namespace std;
class Customer
{
private:
	static int TheNumberOfCustomers;
	static int Rent;
	static int LodgingYear;
	int ID;
	char *NameOfCustomer;
public:
	Customer()
	{
		ID = 0;
	}
	Customer( char *name )
	{
		NameOfCustomer = new char [strlen(name)+1];
		strcpy(NameOfCustomer,name);
		ID = TheNumberOfCustomers + 1;
	}
	~Customer()
	{
		delete [] NameOfCustomer;
	}
	static void AdditionOfLodgingYear( int year )
	{
		LodgingYear = year;
	}
	static void AdditionOfRent( int rent )
	{
		Rent += rent;
	}
	static void AdditionOfNumber()
	{
		TheNumberOfCustomers++;
	}
	void Display()
	{
		cout<<NameOfCustomer<<' '
			<<LodgingYear
			<<setw(4)<<setfill('0')<<ID<<' '
			<<ID<<' '
			<<Rent<<endl;
	}
};
int Customer::TheNumberOfCustomers = 0;
int Customer::Rent = 0;
int Customer::LodgingYear = 0;
int main()
{
	int t,year;
	char name[88] = "imputing\0";
	cin>>t;
	while ( t-- )
	{
		cin>>year;
		do
		{
			cin>>name;
			if ( name[0] != '0' )
			{
				Customer guest(name);
				Customer::AdditionOfLodgingYear(year);
				Customer::AdditionOfRent(150);
				Customer::AdditionOfNumber();
				guest.Display();
			}
			else 
				break;
		}
		while( name[0] != '0' );
	}
	return 0;
}

