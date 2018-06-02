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
��Ŀ����
ѧϰKMP�㷨������������ģʽ������ģʽ����������λ��

����
��һ������t����ʾ��t��ʵ��
�ڶ��������1��ʵ���������������������1��ʵ����ģʽ��
�Դ�����

���
��һ�������1��ʵ����ģʽ����nextֵ
�ڶ��������1��ʵ����ƥ��λ�ã�λ�ô�1��ʼ���㣬���ƥ��ɹ����λ�ã�ƥ��ʧ�����0
�Դ�����

��������
3
qwertyuiop
tyu
aabbccdd
ccc
aaaabababac
abac

�������
0 1 1 
5
0 1 2 
0
0 1 1 2 
8
*/
