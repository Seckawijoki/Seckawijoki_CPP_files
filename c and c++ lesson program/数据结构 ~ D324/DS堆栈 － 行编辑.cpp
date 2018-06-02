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
     	int i, j, length;
     	stack<char> edlin;
     	stack<char> copy;
     	cin>>invader;
     	length = invader.length();
     	for ( i = 0 ; i < length ; ++i )
     		if ( invader[i] != '#' )
     			edlin.push(invader[i]);
     		else if ( invader[i] == '#' && !edlin.empty() )
     			edlin.pop();
     	if ( edlin.empty() )
		 {
     		cout<<"NULL\n";
     		break;
     	}
     	while ( !edlin.empty() )
     	{
     		copy.push(edlin.top());
     		edlin.pop();
     	}
     	while ( !copy.empty() )
     	{
     		cout<<copy.top();
     		copy.pop();
     	}
     	cout<<endl;
     }
     return 0;
}
/*
��Ŀ����
ʹ��C++��STL��ջ���󣬱�д����ʵ���б༭���ܡ�
�б༭�����ǣ�������#�ַ�����ִ���˸������
������ַ����˾Ͳ����������ᱨ��
������Ĭ�ϲ�����ʾ#�ַ�����������������#��ʾ����ִ�ж���˸����
ÿ����һ���ַ���س����ʾ�ַ�������
ע�⣺����ʹ�ö�ջʵ�֣����ҽ���������������

����
��һ������һ������t����ʾ��t���ַ���Ҫ����
�ڶ���������һ���ַ�����������t��

���
ÿ��������մ����Ľ�������һ��������ַ������������û���ַ��������ֱ�����NULL

��������
4 chinaa# sb#zb#u ##shen###zhen### chi##a#####

�������
china szu sz NULL 
*/
