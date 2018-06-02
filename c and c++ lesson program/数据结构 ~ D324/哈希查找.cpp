# include <iostream>
using namespace std;
# define ERROR -1
const int mode = 11;
class ListNode
{
public:
	ListNode *next;
	int datum;
	ListNode()
	{
		next = NULL;
	}
};
class ListSite
{
private:
	ListNode **head;
public:
	ListSite()
	{
		int i;
		head = new ListNode* [mode];
		for ( i = 0 ; i < mode ; ++i )
			head[i] = new ListNode ();
	}
	void ListSite_Insert( int item )
	{
		ListNode *p, *q;
		q = head[item%mode]->next;
		p = new ListNode ();
		p->datum = item;
		p->next = q;
		head[item%mode]->next = p;
	}
	int ListSite_Search( int item, int &times )
	{
		ListNode *p;
		p = head[item%mode];
		times = 0;
		while ( p->next != NULL )
		{
			p = p->next;
			++times;
			if ( p->datum == item )return times;
		}
		return ERROR;
	}
	void ListSite_Display()
	{
		int i;
		ListNode *p;
		for ( i = 0 ; i < mode ; ++i )
		{
			cout<<"head["<<i<<"]";
			p = head[i];
			if ( p->next == NULL )cout<<"->null\n";
			if ( p->next == NULL )continue;
			do
			{
				p = p->next;
				cout<<"->"<<p->datum;
			}while  ( p->next != NULL );
			cout<<endl;
		}
	}
};
int main()
{
	int n, item, times, result;
	ListSite hashtable;
	cin>>n;
	while ( n-- )
	{
		cin>>item;
		hashtable.ListSite_Insert(item);
	}
	cin>>n;
//	hashtable.ListSite_Display();
	while ( n-- )
	{
		cin>>item;
		result = hashtable.ListSite_Search(item,times);
		if ( result == ERROR )
		{
			cout<<"error\n";
			hashtable.ListSite_Insert(item);
		}
		else cout<<item%mode<<' '<<times<<endl;
	}
//	hashtable.ListSite_Display();
	return 0;
}
/*
��Ŀ����
����һ���������У�������ϣ���������෨��Ϊ��ϣ������ģ��Ϊ11����ϣ��ͻ������ַ���ͱ�ͷ����
����״β���ʧ�ܣ��Ͱ����ݲ��뵽��Ӧ��λ����
ʵ�ֹ�ϣ���ҹ���

����
��һ������n����ʾ��n������
�ڶ�������n�����ݣ�������Ȼ���һ�����ͬ������֮���ÿո����
����������t����ʾҪ����t������
�ӵ�������ÿ������һ��Ҫ���ҵ����ݣ�����������

���
ÿ�������Ӧ���ݵĲ��ҽ��

��������
6
11 23 39 48 75 62
6
39
52
52
63
63
52

�������
6 1
error
8 1
error
8 1
8 2

��ʾ
ע�⣬����������Ҫ��ͬ�Ĳ������ݣ������һ�β��Ҳ��ɹ��ͻ�ִ�в��룬��ô�ڶ��β��ұ�Ȼ�ɹ����Ҳ��Ҵ���Ϊ1�Σ���Ϊ����ͷ���룩
����ʾ����������������52����һ�β���ʧ�ܾͰ�52���뵽λ��8���ڶ��β��Ҿͳɹ��ˣ����Ե�һ�����error���ڶ��ξ����8 1
Ϊʲô����������52�����8 2
*/
