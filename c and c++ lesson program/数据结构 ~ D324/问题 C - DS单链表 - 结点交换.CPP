/*
题目描述
用C++实现含头结点的单链表，然后实现单链表的两个结点交换位置。
注意不能简单交换两个结点包含数据，必须通过修改指针来实现两个结点的位置交换

交换函数定义可以参考：
swap（int  pa, int pb)  //pa和pb表示两个结点在单链表的位置序号
swap (ListNode * p, ListNode * q)  //p和q表示指向两个结点的指针
输入

第1行先输入n表示有n个数据，接着输入n个数据
第2行输入要交换的两个结点位置
第3行输入要交换的两个结点位置

输出

第一行输出单链表创建后的所有数据，数据之间用空格隔开
第二行输出执行第1次交换操作后的单链表数据，数据之间用空格隔开
第三行输出执行第2次交换操作后的单链表数据，数据之间用空格隔开
如果发现输入位置不合法，输出字符串error，不必输出单链表

样例输入
5 11 22 33 44 55
1 4
2 6

样例输出
11 22 33 44 55 
44 22 33 11 55 
error
*/
# include <iostream>
using namespace std;
# define ok     0
# define error -1
class ListNode
{
public:
	int datium;
	ListNode *next;
	ListNode()
	{
		next = NULL;
	}
	ListNode( int digit )
	{
		next = NULL;
		datium = digit;
	}
};
class LinkList
{
private:
	ListNode *head;
	int length;
public:
	LinkList()
	{
		head = new ListNode ();
		length = 0;
	}
	LinkList( int size )
	{
		head = new ListNode ();
		length = size;
		ListNode *p , *q ;
		int j , invader;
		p = head;
		for ( j = 1 ; j <= length ; j++ )
		{
			cin>>invader;
			q = new ListNode (invader);
			p->next = q;
			p = q;
		}
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
	int LL_Swaping( int site1, int site2 )
	{
		if ( site1 < 1 || site1 > length || 
			 site2 < 1 || site2 > length  )
		{
			cout<<"error\n";
			return error;	
		}
		else
		{
			ListNode *pa, *pb, *qa, *qb, *s;
			int j;
			pa = head;
			qa = head;
			for ( j = 1 ; j < site1 ; j++ )
				pa = pa->next;
			pb = pa->next;
			for ( j = 1 ; j < site2 ; j++ )
				qa = qa->next;
			qb = qa->next;
			
			s = qb->next;
			pa->next = qb;
			qb->next = pb->next;
			qa->next = pb;
			pb->next = s;
			return ok;
		}
	}
	void LL_Display()
	{
		ListNode *p;
		int j;
		p = head->next;
		for ( j = 1 ; j <= length ; j++ )
		{
			cout<<p->datium<<' ';
			p = p->next;
		}
		cout<<endl;
	}
};
int main()
{
	int n , location, situation, boolean;
	cin>>n;
	LinkList thread(n);
	thread.LL_Display();
	
	cin>>location>>situation;
	boolean = thread.LL_Swaping(location,situation);
	if(	boolean != error )thread.LL_Display();
	
	cin>>location>>situation;
	boolean = thread.LL_Swaping(location,situation);
	if(	boolean != error )thread.LL_Display();
	return 0;
}
