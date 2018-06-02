/*
题目描述
前面几道练习，估计大家都是把所有代码放在一个文件里一起实现，
这也就是我们说的类的界面和类的实现合二为一的方式，
对于短小的程序来说效率是不错的，但是对于较大的项目来说，
不利于可读性，在“指针对象练习”基础上，
在VC环境下我们把原来的程序分成两部分，一个是界面（.h文件），
一个是实现（.cpp文件），当然，为了和OJ环境一致，
在一个程序结构里，需要把类界面和类实现在一个文件里分开两部分来实现，
本题的基本要求和“指针对象”一样，唯一要求不同的是程序的结构不一致，
批改的标准是在结果正确基础上对照看提交的原始程序代码！

输入
第一行输入n个对象实例
后面各行依次输入对象的各属性

输出
每行输出经过排序后对象的姓名属性

样例输入
2
Bob 男 2012222222 计算机学院 13777777777
Alice 女 2013333333 计算机学院 13888888888

样例输出
Alice
Bob
*/
# include <iostream>
# include <string>//此头文件用于创建string类型
using namespace std;
class Gakusei
{
private:
	string namae;
	string seibetsu;//性别：sex,性别(せいべつ)
	string bango;
	string gakuin;//学院：sex,学院(がくいん)
	string denwa;
public:
	Gakusei()
	{
		namae = "No name\0";
		seibetsu = "Unknown\0";
		bango = "0000000000\0";
		gakuin = "Unknown\0";
		denwa = "00000000000\0";
	}
	Gakusei(string name,string sex,string number,string academy,string phone)
	{
		namae = name;
		seibetsu = sex;
		bango = number;
		gakuin = academy;
		denwa = phone;
	}
	void Toru(string name,string sex,string number,string academy,string phone)
	{
		namae = name;
		seibetsu = sex;
		bango = number;
		gakuin = academy;
		denwa = phone;
	}
	Gakusei( Gakusei &copy )
	{
		namae = copy.namae;
		seibetsu = copy.seibetsu;
		bango = copy.bango;
		gakuin = copy.gakuin;
		denwa = copy.denwa;
	}
	void Ranking( Gakusei &rgks );
	void Miseru();
};
void Gakusei::Ranking( Gakusei &rgks )
{
	Gakusei kopii;
	if ( namae[0] > rgks.namae[0] )
	{
		kopii = rgks;
		rgks.Toru(namae,seibetsu,bango,gakuin,denwa);
			namae = kopii.namae;
			seibetsu = kopii.seibetsu;
			bango = kopii.bango;
			gakuin = kopii.gakuin;
			denwa = kopii.denwa;
	}
}
void Gakusei::Miseru()
{
	cout<<namae<<endl;
}
int main()
{
	int i,j,t;
	string name,sex,number,academy,phone;
	cin>>t;
	Gakusei *student;
	student = new Gakusei [t];
	for ( i = 0 ; i < t ; i++ )
	{
		cin>>name>>sex>>number>>academy>>phone;
		student[i].Toru(name,sex,number,academy,phone);
	}
	for ( i = 0 ; i < t ; i++ )
		for ( j = i + 1 ; j < t ; j++ )
			student[i].Ranking( student[j] );
	for ( i = 0 ; i < t ; i++ )
		student[i].Miseru();
	delete [] student;
	return 0;
}