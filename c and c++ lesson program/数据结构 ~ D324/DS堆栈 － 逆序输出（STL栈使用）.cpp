# include <iostream>
# include <stack>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while ( t-- )
	{
		string invader;
		int i, length;
		stack<char> thread;
		cin>>invader;
		length = invader.length();
		for ( i = 0 ; i < length ;++i )
			thread.push(invader[i]);
		while ( !thread.empty() )
		{
			cout<<thread.top();
			thread.pop();
		}
		cout<<endl;
	}
    return 0;
}
/*
��Ŀ����
C++���Ѿ��Դ���ջ����stack�������д��ջ�����ľ���ʵ�ִ��롣
����Ŀ��Ҫ���������Ϥstack�����ʹ�ã�Ȼ��ʵ���ַ������������
����һ���ַ��������ַ�������˳��ѹ���ջ��Ȼ����ݶ�ջ����ȳ����ص㣬���������

stack��ʹ�õĲο�����
n����ͷ�ļ�<stack>  ��  #include <stack>
n����һ����ջ����s��ע��stack��ģ���ࣩ��stack <char>  s; //��ջ�������������ַ���
n��һ���ַ�ctѹ���ջ�� s.push(ct);
n��ջ��Ԫ�ص�����s.pop();
n��ȡջ��Ԫ�أ��������c2�� c2 = s.top();
n�ж϶�ջ�Ƿ�գ� s.empty()�����Ϊ����������true����������򷵻�false

����
��һ������t����ʾ��t������ʵ��
�ڶ���ÿһ������һ���ַ�����ע���ַ�����Ҫ�����ո�
�ַ�����������Կ���һ�´��룺
#include <string>
int main()
{ string str;
  Int len;
  cin>>str; //��������ַ��������ڱ���str��
  len = str.length()  //��ȡ�����ַ����ĳ���
}

���
ÿ���������ÿһ���ַ���

��������
2 abcdef aabbcc

�������
fedcba ccbbaa 
*/
