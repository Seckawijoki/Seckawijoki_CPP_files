/*题目描述
用C++语言和类实现单链表，含头结点

属性包括：data数据域、next指针域

操作包括：插入、删除、查找

注意：单链表不是数组，
所以位置从1开始对应首结点，头结点不放数据

类定义参考

输入

n 

第1行先输入n表示有n个数据，接着输入n个数据
第2行输入要插入的位置和新数据
第3行输入要插入的位置和新数据
第4行输入要删除的位置
第5行输入要删除的位置
第6行输入要查找的位置
第7行输入要查找的位置

输出
n数据之间用空格隔开，
第1行输出创建后的单链表的数据
每成功执行一次操作（插入或删除），输出执行后的单链表数据
每成功执行一次查找，输出查找到的数据
如果执行操作失败（包括插入、删除、查找等失败），
输出字符串error，不必输出单链表

样例输入
6 11 22 33 44 55 66
3 777
1 888
1
11
0
5

样例输出
11 22 33 44 55 66 
11 22 777 33 44 55 66 
888 11 22 777 33 44 55 66 
11 22 777 33 44 55 66 
error
error
44
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
private:
	ListNode *head;
	int length;      
public:  
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
	void LL_Display()
	{
		ListNode *p;
		p = head;
		while ( p->next != NULL )
		{
			p = p->next;
			cout<<p->data<<' ';
		}
		cout<<endl;
	}
}; 
int main()
{
	int i, n, location, immigrant, boolean;
	cin>>n;
	LinkList thread( n );
	thread.LL_Display();
	
	cin>>location>>immigrant;
	boolean = thread.LL_Insert( location, immigrant );
	if ( boolean != error )	thread.LL_Display();
	cin>>location>>immigrant;
	boolean = thread.LL_Insert( location, immigrant );
	if ( boolean != error )	thread.LL_Display();

	cin>>location;
	boolean = thread.LL_Amputate( location );
	if ( boolean != error )	thread.LL_Display();
	cin>>location;
	boolean = thread.LL_Amputate( location );
	if ( boolean != error )	thread.LL_Display();
	
	cin>>location;
	boolean = thread.LL_GetData( location );
	if ( boolean != error )cout<<boolean<<endl;
	cin>>location;
	boolean = thread.LL_GetData( location );
	if ( boolean != error )cout<<boolean<<endl;
	
	return 0;
}

