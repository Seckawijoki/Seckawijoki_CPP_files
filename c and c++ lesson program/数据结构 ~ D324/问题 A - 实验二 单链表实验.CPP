/*
题目描述
1、问题描述
给出初始数据
实现单链表的定义、创建、查找、插入、删除

2、算法
单链表结点的存储结构包含两部分：数据、下一结点指针
单链表的查找：给出位置i结点的指针
单链表的插入：创建新的结点，在位置i-1和位置i之间插入新的结点，修改相关指针指向
单链表的创建：依次为输入的数据分配结点，并按序链接起来
单链表的删除：修改位置i-1结点的下一结点指针指向i+1结点，删除位置i结点，释放被删除结点


输入
每个样本分4行：
第一行：第一个数字n表示样本数目，其后跟n个样本
第二行：查找数据的位置
第三行：插入新数据位置、新数据
第四行：删除数据的位置


输出
第一行：单链表创建后，单链表按顺序排列的每个结点的数据
第二行：按指定位置给出数据
第三行：插入新数据结点后，单链表按顺序排列的每个结点的数据
第四行：删除一个数据结点，单链表按顺序排列的每个结点的数据

样例输入
5 2 4 3 5 7
4
2 9
3

样例输出
2 4 3 5 7
5 
2 9 4 3 5 7
2 9 3 5 7
*/
# include <iostream>
using namespace std;
# define ok      0
# define error  -1
class ListNode
{
public:
	int data;
	ListNode *next;
	ListNode()
	{
		next = NULL;
	}
	ListNode( int digit )
	{
		next = NULL;
		data = digit;
	}
};
class LinkList           
{
public:
	ListNode *head;
	int length;      
	LinkList()            
	{
		head = new ListNode();
		length = 0;		
	}
	LinkList( int size )
	{
		int j, newcomer;
		ListNode *p, *s;
		head = new ListNode();
		p = head;
		for ( j = 1 ; j <= size ; j++ )
		{
			cin>>newcomer;
			s = new ListNode (newcomer);
			p->next = s;
			p = s;
		}		
		length = size;		
	} 
	~LinkList()                   
	{
		ListNode *p , *q;
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
	ListNode *LL_Questing( int i )
	{
		if ( i > length || i <= 0 )
		{
			cout<<"error\n";
			return NULL;
		}
		else
		{
			ListNode *p;
			p = head;
			int j;
			for ( j = 1 ; j <= i ; j++ )
				p = p->next;
			return p;
		}
	}
	int LL_GetData( int i )
	{
		if ( i > length || i <= 0 )
		{
			cout<<"error\n";
			return error;
		}
		else
		{
			ListNode *p;
			p = head;
			int j;
			for ( j = 1 ; j <= i ; j++ )
				p = p->next;
			return p->data;
		}
	}
	int LL_Insert( int i , int item )                 
	{
		if ( i > length + 1 || i <= 0 )
		{
			cout<<"error\n";
			return error;
		}
		else
		{
			ListNode *p, *q;
			p = head;
			int j;
			for ( j = 1 ; j < i ; j++ )
				p = p->next;
			q = new ListNode (item);
			q->next = p->next;
			p->next = q;
			length++; 
			return ok;
		}
	}
	int LL_Amputate( int i )
	{
		if ( i > length || i <= 0 )
		{
			cout<<"error\n";
			return error;
		}
		else
		{
			ListNode *p;
			p = head;
			int j;
			for ( j = 1 ; j < i ; j++ )
				p = p->next;
			p->next = p->next->next;
			length--;
			return ok;
		}
	}
	void LL_Sort()
	{
		//	5 2 135 73 9578905 3
		ListNode *p, *q;
		int i, j;
		p = head;
		for ( i = 0 ; i < length ; ++i )
		{
			p = p->next;
			q = p;
			for ( j = i + 1 ; j < length ; ++j )
			{
				q = q->next;
				if ( p->data > q->data )
				{
					p->data = p->data + q->data;
					q->data = p->data - q->data;
					p->data = p->data - q->data;
				}
			}
		}	
	}
	void LL_Display()
	{
		ListNode *p;
		p = head;
		while ( p->next->next != NULL )
		{
			p = p->next;
			cout<<p->data<<' ';
		}
		cout<<p->next->data<<endl;
	}
	
	
}; 
int main()
{
	int i, n, location, immigrant, boolean;
	cin>>n;
	LinkList thread( n );
	thread.LL_Display();
	/*
	cin>>location;
	boolean = thread.LL_GetData( location );
	if ( boolean != error )cout<<boolean<<endl;
	
	cin>>location>>immigrant;
	boolean = thread.LL_Insert( location, immigrant );
	if ( boolean != error )	thread.LL_Display();

	cin>>location;
	boolean = thread.LL_Amputate( location );
	if ( boolean != error )	thread.LL_Display();
	*/
	thread.LL_Sort();
	cout<<thread.LL_Maxium(thread.head->next, thread.head->next->next)<<endl;
	thread.LL_Display();
	return 0;
}
