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
��Ŀ����
����������ģʽ�����滻������KMP�㷨�ҳ�ģʽ����������λ�ã�Ȼ�����滻�����ַ��滻��ģʽ��
����ֻ����һ���滻����������������������һЩ���ܹ�ʵ�ֶദ�滻��
������Ҫ����ģʽ�����滻�����Ȳ�һ�µ����

����
��һ������t����ʾ��t��ʵ��
�ڶ��������1��ʵ���������������������1��ʵ����ģʽ���������������1��ʵ�����滻��
�Դ�����

���
��һ�������1��ʵ��������
�ڶ��������1��ʵ���������滻���������û�з����滻���������ԭ�������ݡ�
�Դ�����

��������
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

�������
aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef
*/
