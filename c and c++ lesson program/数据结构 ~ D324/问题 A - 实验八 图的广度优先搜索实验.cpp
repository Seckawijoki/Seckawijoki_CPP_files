# include <iostream>
# include <queue>
using namespace std;
const int Maxlength = 20;
class Graph{
private:
	bool visited[Maxlength];
	int matrix[Maxlength][Maxlength];
	int vertex;
	char character[Maxlength];
	void DFS( int v )
	{
		int w, i, k;
		int *adjacent = new int [vertex];
		visited[v] = true;
		cout<<v<<' ';
		
		for ( i = 0 ; i < vertex ; ++i )
			adjacent[i] = -1;
		k = 0;
		for ( i = 0 ; i < vertex ; ++i )
		if ( matrix[v][i] && v != i ) adjacent[k++] = i;
		
		i = 0;
		for ( w = adjacent[i] ; w != -1 ; )
		{
			if ( !visited[w] )	DFS(w);
			w = adjacent[i++];
		}
		delete [] adjacent;
	}
	void BFS( int v )
	{
		int w, u, i, j, k;
		int *adjacent = new int [vertex];
		queue<int> q;	
		
		for ( v = 0 ; v < vertex ; ++v )
		{
			if ( ! visited[v] )
			{
				visited[v] = true;
				cout<<character[v]<<' ';
				q.push(v);
				while ( !q.empty() )
				{
					u = q.front();
					q.pop();
					k = 0;
					for ( i = 0 ; i < vertex ; ++i )
						adjacent[i] = -1;
					for ( i = 0 ; i < vertex ; ++i )
					if ( matrix[u][i] && u != i )
						adjacent[k++] = i;
					
					i = 0;
					for ( w = adjacent[i] ; w != -1 ; )
					{
						if ( !visited[w] )
						{
							visited[w] = true;
							cout<<character[w]<<' ';
							q.push(w);
						}
						w = adjacent[++i];
					}
				}
			}
		}
		delete [] adjacent;
	}
public:
	void SetMatrix( int chouten, int array[Maxlength][Maxlength], char letter[Maxlength] )
	{
		int i, j;
		vertex = chouten;
		for ( i = 0 ; i < Maxlength ; ++i )
			character[i] = letter[i];
		for ( i = 0 ; i < Maxlength ; ++i )
		for ( j = 0 ; j < Maxlength ; ++j )
			matrix[i][j] = 0;
		for ( i = 0 ; i < vertex ; ++i )
		for ( j = 0 ; j < vertex ; ++j )
			matrix[i][j] = array[i][j];
	}
	void DFSTraverse()
	{
		int visit;
		for ( visit = 0 ; visit < vertex ; ++visit )
			visited[visit] = false;
		for ( visit = 0 ; visit < vertex ; ++visit )
		if ( !visited[visit] ) DFS(visit);
	}
	void BFSTraverse()
	{
		int i;
		for ( i = 0 ; i < vertex ; ++i )
			visited[i] = false;
		BFS(0);
	}
};
int Searching( char item, char *array )
{
	int i;
	for ( i = 0 ; i < strlen(array) ; ++i )
		if ( item == array[i] )
			return i;
}
int main ()
{
	int  n, i, j, group, index1, index2;
	int gyouretsu[Maxlength][Maxlength];
	char ch1, ch2;
	char *node;
	Graph zu;
		cin>>n;
		node = new char [n];
		for ( i = 0 ; i < n ; ++i )
			cin>>node[i];
		for ( i = 0 ; i < n ; ++i )
		for ( j = 0 ; j < n ; ++j )
			gyouretsu[i][j] = 0;
		cin>>group;
		
		for ( i = 0 ; i < group ; ++i )
		{
			cin>>ch1>>ch2;
			index1 = Searching(ch1,node);
			index2 = Searching(ch2,node);
			gyouretsu[index1][index2] = 1;
		}
		
		zu.SetMatrix(n,gyouretsu,node);
		zu.BFSTraverse();
		cout<<endl;
	delete [] node;
	return 0;
}
/*
题目描述
1、问题描述
给定一个结点（始点），从它开始，对（连通）图中其它结点进行广度优先搜索。

2、算法
所有顶点访问标志visited[]设置为FALSE
从某顶点v0开始，访问v0，visited[v0]=TRUE，将v0插入队列Q
⑴、如果队列Q不空，则从队列Q头上取出一个顶点v,否则结束
⑵、依次找到顶点v的所有相邻顶点v’，如果visited[v’]==FALSE，则访问该顶点v’，然后将v’插入队列Q，并使visited[v’]=TRUE，
⑶、重复⑴，⑵

输入
第一行：样本顶点个数，假设为n。
第二行，n个顶点（用空格隔开）
第三行，图中边（或弧）的数目
第四行开始：每一行是边（弧）的两个顶点（用空格隔开）

输出
广度优先搜索的顶点序列（用空格隔开，回车前无空格）
从输入的第一个顶点开始（如例题中的’a’顶点）

样例输入
6
a b c d e f
10
a b
a e
a f
b c
b d
b f
c d
d f
e d
e f

样例输出
a b e f c d
*/
