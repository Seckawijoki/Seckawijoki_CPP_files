/*
��Ŀ����
1����������
�š���һ���������в�ͬ����������data�������������ַ����ַ�ֵ��int���ͱ�ʾ��
����д��ĸ�ַ���A������Z����Сд��ĸ�ַ���a������z��,�����ַ���0������9������
����ʵ���㷨�����õ�����ָ����������������ÿ���������о�ֻ��һ���ַ���
�ơ���ÿ��������������򣨲��������µĽ�㣬Ҳ����ɾ���ɵĽ�㣩��

����
ÿ��������2�У�
��һ�У�����n��ʾ������Ŀ
�ڶ��У�n������

���
��һ�У����������󣬵�����˳�����е�ÿ����������
�ڶ��У�δ����Ĵ�д��ĸ�ַ�����
�����У�δ�����Сд��ĸ�ַ�����
�����У�δ����������ַ�����
�����У�������Ĵ�д��ĸ�ַ�����
�����У��������Сд��ĸ�ַ�����
�����У�������������ַ�����


��������
13
2 W m a 7 Q 3 1 A P p b D

�������
2 W m a 7 Q 3 1 A P p b D
W Q A P D
m a p b
2 7 3 1
A D P Q W
a b m p
1 2 3 7
*/
# include <iostream>
# include <string>
using namespace std;
# define    ok  0
# define error -1
class ListNode
{
public:
	char datium;
	ListNode *next;
	ListNode()
	{
		next = NULL;
	}
};
class LinkList
{
public:
	ListNode *head;
	int length;
	LinkList()
	{
		head = new ListNode ();
		length = 0;
	}
	~LinkList()
	{
		ListNode *p, *q;
		p = head;
		while ( p != NULL )
		{
			q = p;
			p = p->next;
			delete q;
		}
		length = 0;
		head = NULL;
	}
	void LL_GetVariousData( LinkList &all , string type )
	{
		ListNode *p, *q, *s;
		int j;
		p = head;
		q = all.head;
		for ( j = 1 ; j <= length ; ++j )
			p = p->next;
		if ( type == "capital" ) 
		{
			for ( j = 1 ; j <= all.length ; ++j )
			{
				q = q->next;
				if ( q->datium >= 'A' && q->datium <= 'Z' )
				{
					s = new ListNode ();
					s->datium = q->datium;
					p->next = s;
					p = s;
					length++;
				}
			}
		}
		else if ( type == "lowercase" ) 
		{
			for ( j = 1 ; j <= all.length ; ++j )
			{
				q = q->next;
				if ( q->datium >= 'a' && q->datium <= 'z' )
				{
					s = new ListNode ();
					s->datium = q->datium;
					p->next = s;
					p = s;
					length++;
				}
			}
		}
		else if ( type == "number" ) 
		{
			for ( j = 1 ; j <= all.length ; ++j )
			{
				q = q->next;
				if ( q->datium >= '0' && q->datium <= '9' )
				{
					s = new ListNode ();
					s->datium = q->datium;
					p->next = s;
					p = s;
					length++;
				}
			}
		}
		
	}
	void LL_Sequencing()
	{
		ListNode *p, *q;
		int i,j;
		p = head;
		for ( i = 1 ; i <= length ; ++i )
		{
			p = p->next;
			q = p;
			for ( j = i + 1 ; j <= length ; ++j )
			{
				q = q->next;
				if ( p->datium > q->datium )
				{
					char transient;
					transient = p->datium;
					p->datium = q->datium;
					q->datium = transient;
				}
			}
		}	
				
	}
	void LL_Insert( int i , char item )
	{
		if ( i > 0 && i <= length + 1 )
		{
			ListNode *p, *q;
			int j;
			p = head;
			for ( j = 1 ; j < i ; ++j )
				p = p->next;
			q = new ListNode ();
			q->datium = item;
			p->next = q;
			length++;
		}
	}
	void LL_Display()
	{
		ListNode *p;
		int j;
		p = head;
		for ( j = 1 ; j < length ; ++j )
		{
			p = p->next;
			cout<<p->datium<<' ';
		}
		cout<<p->next->datium<<endl;
	}
};
int main()
{
	int i, n;
	char immigrant;
	LinkList sum;
	LinkList capital;
	LinkList lowercase;
	LinkList number;
	cin>>n;
	for ( i = 1 ; i <= n ; ++i )
	{
		cin>>immigrant;
		sum.LL_Insert(i,immigrant);
	}
	sum.LL_Display();
	
	capital.LL_GetVariousData( sum , "capital" );
	capital.LL_Display();
	lowercase.LL_GetVariousData( sum , "lowercase" );
	lowercase.LL_Display();
	number.LL_GetVariousData( sum , "number" );
	number.LL_Display();
	
	capital.LL_Sequencing();
	capital.LL_Display();
	lowercase.LL_Sequencing();
	lowercase.LL_Display();
	number.LL_Sequencing();
	number.LL_Display();
	return 0;
}
