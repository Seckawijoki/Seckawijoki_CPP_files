/*
题目描述
面向对象程序设计的中心就是把客观事物抽象为程序世界里一段段代码，
校园里的主体是学生，泛泛的学生包含很多属性，
比如姓名、学号、所在学院、专业、性别、住址、联系电话等等，
有这些属性，需要操纵它们的动作，
比如读取姓名、设置姓名、读取学号、设置学号等等，
这就是我们课堂说的属性和方法，
对于属性和方法，我们又有访问控制方式限制，
标示为public、private、protected等，
根据以上的信息，请给出一个完整的学生类定义：Student，
并测试输出n个该类对象的各项属性值。

输入
第一行表示要输入n个对象
后续各行输入不同对象的各属性值，每个对象一行。

输出
输出不同对象的各自属性

每个对象占一行

样例输入
2
WangHai 2014150112 计算机 计算机科学与技术 男 南区215 13760222222
LiBin 2013151292 计算机 软件工程 男 南区318 13677777777
样例输出
WangHai 2014150112 计算机 计算机科学与技术 男 南区215 13760222222
LiBin 2013151292 计算机 软件工程 男 南区318 13677777777
*/
# include <iostream>
# include <string>
using namespace std;
class Gakusei
{
private:
	/*
	使用下面格式，可以使用string来定义字符串：
	# include <iostream>
	# include <string>
	using namespace std;
	*/
	string namae,gakuseinoban,gakuin,senmon,seibetsu,juusho,denwabango;
	//専門(せんもん)
public:
	Gakusei(string name, string number, string academy, string speciality, string sex, string address, string phone )
	{
		//对于string类字符串，可直接等号计算。
		namae = name;
		gakuseinoban = number;
		gakuin = academy;
		senmon = speciality;
		seibetsu = sex;
		juusho = address;
		denwabango = phone;
	}
	void miseru()
	{
		//用C++方便输出。
		cout<<namae<<' '
			<<gakuseinoban<<' '
			<<gakuin<<' '
			<<senmon<<' '
			<<seibetsu<<' '
			<<juusho<<' '
			<<denwabango<<'\n';
	}
};
int main()
{
	int t;
	string namae,gakuseinoban,gakuin,senmon,seibetsu,juusho,denwabango;
	cin>>t;
	while ( t-- )
	{
		//用C++方便输入。
		cin>>namae>>gakuseinoban>>gakuin>>senmon>>seibetsu>>juusho>>denwabango;
		Gakusei dareka(namae,gakuseinoban,gakuin,senmon,seibetsu,juusho,denwabango);
		dareka.miseru();
	}
	return 0;
}