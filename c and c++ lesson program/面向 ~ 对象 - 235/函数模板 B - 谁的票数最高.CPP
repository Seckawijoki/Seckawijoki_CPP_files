/*
题目描述
某小镇要票选镇长，得票最高者当选。
但由于投票机制不健全，导致每届投票时，候选人在投票系统的识别码类型不一致。
请编写函数模板，能针对多种类型的数据，查找出得票最高的元素。
其中，每届投票的选票有n张，识别码类型为T

注意：必须使用模板函数

输入

第一行输入t表示有t个测试实例
第二行先输入一个大写字母表示识别码类型，
I表示整数类型，C表示字符型，S表示字符串型；
然后输入n表示数组长度。
第三行输入n个数据
依次输入t个实例

输出
每行输出一个结果，分别输出当选者的识别码和得票数，以空格分开。

样例输入
3
I 10
5 3 5 2 9 7 3 7 2 3
C 8
a b a e b e e q
S 5
sandy david eason cindy cindy

样例输出
3 3
e 3
cindy 2

*/
# include <iostream>
# include <string>
using namespace std;
template < class T >
T VotingMajor( T *vote , int size )
{
	int i,k,type = 1;
	T label[88];
	int number[88] = {0};
	label[0] = vote[0];
	for ( i = 1 , k = 1 ; i < size ; i++ )
		if ( vote[0] != vote[i] )
		{
			label[k] = vote[i];
			type++;
			k++;
		}
	for ( k = 0 ; k < type ; k++ )
		for ( i = 0 ; i < size ; i++ )
			if ( label[k] == vote[i] )
				number[k]++;
	int max = number[0],x = 0;
	for ( i = 0 ; i < size ; i++ )
		if ( max < number[i] )
		{
			max = number[i];
			x = i;
		}
	return label[x];
}
int main()
{
	int t,n,i;
	char type;
	cin>>t;
	while ( t-- )
	{
		cin>>type>>n;
		if ( type == 'I' )
		{
			int *vote = new int [n];
			for ( i = 0 ; i < n ; i++ )
				cin>>vote[i];
			int sign = VotingMajor(vote,n);
			int sum = 0;
			for ( i = 0 ; i < n ; i++ )
				if ( vote[i] == sign )
					sum++;
			cout<<sign<<' '<<sum<<endl;
			delete [] vote;
		}
		else if ( type == 'C' )
		{
			char *vote = new char [n];
			for ( i = 0 ; i < n ; i++ )
				cin>>vote[i];
			char sign = VotingMajor(vote,n);
			int sum = 0;
			for ( i = 0 ; i < n ; i++ )
				if ( vote[i] == sign )
					sum++;
			cout<<sign<<' '<<sum<<endl;
			delete [] vote;
		}
		else if ( type == 'S' )
		{
			string *vote = new string [n];
			for ( i = 0 ; i < n ; i++ )
				cin>>vote[i];
			string sign = VotingMajor(vote,n);
			int sum = 0;
			for ( i = 0 ; i < n ; i++ )
				if ( vote[i] == sign )
					sum++;
			cout<<sign<<' '<<sum<<endl;
			delete [] vote;
		}
	}
	return 0;
}