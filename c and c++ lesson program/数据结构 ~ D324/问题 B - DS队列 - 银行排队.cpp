/*
��Ŀ����

������Ӫҵ����������3�ֿͻ�������ΪA\B\C�������ֱ�������3�����ڷֱ�������ֿͻ���
��ÿ������ֻ����һ�ֿͻ���
����һ���ͻ������а���ҵ��ÿ���ͻ��������ͺͰ���ҵ��ʱ�䡣
ÿ�����ڰ��տͻ�������˳����з���
���ʵ�����ǵİ������̣���ʹ��C++�Դ���queue����ʹ�ö���ʵ�֣���������0�֣�
����queue���÷����£�
1.����ͷ�ļ���#include <queue>
2.����һ���������ж���queue<int>  myQe;
3.����һ���������ж������飺queue<int>  myQA[10]; 
4.��Ӳ�����myQe.push(itemp); //������itemp�������
5.���Ӳ�����myQe.pop();  //�Ѷ�ͷԪ�ص������У�ע�Ȿ��������ȡ��ͷԪ��
6.��ȡ��ͷԪ�أ� itemp = myQe.front(); // �Ѷ�ͷԪ�ط���itemp�У�ע�Ȿ����������Ԫ��
7.�ж϶����Ƿ�Ϊ�գ�myQe.empty();//���п��򷵻�true�������򷵻�false

����
��һ������������n��ʾ�ͻ�����
�ڶ�������ÿ���ͻ������ͣ�����֮�����ÿո����
����������ÿ���ͻ��İ���ʱ�䣬����֮�����ÿո����

���
��һ�����A��ͻ���ƽ������ʱ��
�ڶ������B��ͻ���ƽ������ʱ��
���������C��ͻ���ƽ������ʱ��

��������
8
A B C B C A A A
10 20 30 40 50 60 70 80

�������
55
30
40
*/
# include <iostream>
# include <queue>
using namespace std;
int main()
{
	int n, i, time;
	int serviceTime[3] = {0};
	int guestNumber[3] = {0};
	char type;
	queue <int> transacting;
	queue <char> serving;
	cin>>n;
	for ( i = 0 ; i < n ; ++i )
	{
		cin>>type;
		serving.push(type);
	}
	for ( i = 0 ; i < n ; ++i )
	{
		cin>>time;
		transacting.push(time);
	}
	while ( n-- )
	{
		type = serving.front();
		serviceTime[type - 'A'] += transacting.front();
		++guestNumber[type - 'A'];
		transacting.pop();
		serving.pop();
	}
	for ( i = 0 ; i < 3 ; ++i )
		cout<<serviceTime[i] / guestNumber[i]<<endl;
	return 0;
}


