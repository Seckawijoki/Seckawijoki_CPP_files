# include <iostream>
# include <cstdlib> 
using namespace std;
# define ERROR  -1
# define OK      0
class ListNode
{
public:
     long id;
     string name;
     string phone;
     string qq;
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
     SingleLinkedList( int n )
     {
          int i, j;
        string stringinput;
        long longinput;
        ListNode *p, *q, *t, *s;
        length = 0;
        head = new ListNode ();
        p = head;      
		for ( i = 1 ; i <= n ; ++i )
        {
        	cout<<"�����������"<<i<<"����ϵ�˵ČW̖���������֙C̖��QQ̖��"<<endl;
            q = new ListNode ();
            cin>>longinput;
            q->id = longinput;
            cin>>stringinput;
            q->name = stringinput;
            cin>>stringinput;
            q->phone = stringinput;
            cin>>stringinput;
            q->qq = stringinput;
            ++length;
           	j = 1;
           	t = head->next;
           	for ( ; t != NULL && longinput > t->id && j <= length ; ++j )
	           	t = t->next;
	        SSL_Insert(j,q);
        }
     }
     void CreateSingleLinkedList( int n )
     {
        int i, j;
        string stringinput;
        long longinput;
        ListNode *p, *q, *t, *s;
        length = 0;
        head = new ListNode ();
        p = head;      
		for ( i = 1 ; i <= n ; ++i )
        {
        	cout<<"�����������"<<i<<"����ϵ�˵ČW̖���������֙C̖��QQ̖��"<<endl;
            q = new ListNode ();
            cin>>longinput;
            q->id = longinput;
            cin>>stringinput;
            q->name = stringinput;
            cin>>stringinput;
            q->phone = stringinput;
            cin>>stringinput;
            q->qq = stringinput;
            ++length;
           	j = 1;
           	t = head->next;
           	for ( ; t != NULL && longinput > t->id && j <= length ; ++j )
	           	t = t->next;
	        SSL_Insert(j,q);
        }
     }
    ~SingleLinkedList()                   
	{
	//	/*
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
	//	*/
	}
     void SSL_Change_ID( int n, long bango )
     {
     	int i;
     	ListNode *p = head, *t, *copy;
     	
     	for ( i = 0 ; i < n ; ++i )
     		p = p->next;
     	copy = new ListNode ();
     	copy->id = bango;
     	copy->name = p->name;
     	copy->phone = p->phone;
     	copy->qq = p->qq;
     	SSL_Delete(n); 
		++length;   
        t = head->next;
        i = 1;
        for ( ; t != NULL && bango > t->id  && i <= length ; ++i )
	        t = t->next;
	    SSL_Insert(i,copy);	
     }
     void SSL_Change_Else( int n, string change, int type )
     {
     	int i;
     	ListNode *p = head;
     	for ( i = 0 ; i < n ; ++i )
     		p = p->next;
     	if ( type == 2 )		p->name = change;
     	else if ( type == 3 )	p->phone = change;
     	else if ( type == 4 )	p->qq = change;
     }
     void SSL_Search_Name( string namae )
     {
     	ListNode *p = head->next;
     	if ( p != NULL )do
		{
			if ( p->name == namae )
			{
				cout << "�W̖\t\t����\t\t�֙C̖\t\t\tQQ̖"<< endl;
				cout
				<< p->id<<'\t'
				<< p->name<<'\t'
				<< p->phone<<'\t'
				<< p->qq<<endl;
				return;
			}
			p = p->next;
     	}while ( p != NULL );
     	cout<<"�����ڸ���������ϵ�ˡ�\n";  
     }
     void SSL_Search_ID( long bango )
     {
     	ListNode *p = head;
     	if ( p != NULL )do
		{
			if ( p->id == bango )
			{
				cout << "�W̖\t\t����\t\t�֙C̖\t\t\tQQ̖"<< endl;
				cout
				<< p->id<<'\t'
				<< p->name<<'\t'
				<< p->phone<<'\t'
				<< p->qq<<endl;
				return;
			}
			p = p->next;
     	}while ( p != NULL );
     	cout<<"�����ڸ�ѧ�ŵ���ϵ�ˡ�\n"; 
     }
     void SSL_Insert( int n, ListNode *t )
     {
     	int i = 1;
     	ListNode *p = head, *q;
     	for ( i = 1 ; i < n ; ++i )
     		p = p->next;
     	q = p->next;
     	t->next = q;
     	p->next = t;
     }
     void SSL_Delete( int n )
     {
     	if ( n < 1 || n > length )
     	{
     		cout<<"��������\n";
			 return; 
     	}
     	else
     	{
	     	int i;
	     	ListNode *p = head, *q;
	     	for ( i = 1 ; i < n ; ++i )
	     		p = p->next; 
	     	q = p->next;
	     	p->next = q->next;
	     	--length;
	     	delete q;
   		}
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
            s = p->next;
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
    void SSL_Display()
	{
		int i = 1;
		ListNode *p = head->next;
		cout << "   �W̖\t\t����\t�֙C̖\t\tQQ̖" << endl;
		while ( p != NULL || i <= length )
		{
			cout<<'['<<i++<<']'<<' '
			<< p->id<<'\t'
			<< p->name<<'\t'
			<< p->phone<<'\t'
			<< p->qq<<endl;
			p = p->next;
		}
	}
};
int main()
{
	int choice, number, n;
	SingleLinkedList ssl;
	cout << "             ******************************************************" << endl;
	cout << "             *                     ��W��ͨӍ䛡�                 *" << endl;
	cout << "             *                                                    *" << endl;
	cout << "             *  1������ͨӍ�   2���g�[�M��   3���޸��M����Ϣ *" << endl;
	cout << "             *                                                    *" << endl;
	cout << "             *  4���h���M��   5������M��   6����������       *" << endl;
	cout << "             *                                                    *" << endl;
	cout << "             *  7���W̖����     8���˳�ͨӍ�                     *" << endl;
	cout << "             ******************************************************" << endl;
	do
	{
		cout << "Ոݔ���헲���ǰ����̖��";
		number = 0;
		cin>>choice;
		switch ( choice )
		{
			case 1: 
			{
				if ( number > 0 )break;
				 cout<<"��������ϵ������";
				 cin>>number;
				 ssl.CreateSingleLinkedList(number);
				 break;
			}
			case 2:
			{
				ssl.SSL_Display();
				break;
			}
			case 3:
			{
				int order; 
				cout<<"������Ҫ�޸ĵ���ϵ�˵���ţ�";
				cin>>n;
				if ( n < 1 || n > ssl.length ) 
				{
					cout<<"�����Ҫ�޸���ϵ�˵��������\n";
					break;
				}
				cout << "***************" << endl;
				cout << "*  1��ѧ��    *" << endl;
				cout << "*  2������    *" << endl;
				cout << "*  3���ֻ���  *" << endl;
				cout << "*  4��QQ��    *" << endl;
				cout << "***************" << endl;
				cout<<"������Ҫ�޸ĵ���ϵ�˵���Ϣ��ţ�";
				cin>>order;
				if ( order == 1 )
				{
					long bango;
					cout<<"������Ҫ�޸ĵ���ϵ�˵�ѧ�ţ�";
					cin>>bango;
					ssl.SSL_Change_ID(n,bango); 
				}
				else if ( order == 2 || order == 3 || order == 4 )
				{
					string change;
					/**/ if ( order == 2 )cout<<"������Ҫ�޸ĵ���ϵ�˵�������";
					else if ( order == 3 )cout<<"������Ҫ�޸ĵ���ϵ�˵��ֻ��ţ�";
					else if ( order == 4 )cout<<"������Ҫ�޸ĵ���ϵ�˵�QQ�ţ�";
					cin>>change;
					ssl.SSL_Change_Else(n,change,order); 
				}
				else
					cout<<"�������Ϣ�������\n";
				break;
			}
			case 4:
			{
				cout<<"������Ҫɾ������ϵ�˵���ţ�";
				cin>>n;
				if ( n < 1 || n > ssl.length )
					cout<<"�����Ҫɾ����ϵ�˵��������\n";
				else
					ssl.SSL_Delete(n); 
				break;
			}
			case 5:
			{
				int i = 1;
				ListNode *p, *t = new ListNode();
				string stringinput;
				long longinput;
				cout<<"����������Ҫ�������ϵ�˵ČW̖���������֙C̖��QQ̖��"<<endl;
				cin>>longinput;
				t->id = longinput;
				cin>>stringinput;
				t->name = stringinput;
				cin>>stringinput;
				t->phone = stringinput;
				cin>>stringinput;
				t->qq = stringinput;
				++ssl.length;
				p = ssl.head->next;
				for ( ; p != NULL && longinput > p->id && i <= ssl.length ; ++i )
					p = p->next;
				ssl.SSL_Insert(i,t);
			 	break;
			}
			case 6:
			{
				string namae;
				cout<<"������ҪѰ�ҵ���ϵ�˵�������"<<endl;
				cin>>namae;	
				ssl.SSL_Search_Name(namae);
				break; 
			}
			case 7:
			{
				long bango;
				cout<<"������ҪѰ�ҵ���ϵ�˵�ѧ�ţ�"<<endl;
				cin>>bango;	
				ssl.SSL_Search_ID(bango);
				break; 
			}
			case 8:break;
			default:
			{
				cout << "\n           ��!�]�д��x헣�����Ո����ݔ�룺";
				choice = 9999;
				break;
			}
		}
	}while ( choice != 8 );
	cout<<"�����˳�������������\n";
	return 0;
}
/*
1 5
12611 zhangsan 2222221111 111111222222
10402 lisi 3333332222 22222333333
12303 wangwu 444444333 3333344444
15044 zhaoritian 123456789 234567800
10023 zhaoc 5723462389 4645654
2
3
1
1
18888
5
18403 liuqi 462626246 475474574
2
3
4
4
3
5
18403 liuqi 462626246 475474574
6
zhaoritian
7
10023
8
*/ 
