# include <iostream>
using namespace std;
void Get_NextValue( string model, int next[] )
{
	int i = 1;
	int j = 0;
	next[1] = 0;
	while ( i < model[0] )
	{
		if ( j == 0 || model[i] == model[j] )
			next[++i] = ++j;
		else
			j = next[j];
	}
}
int Index_KMP( string primary, string secondary, int position )
{
	int i = position;
	int j = 0;
	int k, length = secondary.length();
	int *next = new int [length];
	Get_NextValue(secondary,next);
	for ( k = 1 ; k < length ; ++k )cout<<next[k]<<' ';cout<<endl;
	while ( i <= primary[0] && j <= secondary[0] )
	{
		if ( j == 0 || primary[i] == secondary[j] )
		{
			++i;
			++j;
		}
		else
			j = next[j];
	}
	if ( j > secondary[0] )return i - secondary[0];
	else return 0;
}
int main()
{
	int t, i;
	char copy[512];
	string chief, vice;
	cin>>t;
	while ( t-- )
	{
		cin>>chief>>vice;
		
		copy[0] = chief.length();
		for ( i = 1 ; i <= copy[0] ; ++i )
			copy[i] = chief[i-1];
		copy[i] = '\0';
		chief = copy;
		
		copy[0] = vice.length();
		for ( i = 1 ; i <= copy[0] ; ++i )
			copy[i] = vice[i-1];
		copy[i] = '\0';
		vice = copy;
		
	//	cout<<chief<<endl<<vice<<endl;
		cout<<Index_KMP(chief,vice,1)<<endl;
	}
	return 0;
}
/*
题目描述
学习KMP算法，给出主串和模式串，求模式串在主串的位置

输入
第一个输入t，表示有t个实例
第二行输入第1个实例的主串，第三行输入第1个实例的模式串
以此类推

输出
第一行输出第1个实例的模式串的next值
第二行输出第1个实例的匹配位置，位置从1开始计算，如果匹配成功输出位置，匹配失败输出0
以此类推

样例输入
3
qwertyuiop
tyu
aabbccdd
ccc
aaaabababac
abac

样例输出
0 1 1 
5
0 1 2 
0
0 1 1 2 
8
*/
