# include <iostream>
# include <stack>
# include <cstring>
using namespace std;
class BinaryTree
{
private:
	char *treenode;	
	int nodes;
	int CalculatingLeaves( int m )
	{
		if ( treenode[m] != '0' && m <= nodes )
		{
			if ( ( treenode[2*m] == '0' && treenode[2*m+1] == '0' )
			|| ( 2*m > nodes ) )
				return 1;
			else
			{
				int l = 0;
				l += CalculatingLeaves(2*m);
				l += CalculatingLeaves(2*m+1);
				return l;
			}
		}
		else 
			return 0;
	}
	void InOrder( int m )
	{
		int j;
		char root = treenode[1];
		char *visited = new char [nodes+1];
		for ( j = 1 ; j <= nodes ; ++j )
			visited[j] = treenode[j];
		cout<<"+++++++++++++++++++++++++++++++++++\n";
		stack <char> st;
		cout<<"***********************************\n";
		j = m;
		while ( j >= 1 && ( treenode[j] != '0' || !st.empty() ) ) 
		{
			while ( j <= nodes && treenode[j] != '0' && visited[j] != '0' )
			{
				st.push(treenode[j]);
				visited[j] = '0';
				j *= 2;
			}
			j /= 2;
			if ( !st.empty() )
			{
				cout<<st.top()<<' ';
				if ( st.top() == root )
					j = 2 * m + 1;
				else
					j = 2 * j + 1;
				st.pop();
			}
		}
		cout<<"j = "<<j<<endl;
		delete [] visited;
	}
public:
	int leaves;
	BinaryTree()
	{
		treenode = NULL;
		nodes = 0;
	}
	BinaryTree( int n , char *array )
	{
		nodes = n;
		treenode = new char [nodes];
		for ( int i = 1 ; i <= nodes ; ++i )
			treenode[i] = array[i];
	}
	~BinaryTree()
	{
		if ( treenode != NULL )delete [] treenode;
	}
	void CalculatingLeaves()
	{
		leaves = CalculatingLeaves(1);
	}
	void InOrder()
	{
		InOrder(1);
	}
};
int main ()
{
	int i, n;
	char *list;
	cin>>n;
	list = new char [n+1];
	for ( i = 1 ; i <= n ; ++i )
		cin>>list[i];
	BinaryTree nishinponoki(n,list);
	nishinponoki.CalculatingLeaves();
	cout<<nishinponoki.leaves<<endl;
	nishinponoki.InOrder();
	cout<<endl;
	return 0;
}
/*
��Ŀ����
1����������
����һ�ð�˳��洢��ʽ�洢�Ķ����������и�������ö�������������Ҷ�ӵ���Ŀ��

2������������˵��
�š���˳��洢��ʽ�洢��������ÿ����㣬����0��ʾ�ս��
�ơ�����1��ʼ��ţ�����ȫ��������ʽ���У���
������Ϊi�Ľ�������ӣ������ӵı��Ϊ2i��
������Ϊi�Ľ�����Һ��ӣ����Һ��ӵı��Ϊ2i+1
�ǡ����磺A 0 B 0 0 C D�����У�
AΪ�������Ϊ1����B�����Ϊ3��ΪA���Һ��ӣ�
C�����Ϊ6��ΪB�����ӣ�D�����Ϊ7��ΪB���Һ���
�ȡ��жϵ�ǰ����Ƿ�Ϊ�յķ�����������˳��ʽ�洢�Ķ������Ľ����Ϊn��
�����ǰ�����Ϊi���򣺵�i>nʱ��i���Ϊ�ս�㣻
�����i�����ݲ��֣�i����Ӧ���ַ���Ϊ��0��ʱ��i���Ϊ�ս��

3��Ҫ��
�����õݹ飬ֻ�����Լ�������ջ��

����
��һ�У������������Ŀ�������ս�㣩
�ڶ��У�n������������ַ����ÿո���������ַ�0��ʾ�ս�㣩

���
��1�У�Ҷ����Ŀ
��2�У����������и��������У�����ÿո�����������һ�����֮��Ҳ���пո�

��������
7
C D A 0 B E F

�������
3
D B C E A F 
*/
