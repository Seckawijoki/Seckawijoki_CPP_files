/*
题目描述
1、问题描述
⑴、有一单链表，表中不同结点的数据域（data）包含有三类字符（字符值用int类型表示）
（大写字母字符‘A’～‘Z’，小写字母字符‘a’～‘z’,数字字符‘0’～‘9’），
请编程实现算法，将该单链表分割成三个单链表，其中每个单链表中均只含一类字符。
⑵、对每个单链表进行排序（不能申请新的结点，也不能删除旧的结点）。

输入
每个样本分2行：
第一行：数字n表示样本数目
第二行：n个样本

输出
第一行：单链表创建后，单链表按顺序排列的每个结点的数据
第二行：未排序的大写字母字符数据
第三行：未排序的小写字母字符数据
第四行：未排序的数字字符数据
第五行：已排序的大写字母字符数据
第六行：已排序的小写字母字符数据
第七行：已排序的数字字符数据


样例输入
13
2 W m a 7 Q 3 1 A P p b D

样例输出
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
