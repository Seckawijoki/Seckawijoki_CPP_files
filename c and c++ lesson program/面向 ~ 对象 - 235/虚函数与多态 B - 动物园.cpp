/*
题目描述

某个动物园内，有老虎、狗、鸭子和猪等动物，
动物园的管理员为每个动物都起了一个名字，
并且每个动物都有年龄、体重等信息。每到喂食的时候，
不同的动物都会叫唤(speak)。每种动物的叫唤声均不同，
老虎的叫唤声是“AOOO”，狗的叫唤声是“WangWang”，
鸭子的叫唤声是“GAGA”，猪的叫唤声是“HENGHENG”。

定义一个Animal的基类，Animal类有函数Speak()，
并派生老虎、狗、鸭子和猪类，其能发出不同的叫唤声（用文本信息输出叫声）。

编写程序，输入动物名称、名字、年龄，让动物园内的各种动物叫唤。
要求：只使用一个基类指针，指向生成的对象并调用方法。

输入
测试案例的个数
第一种动物的名称  名字 年龄
第二种动物的名称  名字 年龄
......

输出
输出相应动物的信息
如果不存在该种动物，输出“There are no Rabbit in our Zoo.”

样例输入
4
Tiger Jumpjump 10
Pig Piglet 4
Rabbit labi 3
Duck tanglaoya 8

样例输出
Hello,I am Jumpjump,AOOO.
Hello,I am Piglet,HENGHENG.
There are no Rabbit in our Zoo.
Hello,I am tanglaoya,GAGA.
*/
# include <iostream>
# include <string>
using namespace std;
class AnAnimal
{
protected:
	string name;
	int age;
public:
	AnAnimal()
	{
		name = "?\0";
		age = 0;
	}
	AnAnimal( string namae, int nenrei )
	{
		name = namae;
		age = nenrei;
	}
	virtual void Speaking() = 0;
};
class ATiger:virtual public AnAnimal
{
public:
	ATiger():AnAnimal("?\0",0)
	{}
	ATiger(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",AOOO.\n";		
	}
};
class APig:virtual public AnAnimal
{
public:
	APig():AnAnimal("?\0",0)
	{}
	APig(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG.\n";		
	}
};
class ADuck:virtual public AnAnimal
{
public:
	ADuck():AnAnimal("?\0",0)
	{}
	ADuck(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",GAGA.\n";		
	}
};
class ADog:virtual public AnAnimal
{
public:
	ADog():AnAnimal("?\0",0)
	{}
	ADog(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",WangWang.\n";		
	}
};
int main()
{
	int t,nenrei;
	string taipu,namae;
	cin>>t;
	AnAnimal *theLittleOne;
	while ( t-- )
	{
		cin>>taipu>>namae>>nenrei;
		if ( taipu == "Tiger" )
		{
			ATiger theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else if ( taipu == "Pig" )
		{
			APig theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else if ( taipu == "Duck" )
		{
			ADuck theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else if ( taipu == "Dog" )
		{
			ADog theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else
			cout<<"There is no "<<taipu<<" in our Zoo.\n";
	}
	return 0;
}
