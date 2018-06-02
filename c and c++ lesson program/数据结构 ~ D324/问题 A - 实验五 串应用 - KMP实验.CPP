# include <iostream>
# include <string>
using namespace std;
void Get_NextValue( string model, int next[] )
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while ( i < model[0] )
	{
		if ( j == 0 || model[i] == model[j] )
		{
			++i;
			++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
}
int Index_KMP( string primary, string secondary )
{
	int i = 1;
	int j = 1;
	int *next = new int [secondary.length()];
	Get_NextValue(secondary, next);
	for ( int k = 0 ; k < secondary.length() ; ++k )
		cout<<next[k]<<' ';
	cout<<endl;
	while ( i < primary[0] && j < secondary[0] )
	{
		if ( j == 0 || primary[0] || primary[0] == secondary[0] )
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if ( j > secondary[0] )
		return i-secondary[0];
	else
		return -1;
}
int main()
{
	int n, i;
	string one, two;
	string chief, vice;
	cin>>n;
	while ( n-- )
	{
		cin>>one>>two;
		vice[0] = one.length();
		for ( i = 0 ; i < vice[0] ; ++i )
			vice[1+i] = one[i];
		chief[0] = two.length();
		for ( i = 0 ; i < chief[0] ; ++i )
			chief[1+i] = two[i];
		cout<<Index_KMP(chief,vice)<<endl;
	}
	return 0;
}
/*
题目描述

1、问题描述
在主串MainString中，从位置Pos开始，查找是否存在模式子串SubString
如果存在，则返回与模式第一字符相等的字符在主串中的序号
如果不存在，则返回-1

2、算法
是串的模式匹配的一种改进,由D.E.Knuth(克努特)－J.H.Morris(莫里斯)－V.R.Pratt(普拉特)发现
当一趟匹配过程中出现字符比较不等(失配)时
⑴、不需回溯i指针
⑵、利用已经得到的“部分匹配”的结果
⑶、将模式向右“滑动”尽可能远的一段距离(next[j])后，继续进行比较
求next[j]值的算法
⑴、next[1]=0, next[2]=1
⑵、若Tj-1=Tnext[i], (i初值为j-1 或 i=next[i])
    则next[j] = next[i]+1
除非i=0, 此时next[j]=1

输入
第一行：样本个数，假设为n。
第二到2n+1行，每两行是一个样本（第1行是子串，第二行是主串），共n个测试样本。

输出
共有2n行，每两行是一个测试结果，共n个测试结果
每个测试结果包括：
第1行：子串的next[j]函数值（每个值用空格隔开）
第2行：子串在主串中的位置（主串中没有子串时，返回-1）

样例输入
2 aaba aabbababcaa ababcabd ababcaaababcabdcd

样例输出
0 1 2 1 
-1 
0 1 1 2 3 1 2 3 
8 
*/
