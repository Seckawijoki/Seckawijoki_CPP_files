# include <iostream>
# include <string>
# define ERROR  -1
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
int Index_KMP( string primary, string secondary, int position )
{
	int i = position, j = 1, length = secondary.length();
	int *next = new int [length];
	Get_NextValue(secondary,next);
//	for ( int k = 1 ; k < length ; ++k )cout<<next[k]<<' ';cout<<endl;
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
	delete []next;
	if ( j > secondary[0] )return i - secondary[0];
	else return ERROR;
}
int main()
{
	int t, i, size, site;
	char copy[1024];
	string zero, one, two, three;
	cin>>t;
	while ( t-- )
	{
		cin>>one;
		cout<<one<<endl;
		copy[0] = one.length();
		for ( i = 0 ; i < copy[0] ; ++i )
			copy[i+1] = one[i];
		copy[i+1] = '\0';
		one = copy;
		
		cin>>two;
		copy[0] = two.length();
		for ( i = 0 ; i < copy[0] ; ++i )
			copy[i+1] = two[i];
		copy[i+1] = '\0';
		two = copy;
	//	cout<<one<<endl<<two<<endl;
		cin>>three;
		site = Index_KMP(one,two,1);
		if ( site != ERROR )
	//	do
		{
			size = two.length() - 1;
			one.replace(site,size,three);
			one[0] = one.length() - 1;
		//	cout<<one<<endl;
		//	cout<<(int)one[0]<<endl;
		//	site = Index_KMP(one,two,site+size);
		//	cout<<"site = "<<site<<endl;
		}
	//	while ( site != ERROR );	
		size = one.length() - 1;
		for ( i = 0 ; i < size ; ++i )
			copy[i] = one[i+1];
		copy[i] = '\0';
		zero = copy;
		cout<<zero<<endl;
	}// 		1 qweqweqweqwe we tttt
	return 0;
}
/*
题目描述
给出主串、模式串、替换串，用KMP算法找出模式串在主串的位置，然后用替换串的字符替换掉模式串
本题只考虑一处替换的情况，如果你想做的完美一些，能够实现多处替换那
可能需要考虑模式串和替换串长度不一致的情况

输入
第一个输入t，表示有t个实例
第二行输入第1个实例的主串，第三行输入第1个实例的模式串，第四行输入第1个实例的替换串
以此类推

输出
第一行输出第1个实例的主串
第二行输出第1个实例的主串替换后结果，如果没有发生替换就输出主串原来的内容。
以此类推

样例输入
3
aabbccdd
bb
ff
aaabbbccc
ddd
eee
abcdef
abc
ccccc

样例输出
aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef
*/
