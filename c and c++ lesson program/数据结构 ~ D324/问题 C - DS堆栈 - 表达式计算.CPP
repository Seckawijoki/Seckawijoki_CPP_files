/*
题目描述

计算一个表达式的运算结果
使用C++自带stack堆栈对象来实现
参考课本的伪代码，把伪代码改造成可运行的代码
课本伪代码请下载本附件：表达式伪c代码

例如
1. Push (OPTR, '#');表示把字符#压入堆栈OPTR中，
转换成c++代码就是OPTR.push('#');
2. Pop(OPND, a); 表示弹出栈OPND的栈顶元素，
并把栈顶元素放入变量a中。因此改成c++代码是两个操作：
   a = OPND.top();   OPND.pop();
3. a = GetTop(OPND)表示获取栈OPND的栈顶元素，
转成c++代码就是： a = OPND.top(); 

输入
第一个输入t，表示有t个实例
第二行起，每行输入一个表达式，每个表达式末尾带#表示结束
输入t行

输出
每行输出一个表达式的计算结果，计算结果用浮点数（含4位小数）的格式表示
用cout控制浮点数输出的小数位数，需要增加一个库文件，
并使用fixed和setprecision函数，代码如下：

#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	double temp = 12.34
	cout<<fixed<<setprecision(4)<<temp<<endl;
}
输出结果为12.3400

样例输入
2 1+2*3-4/5# (66+(((11+22)*2-33)/3+6)*2)-45.6789#

样例输出
6.2000 54.3211 
*/
# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <cstring>
# include <stack>
using namespace std;
# define OK        0
# define ERROR    -1
# define OVERFLOW -1
# define OPSETSIZE 7//运行算符号集合长度，目前只有7个符号
typedef int Status;
char Prior[7][7] = 
{//算符间的优先关系
	'>','>','<','<','<','>','>',
	'>','>','<','<','<','>','>',
	'>','>','>','>','<','>','>',
	'>','>','>','>','<','>','>',
	'<','<','<','<','<','=',' ',
	'>','>','>','>',' ','>','>',
	'<','<','<','<','<',' ','=',
};
float Operate( float a, unsigned char theta, float b );
char OPSET[OPSETSIZE] = 
{ '+', '-', '*', '/', '(', ')', '#'};

Status In( char Test, char *TestOp );//判断字符Test是否为运算符
char precede( char Aop, char Bop );
float EvaluateExpression( string expression )
{
	//算数表达式求值的算符优先算法
	//设OPTR和OPND分别为运算符栈和运算数栈，
	//OP为运算符集合
	stack <char>	OPTR;
	stack <double>	OPND;
	char TempData[20];
	double Data, a, b, r;
	char theta, Dr[2];
	char c;
	int i = 0;

	OPTR.push('#');
	c = expression[0];

	strcpy(TempData, "\0");
	while ( c != '#' || OPTR.top() != '#' )
	{
		if ( ! In(c, OPSET) )//读入的字符不是运算符，是一个数字
		{
			Dr[0] = c;
			Dr[1] = '\0';
			strcat(TempData, Dr);
			c = expression[++i];
			if ( In(c, OPSET) )
				//c是运算符，表明前面读入了一个完整操作数
				Data = (float) stof(TempData);
			OPND.push(Data);
			strcpy(TempData, "\0");
		}
		else
		{
			switch ( precede(OPTR.top(), c) )
			{
				case '<':break;
				case '=':break;
				case '>':break;
			}
		}
	}
}
int main()
{
	string expression;
	int t;
	double result;
	cin>>t;
	while ( t-- )
	{
		cin>>Exp;
		result = EvaluateExpression(expression);
		cout<<fixed<<setprecision(4)<<result<<endl;
	}
	return 0;
}