/*
题目描述
1、问题描述
一个算术表达式中包括圆括号、方括号和花括号三种形式的括号
编程实现判别表达式中括号是否正确匹配的算法

2、算法
顺序扫描算术表达式
若算术表达式扫描完成，此时如果栈空，则正确返回(0)；如果栈未空，说明左括号多于右括号，返回(-3)
从算术表达式中取出一个字符，如果是左括号(‘(‘或‘[‘或 ‘{‘)，则让该括号进栈(PUSH)
如果是右括号(‘)‘或‘]‘或 ‘}‘)：
⑴、如果栈为空，则说明右括号多于左括号，返回(-2)
⑵、如果栈不为空，则从栈顶弹出(POP)一个括号： 若括号匹配，则转1继续进行判断；否则，说明左右括号配对次序不正确，返回(-1)

输入
第一行：样本个数，假设为n。
第二到n+1行，每一行是一个样本（算术表达式串），共n个测试样本。


输出
共有n行，每一行是一个测试结果，有四种结果：
0：左右括号匹配正确  {[(1+2)*3]-1}
-1：左右括号配对次序不正确 {[(1+2]*3)-1}
-2：右括号多于左括号  (1+2)*3)-1}
-3：左括号多于右括号  {[(1+2)*3-1]

样例输入
4
{[(1+2)*3]-1}
{[(1+2]*3)-1}
(1+2)*3)-1}
{[(1+2)*3-1]

样例输出
0
-1
-2
-3
*/
# include <iostream>
# include <string>
# include <stack>
using namespace std;
int SequencialScanning( string conner )
{
	int i, n, length;
	stack <char> storage;
	length = conner.length();
	for ( i = 0 ; i < length ; ++i )
	{
		if ( conner[i] == '[' || 
		     conner[i] == '{' || 
		 	 conner[i] == '(' )
			storage.push(conner[i]);
		else if ( conner[i] == ']' )
		{
			if ( storage.empty() )
				return -2;
			else if ( storage.top() == '(' || storage.top() == '{' )
				return -1;
			else if ( storage.top() == '[' )
				storage.pop();
		}
		else if ( conner[i] == '}' )
		{
			if ( storage.empty() )
				return -2;
			else if ( storage.top() == '(' || storage.top() == '[' )
				return -1;
			else if ( storage.top() == '{' )
				storage.pop();
		}
		else if ( conner[i] == ')' )
		{
			if ( storage.empty() )
				return -2;
			else if ( storage.top() == '[' || storage.top() == '{' )
				return -1;
			else if ( storage.top() == '(' )
				storage.pop();
		}
	}
	if ( storage.empty() )
		return 0;
	else
		return -3;
}
int main()
{
	int n;
	string expression;
	cin>>n;
	while ( n-- )
	{
		cin>>expression;
		cout<<SequencialScanning(expression)<<endl;
	}
	return 0;
}
