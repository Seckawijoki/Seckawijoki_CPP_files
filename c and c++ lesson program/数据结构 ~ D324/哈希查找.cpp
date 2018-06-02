# include <iostream>
using namespace std;
# define ERROR -1
const int mode = 11;
class ListNode
{
public:
	ListNode *next;
	int datum;
	ListNode()
	{
		next = NULL;
	}
};
class ListSite
{
private:
	ListNode **head;
public:
	ListSite()
	{
		int i;
		head = new ListNode* [mode];
		for ( i = 0 ; i < mode ; ++i )
			head[i] = new ListNode ();
	}
	void ListSite_Insert( int item )
	{
		ListNode *p, *q;
		q = head[item%mode]->next;
		p = new ListNode ();
		p->datum = item;
		p->next = q;
		head[item%mode]->next = p;
	}
	int ListSite_Search( int item, int &times )
	{
		ListNode *p;
		p = head[item%mode];
		times = 0;
		while ( p->next != NULL )
		{
			p = p->next;
			++times;
			if ( p->datum == item )return times;
		}
		return ERROR;
	}
	void ListSite_Display()
	{
		int i;
		ListNode *p;
		for ( i = 0 ; i < mode ; ++i )
		{
			cout<<"head["<<i<<"]";
			p = head[i];
			if ( p->next == NULL )cout<<"->null\n";
			if ( p->next == NULL )continue;
			do
			{
				p = p->next;
				cout<<"->"<<p->datum;
			}while  ( p->next != NULL );
			cout<<endl;
		}
	}
};
int main()
{
	int n, item, times, result;
	ListSite hashtable;
	cin>>n;
	while ( n-- )
	{
		cin>>item;
		hashtable.ListSite_Insert(item);
	}
	cin>>n;
//	hashtable.ListSite_Display();
	while ( n-- )
	{
		cin>>item;
		result = hashtable.ListSite_Search(item,times);
		if ( result == ERROR )
		{
			cout<<"error\n";
			hashtable.ListSite_Insert(item);
		}
		else cout<<item%mode<<' '<<times<<endl;
	}
//	hashtable.ListSite_Display();
	return 0;
}
/*
题目描述
给出一个数据序列，建立哈希表，采用求余法作为哈希函数，模数为11，哈希冲突用链地址法和表头插入
如果首次查找失败，就把数据插入到相应的位置中
实现哈希查找功能

输入
第一行输入n，表示有n个数据
第二行输入n个数据，都是自然数且互不相同，数据之间用空格隔开
第三行输入t，表示要查找t个数据
从第四行起，每行输入一个要查找的数据，都是正整数

输出
每行输出对应数据的查找结果

样例输入
6
11 23 39 48 75 62
6
39
52
52
63
63
52

样例输出
6 1
error
8 1
error
8 1
8 2

提示
注意，当两次输入要相同的查找数据，如果第一次查找不成功就会执行插入，那么第二次查找必然成功，且查找次数为1次（因为做表头插入）
例如示例数据中输入两次52，第一次查找失败就把52插入到位置8，第二次查找就成功了，所以第一次输出error，第二次就输出8 1
为什么第三次输入52会输出8 2
*/
