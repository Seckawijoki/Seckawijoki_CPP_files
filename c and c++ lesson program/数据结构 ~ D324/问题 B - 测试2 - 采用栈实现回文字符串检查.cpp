# include <iostream>
# include <string>
# include <stack>
using namespace std;
# define OK     1
# define ERROR -1
int main()
{
	int t;
	cin>>t;
	while ( t-- )
	{
		stack <char> room1, room2;
		string patient;
		int i, length, daijoubu = OK;
		cin>>patient;
		length = patient.length();
		for ( i = 0 ; i < length ; ++i )
			room1.push(patient[i]);
		for ( i = 0 ; i < length / 2 ; ++i )
		{
			room2.push(room1.top());
			room1.pop();
		}
		if ( length %2 )
			room1.pop();
		while ( !room1.empty() && !room2.empty() )
		{
			if ( room1.top() != room2.top() )
			{
				daijoubu = ERROR;
				break;
			}
			else
			{
				room1.pop();
				room2.pop();
			}
		}
		cout<<( daijoubu == OK ? OK : ERROR )<<endl;
	}
	return 0;
}
/*
��Ŀ����
1����������
����һ���ַ���������ջ������Ƿ��ǻ����ַ���

2���㷨
�����ַ����������Ҷ��ʹ��ҵ������ȫһ��������"level" �� ��aaabbaaa��
ѡ�������ַ������ѹ��ջ��Push����Ȼ���ٽ��ַ�����һ����ʼ������ջ�е������ַ���Ƚϣ�����������ַ���ͬ�����ǻ��ģ������ǡ�


����
��1�У�������Ŀn
��2�У���һ���ַ�������
 ��
��n+1�У���n���ַ�������


���
ÿ������1��
�ǻ��ģ������1���������-1


��������
5
abcddcba
1234554321
12abcba12
3210123
32110123

�������
1
1
-1
1
-1

*/
