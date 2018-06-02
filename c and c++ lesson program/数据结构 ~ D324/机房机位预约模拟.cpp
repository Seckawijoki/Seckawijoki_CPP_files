/*
2.机房机位预约模拟
某机房有20台机器,上机时间安排是从早8点到晚8点,
每两个小时一个时间段,现要求编写一程序,实现功能如下: 
(1)查询：根据输入时间,输出机位信息
(2)机位预定:根据输入的日期和时间段,查询是否有空机位。
若有，则预约；若无，则提供最近空机时间段。
另: 若用户要求在非空时间上机，
则将用户信息(学号、姓名和联系方式)插入该时间段的等待列表。
(3)退出预定: 根据输入的时间，撤销该时间的预订,
查询是否有等待信息，若有，则按顺序显示联系方式。
*/
# include <iostream>
using namespace std;
class Machine
{
public:
	int number;//电脑号码
	int busy;//是否在用
};
class BookingComputer
{
private:
	Machine computer;
	string name;
	long id;
	long phone;
};