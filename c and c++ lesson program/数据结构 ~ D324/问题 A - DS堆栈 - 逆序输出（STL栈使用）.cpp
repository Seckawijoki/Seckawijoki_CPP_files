/*
��Ŀ����
C++���Ѿ��Դ���ջ����stack�������д��ջ�����ľ���ʵ�ִ��롣
����Ŀ��Ҫ���������Ϥstack�����ʹ�ã�Ȼ��ʵ���ַ������������
����һ���ַ��������ַ�������˳��ѹ���ջ��Ȼ����ݶ�ջ����ȳ����ص㣬���������

stack��ʹ�õĲο�����
����ͷ�ļ�<stack>  ��  # include <stack>

����һ����ջ����s��ע��stack��ģ���ࣩ��stack <char>  s; //��ջ�������������ַ���
��һ���ַ�ctѹ���ջ�� s.push(ct);
��ջ��Ԫ�ص�����s.pop();
��ȡջ��Ԫ�أ��������c2�� c2 = s.top();
�ж϶�ջ�Ƿ�գ� s.empty()�����Ϊ����������true����������򷵻�false

����
��һ������t����ʾ��t������ʵ��
�ڶ���ÿһ������һ���ַ�����ע���ַ�����Ҫ�����ո�

�ַ�����������Կ���һ�´��룺
#include <string>
int main()
{
  string str;
  int length;
  cin>>str; //��������ַ��������ڱ���str��
  length = str.length()  //��ȡ�����ַ����ĳ���
}

���
ÿ���������ÿһ���ַ���

��������
2
abcdef
aabbcc

�������
fedcba
ccbbaa
*/

# include <iostream>
# include <string>
# include <stack>
using namespace std;
int main()
{
	int n, i, length;
	string s1;
	stack <char> s2;
	cin>>n;
	while ( n-- )
	{
		cin>>s1;
		length = s1.length();
		for ( i = 0 ; i < length ; ++i )
			s2.push(s1[i]);
		for ( i = 0 ; i < length ; ++i )
		{
			cout<<s2.top();
			s2.pop();
		}
		cout<<endl;
	}
	return 0;
}
