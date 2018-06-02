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
��Ŀ����
��C++���Ժ���ʵ�ֵ�������ͷ���
���԰�����data������nextָ����
�������������롢ɾ��������
ע�⣺�����������飬����λ�ô�1��ʼ��Ӧ�׽�㣬ͷ��㲻������
�ඨ��ο�

����
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
���ִ�в���ʧ�ܣ��������롢ɾ�������ҵ�ʧ�ܣ�������ַ���error���������������

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
