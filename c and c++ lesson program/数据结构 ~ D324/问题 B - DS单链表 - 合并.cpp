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
        ListNode *p , *q;
        int j , intruder;
        head = new ListNode ();
        length = size;
        p = head;
        for ( j = 1 ; j <= length ; j++ )
        {
            cin>>intruder;
            q = new ListNode ( intruder );
            p->next = q;
            p = q;
        }
    }
    int LL_Merging( LinkList la, LinkList lb )
    {
        ListNode *localist = head;
        ListNode *p = la.head->next;
        ListNode *q = lb.head->next;
        while ( p != NULL && q != NULL )
        {
            if ( p->datium < q->datium  )
            {
                localist->next = p;
                localist = p;
                p = p->next;
            }
            else//( p->datium > q->datium )
            {
                localist->next = q;
                localist = q;
                q = q->next;
            }
        }
        length = la.length + lb.length;
        localist->next = ( p != NULL ? p : q );
        return ok;
    }
    void LL_Display()
    {
        ListNode *p;
        int j;
        p = head;
        for ( j = 1 ; j <= length ; j++ )
        {
            p = p->next;
            cout<<p->datium<<' ';
        }
        cout<<endl;
    }
};
int main()
{
    int m;
    cin>>m;
    LinkList chain1(m);
    cin>>m;
    LinkList chain2(m);
     
    LinkList chain3;
    chain3.LL_Merging( chain1 , chain2 );
    chain3.LL_Display();
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
3 11 33 55 4 22 44 66 88
样例输出
11 22 33 44 55 66 88 
*/
