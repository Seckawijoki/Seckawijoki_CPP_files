/*��Ŀ����
��C++���Ժ���ʵ�ֵ�������ͷ���

���԰�����data������nextָ����

�������������롢ɾ��������

ע�⣺�����������飬
����λ�ô�1��ʼ��Ӧ�׽�㣬ͷ��㲻������

�ඨ��ο�

����

n 

��1��������n��ʾ��n�����ݣ���������n������
��2������Ҫ�����λ�ú�������
��3������Ҫ�����λ�ú�������
��4������Ҫɾ����λ��
��5������Ҫɾ����λ��
��6������Ҫ���ҵ�λ��
��7������Ҫ���ҵ�λ��

���
n����֮���ÿո������
��1�����������ĵ����������
ÿ�ɹ�ִ��һ�β����������ɾ���������ִ�к�ĵ���������
ÿ�ɹ�ִ��һ�β��ң�������ҵ�������
���ִ�в���ʧ�ܣ��������롢ɾ�������ҵ�ʧ�ܣ���
����ַ���error���������������

��������
6 11 22 33 44 55 66
3 777
1 888
1
11
0
5

�������
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

