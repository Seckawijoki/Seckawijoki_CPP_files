/*
题目描述
1、建立如下的类继承结构：
1)一个车类CVehicle作为基类，具有max_speed、speed、weight等数据成员，display()等成员函数
2)从CVehicle类派生出自行车类CBicycle，添加属性：高度height
3)从CVehicle类派生出汽车类CMotocar，添加属性：座位数seat_num
4)从CBicycle和CMotocar派生出摩托车类CMotocycle
2、分别定义以上类的构造函数、输出函数display及其他函数（如需要）。
3、在主函数中定义各种类的对象，并测试之，通过对象调用display函数产生输出。

输入
第一行：最高速度 速度 重量 
第二行：高度 
第三行：座位数

输出
第一行：Vehicle: 
第二行及以后各行：格式见Sample

样例输入
100 60 20
28
2

样例输出
Vehicle:
max_speed:100
speed:60
weight:20

Bicycle:
max_speed:100
speed:60
weight:20
height:28

Motocar:
max_speed:100
speed:60
weight:20
seat_num:2

Motocycle:
max_speed:100
speed:60
weight:20
height:28
seat_num:2
*/
# include <iostream>
# include <string>
using namespace std;
class Vehicle
{
protected:
	double topSpeed;
	double speed;
	double weight;
public:
	Vehicle()
	{
		topSpeed = 999;
		speed = 0;
		weight = 0;
	}
	Vehicle( double saikousokudo , double sokudo , double juuryou )
	{
		topSpeed = saikousokudo;
		speed = sokudo;
		weight = juuryou;
	}
	void Display()
	{
		cout<<"Vehicle:\n"
			<<"max_speed:"<<topSpeed<<endl
			<<"speed:"<<speed<<endl
			<<"weight:"<<weight<<endl<<endl;
	}
};
class Bicycle:virtual public Vehicle
{
protected:
	double height;
public:
	Bicycle():Vehicle(999,0,0)
	{
		height = 0;
	}
	Bicycle(double saikousokudo, double sokudo, double juuryou, double koudo):Vehicle(saikousokudo,sokudo,juuryou)
	{
		height = koudo;
	}
	void Display()
	{
		cout<<"Bicycle:\n"
			<<"max_speed:"<<topSpeed<<endl
			<<"speed:"<<speed<<endl
			<<"weight:"<<weight<<endl
			<<"height:"<<height<<endl<<endl;
	}
};
class Car:virtual public Vehicle
{
protected:
	double seat;
public:
	Car():Vehicle(999,0,0)
	{
		seat = 0;
	}
	Car(double saikousokudo, double sokudo, double juuryou, double seki):Vehicle(saikousokudo,sokudo,juuryou)
	{
		seat = seki;
	}
	void Display()
	{
		cout<<"Motocar:\n"
			<<"max_speed:"<<topSpeed<<endl
			<<"speed:"<<speed<<endl
			<<"weight:"<<weight<<endl
			<<"seat_num:"<<seat<<endl<<endl;
	}
};
class Motorcycle:public Bicycle,public Car
{
public:
	Motorcycle():Vehicle(999,0,0),Bicycle(999,0,0,0),Car(999,0,0,0)
	{}
	Motorcycle(double saikousokudo, double sokudo, double juuryou, double koudo, double seki):Vehicle(saikousokudo,sokudo,juuryou),Bicycle(saikousokudo,sokudo,juuryou,koudo),Car(saikousokudo,sokudo,juuryou,seki)
	{}
	void Display()
	{
		cout<<"Motocycle:\n"
			<<"max_speed:"<<topSpeed<<endl
			<<"speed:"<<speed<<endl
			<<"weight:"<<weight<<endl
			<<"height:"<<height<<endl
			<<"seat_num:"<<seat<<endl<<endl;
	}
};
int main()
{
	double saikousokudo,sokudo,juuryou;
	double koudo;
	double seki;

	cin>>saikousokudo>>sokudo>>juuryou
		>>koudo
		>>seki;

	Vehicle koutsuukikan(saikousokudo,sokudo,juuryou);
	koutsuukikan.Display();

	Bicycle jitenshya(saikousokudo,sokudo,juuryou,koudo);
	jitenshya.Display();

	Car jidoushya(saikousokudo,sokudo,juuryou,seki);
	jidoushya.Display();

	Motorcycle baiku(saikousokudo,sokudo,juuryou,koudo,seki);
	baiku.Display();

	return 0;
}
