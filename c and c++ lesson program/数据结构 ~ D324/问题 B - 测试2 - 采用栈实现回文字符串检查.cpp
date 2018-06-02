# include <iostream>
# include <string>
# include <stack>
using namespace std;
# define OK     1
# define ERROR -1
int main()
{
	int t;
	cin>>t;
	while ( t-- )
	{
		stack <char> room1, room2;
		string patient;
		int i, length, daijoubu = OK;
		cin>>patient;
		length = patient.length();
		for ( i = 0 ; i < length ; ++i )
			room1.push(patient[i]);
		for ( i = 0 ; i < length / 2 ; ++i )
		{
			room2.push(room1.top());
			room1.pop();
		}
		if ( length %2 )
			room1.pop();
		while ( !room1.empty() && !room2.empty() )
		{
			if ( room1.top() != room2.top() )
			{
				daijoubu = ERROR;
				break;
			}
			else
			{
				room1.pop();
				room2.pop();
			}
		}
		cout<<( daijoubu == OK ? OK : ERROR )<<endl;
	}
	return 0;
}
/*
题目描述
1、问题描述
给出一个字符串，采用栈，检查是否是回文字符串

2、算法
回文字符串：从左到右读和从右到左读完全一样，比如"level" 、 “aaabbaaa”
选将所有字符，逐个压入栈（Push），然后，再将字符（第一个开始），与栈中弹出的字符相比较，如果，所有字符相同，则是回文，否则不是。


输入
第1行：样本数目n
第2行：第一个字符串样本
 ：
第n+1行：第n个字符串样本


输出
每个测试1行
是回文，则输出1，否则输出-1


样例输入
5
abcddcba
1234554321
12abcba12
3210123
32110123

样例输出
1
1
-1
1
-1

*/
