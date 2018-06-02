# include <iostream>
using namespace std;
# define ERROR  -1
# define OK      0
class ListNode
{
public:
     int datum;
     ListNode *next;
     ListNode()
     {
     	next = NULL;
     }
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
     SingleLinkedList( int array[], int n )
     {
          length = n;
          head = new ListNode ();
          int i;
          ListNode *p, *q;
          p = head;
          for ( i = 0 ; i < length ; ++i )
          {
               q = new ListNode ();
               q->datum = array[i];
               p->next = q;
               p = q;
          }
     }/*
     ~SingleLinkedList()
     {
          ListNode *p = head, *q;
          while ( p != NULL )
          {
               q = p;
               p = p->next;
               delete q;
          }
          length = 0;
          head = NULL;
     }*/
     void SSL_Display()
     {
          int i;
          ListNode *p = head->next;
          for ( i = 1 ; i <= length ; ++i, p = p->next )
               cout<<p->datum<<' ';
          cout<<endl;
     }
     void SSL_Merge( SingleLinkedList ssl1, SingleLinkedList ssl2 )
     {
     	ListNode *p = ssl1.head->next;
		ListNode *q = ssl2.head->next;
		ListNode *t = head;
     	while ( p != NULL  && q != NULL )
     	{
     		if ( p->datum < q->datum )
     		{
     			t->next = p;
     			t = p;
     			p = p->next;
     		}
     		else
     		{
     			t->next = q;
     			t = q;
     			q = q->next;
     		}
     	}
     	t->next = ( p != NULL ? p : q );
     	length = ssl1.length + ssl2.length;
     }
};
int main()
{
     int n, i;
     int array[1024];
     
     cin>>n;
     for ( i = 0 ; i < n ; ++i )
          cin>>array[i];
     SingleLinkedList ssl1(array,n);
//     ssl1.SSL_Display();
     
     cin>>n;
     for ( i = 0 ; i < n ; ++i )
          cin>>array[i];
     SingleLinkedList ssl2(array,n);
//     ssl2.SSL_Display();
     
     SingleLinkedList ssl3;
     ssl3.SSL_Merge(ssl1,ssl2);
     ssl3.SSL_Display();
     
     return 0;
}
/*
题目描述
假定两个单链表是递增有序，定义并实现以下函数，完成两个单链表的合并，继续保持递增有序
int LL_merge(ListNode *La, ListNode *Lb)

输入

第1行先输入n表示有n个数据，接着输入n个数据
第2行先输入m表示有M个数据，接着输入m个数据

输出
输出合并后的单链表数据，数据之间用空格隔开

样例输入
3 11 33 55
4 22 44 66 88

样例输出
11 22 33 44 55 66 88 
*/
