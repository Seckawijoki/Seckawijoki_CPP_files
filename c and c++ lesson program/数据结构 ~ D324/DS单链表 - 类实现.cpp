# include <iostream>
using namespace std;
# define OK     0
# define ERROR -1
class ListNode
{
public:
	int datum;
	ListNode *next;
};

class SingleLinkedList
{
public:
	ListNode *head;
	int length;
	SingleLinkedList()
	{
		length = 0;
		head = new ListNode();
	}
	SingleLinkedList( int *array, int n )
	{
		int i;
		length = n;
		head = new ListNode();
		ListNode *p, *q;
		p = head;
		for ( i = 0 ; i < n ; ++i )
		{
			q = new ListNode();
			q->datum = array[i];
			p->next = q;
			p = q;
		}
	}
	void Display()
	{
		int i;
		ListNode *p = head->next;
		for ( i = 1 ; i <= length ; ++i, p = p->next )
			cout<<p->datum<<' ';
		cout<<endl;
	}
	int SSL_Insert( int position, int item )
	{
		if ( position < 1 || position > length + 1 )return ERROR;
		int i;
		ListNode *p, *q;
		p = head;
		q = new ListNode();
		q->datum = item;
		for ( i = 1 ; i < position ; ++i )
			p = p->next;
		q->next = p->next;
		p->next = q;
		++length;
		return OK;
	}
	int SSL_Delete( int position )
	{
		if ( position < 1 || position > length )return ERROR;
		int i;
		ListNode *p, *q;
		p = head;
		for ( i = 1 ; i < position ; ++i )
			p = p->next;
		q = p;
		p = p->next;
		q->next = q->next->next;
		--length;
		delete p;
		return OK;
	}
	int SSL_Search( int position )
	{
		if ( position < 1 || position > length )return ERROR;
		int i;
		ListNode *p = head;
		for ( i = 0 ; i < position ; ++i )
			p = p->next;
		return p->datum;
	}
};
int main()
{
	int n, i, item;
	int array[1024];
	cin>>n;
	for ( i = 0 ; i < n ; ++i )
		cin>>array[i];
	SingleLinkedList sll(array,n);
	sll.Display();
	
	cin>>i>>item;
	n = sll.SSL_Insert(i,item);
	if ( n == ERROR )cout<<"error\n";
	else sll.Display();
	
	cin>>i>>item;
	n = sll.SSL_Insert(i,item);
	if ( n == ERROR )cout<<"error\n";
	else sll.Display();
	
	cin>>i;
	n = sll.SSL_Delete(i);
	if ( n == ERROR )cout<<"error\n";
	else sll.Display();	
	
	cin>>i;
	n = sll.SSL_Delete(i);
	if ( n == ERROR )cout<<"error\n";
	else sll.Display();
	
	cin>>i;
	n = sll.SSL_Search(i);
	if ( n == ERROR )cout<<"error\n";
	else cout<<n<<endl;
	
	cin>>i;
	n = sll.SSL_Search(i);
	if ( n == ERROR )cout<<"error\n";
	else cout<<n<<endl;
	
	return 0;
}
/*
题目描述
用C++语言和类实现单链表，含头结点
属性包括：data数据域、next指针域
操作包括：插入、删除、查找
注意：单链表不是数组，所以位置从1开始对应首结点，头结点不放数据
类定义参考

输入
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
如果执行操作失败（包括插入、删除、查找等失败），输出字符串error，不必输出单链表

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
