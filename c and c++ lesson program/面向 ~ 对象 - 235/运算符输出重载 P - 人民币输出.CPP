/*
题目描述
定义一个人民币类，包括元、角、分三个非负整数属性，操作包括初始化和输出
初始化用构造函数实现，
接收一个浮点数参数（精度为小数点后两位），
并转化为元、角、分，例如输入1.23元，
经过构造函数转为1元、2角、3分

输出函数对元角分进行输出，具体格式看示例

由于VC重载输出运算符有问题，VC能通过但OJ编译不过，
所以建议大家在DevC++下编程，用友元方法或者全局函数重载的方法，会比较顺利

由于OJ编译器对double强制类型转换成int的处理精度有偏差，
建议使用floor函数进行取整操作，此函数需要包含math.h头文件


输入
第一行输入t表示有t个实例
第二行起，输入t个正浮点数，带两位小数，每个数值表示以元为单位的人民币金额

输出
每行输出把浮点数的人民币金额，转化为元角分的整数格式，具体看输出

样例输入
2
2.45
1.38

样例输出
yuan=2 jiao=4 fen=5
yuan=1 jiao=3 fen=8
*/
# include <iostream>
using namespace std;
class Renminbi
{
private:
	unsigned int yuan;
	unsigned int jiao;
	unsigned int fen;
public:
	Renminbi()
	{
		yuan = 0;
		jiao = 0;
		fen = 0;
	}
	Renminbi( float qian )
	{
		unsigned int rmb =  ( qian + 0.005 ) * 100 ;
		yuan = rmb / 100;
		jiao = ( rmb / 10 ) %10;
		fen = rmb %10;
	}
	friend ostream & operator << ( ostream & , Renminbi & );
};
ostream & operator << ( ostream &stream , Renminbi &rmb )
{
	stream<<"yuan="<<rmb.yuan
		<<" jiao="<<rmb.jiao
		<<" fen="<<rmb.fen;
	return stream;
}
int main()
{
	int t;
	float yinliang;
	cin>>t;
	while ( t-- )
	{
		cin>>yinliang;
		Renminbi qian(yinliang);
		cout<<qian<<endl;
	}
	return 0;	
}
