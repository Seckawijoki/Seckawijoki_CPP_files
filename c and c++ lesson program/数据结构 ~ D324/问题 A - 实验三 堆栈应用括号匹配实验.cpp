/*
��Ŀ����
1����������
һ���������ʽ�а���Բ���š������źͻ�����������ʽ������
���ʵ���б���ʽ�������Ƿ���ȷƥ����㷨

2���㷨
˳��ɨ���������ʽ
���������ʽɨ����ɣ���ʱ���ջ�գ�����ȷ����(0)�����ջδ�գ�˵�������Ŷ��������ţ�����(-3)
���������ʽ��ȡ��һ���ַ��������������(��(����[���� ��{��)�����ø����Ž�ջ(PUSH)
�����������(��)����]���� ��}��)��
�š����ջΪ�գ���˵�������Ŷ��������ţ�����(-2)
�ơ����ջ��Ϊ�գ����ջ������(POP)һ�����ţ� ������ƥ�䣬��ת1���������жϣ�����˵������������Դ�����ȷ������(-1)

����
��һ�У���������������Ϊn��
�ڶ���n+1�У�ÿһ����һ���������������ʽ��������n������������


���
����n�У�ÿһ����һ�����Խ���������ֽ����
0����������ƥ����ȷ  {[(1+2)*3]-1}
-1������������Դ�����ȷ {[(1+2]*3)-1}
-2�������Ŷ���������  (1+2)*3)-1}
-3�������Ŷ���������  {[(1+2)*3-1]

��������
4
{[(1+2)*3]-1}
{[(1+2]*3)-1}
(1+2)*3)-1}
{[(1+2)*3-1]

�������
0
-1
-2
-3
*/
# include <iostream>
# include <string>
# include <stack>
using namespace std;
int SequencialScanning( string conner )
{
	int i, n, length;
	stack <char> storage;
	length = conner.length();
	for ( i = 0 ; i < length ; ++i )
	{
		if ( conner[i] == '[' || 
		     conner[i] == '{' || 
		 	 conner[i] == '(' )
			storage.push(conner[i]);
		else if ( conner[i] == ']' )
		{
			if ( storage.empty() )
				return -2;
			else if ( storage.top() == '(' || storage.top() == '{' )
				return -1;
			else if ( storage.top() == '[' )
				storage.pop();
		}
		else if ( conner[i] == '}' )
		{
			if ( storage.empty() )
				return -2;
			else if ( storage.top() == '(' || storage.top() == '[' )
				return -1;
			else if ( storage.top() == '{' )
				storage.pop();
		}
		else if ( conner[i] == ')' )
		{
			if ( storage.empty() )
				return -2;
			else if ( storage.top() == '[' || storage.top() == '{' )
				return -1;
			else if ( storage.top() == '(' )
				storage.pop();
		}
	}
	if ( storage.empty() )
		return 0;
	else
		return -3;
}
int main()
{
	int n;
	string expression;
	cin>>n;
	while ( n-- )
	{
		cin>>expression;
		cout<<SequencialScanning(expression)<<endl;
	}
	return 0;
}
