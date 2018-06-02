/*
题目描述
1、建立如下的类继承结构：

1)        定义一个人员类CPeople，其属性（保护类型）有：姓名、性别、年龄；

2)        从CPeople类派生出学生类CStudent，添加属性：学号和入学成绩；

3)        从CPeople类再派生出教师类CTeacher，添加属性：职务、部门；

4)        从CStudent和CTeacher类共同派生出在职研究生类CGradOnWork，添加属性：研究方向、导师；

2、分别定义以上类的构造函数、输出函数print及其他函数（如需要）。

3、在主函数中定义各种类的对象，并测试之。

输入
第一行：姓名性别年龄
第二行：学号成绩
第三行：职务部门
第四行：研究方向导师
输出
第一行：People:
第二行及以后各行：格式见Sample

样例输入
wang-li m 23
2012100365 92.5
assistant computer
robot zhao-jun

样例输出
People:
Name: wang-li
Sex: m
Age: 23

Student:
Name: wang-li
Sex: m
Age: 23
No.: 2012100365
Score: 92.5

Teacher:
Name: wang-li
Sex: m
Age: 23
Position: assistant
Department: computer

GradOnWork:
Name: wang-li
Sex: m
Age: 23
No.: 2012100365
Score: 92.5
Position: assistant
Department: computer
Direction: robot
Tutor: zhao-jun

*/
# include <iostream>
# include <string>
using namespace std;
class Person
{
protected:
	string name;
	char sex;
	int age;
public:
	Person()
	{
		name = "?\0";
		sex = '?';
		age = 0;
	}
	Person( string namae , char seibetsu , int nenrei )
	{
		name = namae;
		sex = seibetsu;
		age = nenrei;
	}
	void Display()
	{
		cout<<"Name: "<<name<<endl
			<<"Sex: "<<sex<<endl
			<<"Age: "<<age<<endl;
	}
};
class Student:virtual public Person
{
protected:
	int id;
	double enterScores;
public:
	Student():Person("?\0",'?',0)
	{
		id = 0;
		enterScores = 0;
	}
	Student( string namae , char seibetsu , int nenrei , int bango , double seiseki ):Person(namae,seibetsu,nenrei)
	{
		id = bango;
		enterScores = seiseki;
	}
	void Display()
	{
		Person::Display();		
		cout<<"No.: "<<id<<endl	
			<<"Score: "<<enterScores<<endl;		
	}
};
class Teacher:virtual public Person
{
protected:
	string position;
	string department;
public:
	Teacher():Person("?\0",'?',0)
	{
		position = "?\0";
		department = "?\0";
	}
	Teacher( string namae , char seibetsu , int nenrei , string shyokumu , string bumon ):Person(namae,seibetsu,nenrei)
	{
		position = shyokumu;
		department = bumon;
	}
	void Display()
	{
		Person::Display();		
		cout<<"Position: "<<position<<endl	
			<<"Department: "<<department<<endl;		
	}
};
class GraduateOnWork:public Student,public Teacher
{
private:
	string researchArea;
	string tutor;
public:
	GraduateOnWork():Student("?\0",'?',0,0,0),Teacher("?\0",'?',0,"?\0","?\0"),Person("?\0",'?',0)
	{
		researchArea = "?\0";
		tutor = "?\0";
	}
	GraduateOnWork(string namae, char seibetsu, int nenrei, int bango, double senseki, string shyokumu, string bumon, string kenkyuuhoukou, string shidoukyoukan ):Student(namae,seibetsu,nenrei,bango,senseki),Teacher(namae,seibetsu,nenrei,shyokumu,bumon),Person(namae,seibetsu,nenrei)
	{
		researchArea = kenkyuuhoukou;
		tutor = shidoukyoukan;
	}
};
int main()
{
	string namae;
	char seibetsu;
	int nenrei;

	int bango;
	double senseki;

	string shyokumu,bumon;

	string kenkyuuhoukou,shidoukyoukan;

	cin>>namae>>seibetsu>>nenrei
		>>bango>>senseki
		>>shyokumu>>bumon
		>>kenkyuuhoukou>>shidoukyoukan;

	cout<<"People:\n";
	Person hito(namae,seibetsu,nenrei);
	hito.Display();
	cout<<endl;

	cout<<"Student:\n";
	Student gakusei(namae,seibetsu,nenrei,bango,senseki);
	gakusei.Display();
	cout<<endl;

	cout<<"Teacher:\n";
	Teacher sensei(namae,seibetsu,nenrei,shyokumu,bumon);
	sensei.Display();
	cout<<endl;

	cout<<"GradOnWork:\n";
	GraduateOnWork kenkyuusei(namae,seibetsu,nenrei,bango,senseki,shyokumu,bumon,kenkyuuhoukou,shidoukyoukan);
	kenkyuusei.Display();
	cout<<endl;

	return 0;
}
