/*
��Ŀ����
ʹ��C++��STL��ջ���󣬱�д����ʵ���б༭���ܡ�
�б༭�����ǣ�������#�ַ�����ִ���˸������������ַ����˾Ͳ����������ᱨ��
������Ĭ�ϲ�����ʾ#�ַ�����������������#��ʾ����ִ�ж���˸����
ÿ����һ���ַ���س����ʾ�ַ�������
ע�⣺����ʹ�ö�ջʵ�֣����ҽ���������������

����
��һ������һ������t����ʾ��t���ַ���Ҫ����
�ڶ���������һ���ַ�����������t��

���
ÿ��������մ����Ľ�������һ��������ַ������������û���ַ��������ֱ�����NULL
��������

4
chinaa#
sb#zb#u
##shen###zhen###
chi##a#####

�������
china
szu
sz
NULL
*/
# include <iostream>
# include <stack>
# include <string>
using namespace std;
void BackspaceOperation( string executed )
{
	int length = executed.length();
	int i, j;
	char *display = new char [length];
	stack <char> operation;
	for ( i = 0 ; i < length ; ++i )
	{
		if ( executed[i] == '#' )
		{
			if ( operation.empty() );
			else operation.pop();
		}
		else
			operation.push(executed[i]);
	}
	if ( operation.empty() )
		cout<<"NULL\n";
	else
	{
		for ( i = 0 ; !operation.empty() ; ++i )
		{
			display[i] = operation.top();
			operation.pop();
		}
		for ( j = --i; j >= 0 ; --j )
			cout<<display[j];
		cout<<endl;
	}
	delete [] display;
}
int main()
{
	int n;
	string conner;
	cin>>n;
	while ( n-- )
	{
		cin>>conner;
		BackspaceOperation(conner);
	}
	return 0;
}
