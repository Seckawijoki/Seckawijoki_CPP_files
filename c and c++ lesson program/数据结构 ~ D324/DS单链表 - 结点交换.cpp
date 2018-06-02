# include <iostream>
using namespace std;
# define ERROR  -1
# define OK      0
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
          head = new ListNode ();
     }
     SingleLinkedList( int *array, int n )
     {
          int i;
          ListNode *p, *q;
          length = n;
          head = new ListNode ();
          p = head;
          for ( i = 0 ; i < length ; ++i )
          {
               q = new ListNode ();
               q->datum = array[i];
               p->next = q;
               p = q;
          }
     }
    ~SingleLinkedList()                   
	{
		ListNode *p , *q;
		q = head;
		while ( p != NULL )
		{
			p = q->next;
			delete q;
			q = p;
		}
		length = 0;
		head = NULL;
	}
     void SSL_Display()
     {
          int i;
          ListNode *p = head->next;
          for ( i = 1 ; i <= length ; ++i, p = p->next )
               cout<<p->datum<<' ';
          cout<<endl;
     }
     int SSL_Swap_Position( int pa, int pb )
     {
     	int i;
          if ( pa < 1 || pa > length ||
               pb < 1 || pb > length )return ERROR;
          ListNode *p = head, *q = head;
          for ( i = 1 ; i <= pa ; ++i )
               p = p->next;
          for ( i = 1 ; i <= pb ; ++i )
               q = q->next;
          SSL_Swap_Node(p,q);
          return OK;
     }
     void SSL_Swap_Node( ListNode *p, ListNode *q )
     {
        ListNode *t, *s, *temporary;
        if ( p->next == q )
        {
        	t = head;
            while ( t->next != p )
               t = t->next;
            s = q->next;
            t->next = q;
            q->next = p;
            p->next = s;
        }
        else if ( q->next == p )
        {
        	t = head;
            while ( t->next != q )
               t = t->next;
            t->next = p;
            p->next = q;
            q->next = s;
        }
        else
        {
		  t = head;
          s = head;
          while ( t->next != p )
               t = t->next;
          while ( s->next != q )
               s = s->next;
          temporary = q->next;
          q->next = p->next;
          p->next = temporary;
          t->next = q;
          s->next = p;
        } 
     }
};
int main()
{
     int n, i, result;
     int array[1024];
     cin>>n;
     for ( i = 0 ; i < n ; ++i )
          cin>>array[i];
     SingleLinkedList ssl(array,n);
     ssl.SSL_Display();
     
     cin>>i>>n;
     result = ssl.SSL_Swap_Position(i,n);
     if ( result == ERROR )cout<<"error\n";
     else ssl.SSL_Display();
     
     cin>>i>>n;
     result = ssl.SSL_Swap_Position(i,n);
     if ( result == ERROR )cout<<"error\n";
     else ssl.SSL_Display();
     
     ssl.SSL_Swap_Node(ssl.head->next,ssl.head->next->next);
     ssl.SSL_Display();
     return 0;
}
/*
��Ŀ����
��C++ʵ�ֺ�ͷ���ĵ�����Ȼ��ʵ�ֵ������������㽻��λ�á�
ע�ⲻ�ܼ򵥽����������������ݣ�����ͨ���޸�ָ����ʵ����������λ�ý���
��������������Բο���
swap��int  pa, int pb)  //pa��pb��ʾ��������ڵ������λ�����
swap (ListNode * p, ListNode * q)  //p��q��ʾָ����������ָ��

����
��1��������n��ʾ��n�����ݣ���������n������
��2������Ҫ�������������λ��
��3������Ҫ�������������λ��

���
��һ�����������������������ݣ�����֮���ÿո����
�ڶ������ִ�е�1�ν���������ĵ��������ݣ�����֮���ÿո����
���������ִ�е�2�ν���������ĵ��������ݣ�����֮���ÿո����
�����������λ�ò��Ϸ�������ַ���error���������������

��������
5 11 22 33 44 55
1 4
2 6

8 11 22 33 44 55 66 77 88 1 3 3 1

�������
11 22 33 44 55 
44 22 33 11 55 
error

��ʾ
ע��Ҫ������ʵ��Ŷ��
*/
