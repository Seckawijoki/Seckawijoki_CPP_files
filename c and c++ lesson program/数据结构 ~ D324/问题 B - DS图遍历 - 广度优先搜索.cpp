# include <iostream>
# include <queue>
using namespace std;
const int Maxlength = 20;
class Graph{
private:
	bool visited[Maxlength];
	int matrix[Maxlength][Maxlength];
	int vertex;
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
				cout<<v<<' ';
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
							cout<<w<<' ';
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
	void SetMatrix( int chouten, int array[Maxlength][Maxlength] )
	{
		int i, j;
		vertex = chouten;
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
int main ()
{
	int t, n, i, j;
	int gyouretsu[Maxlength][Maxlength];
	Graph zu;
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		for ( i = 0 ; i < n ; ++i )
		for ( j = 0 ; j < n ; ++j )
			cin>>gyouretsu[i][j];
		zu.SetMatrix(n,gyouretsu);
		zu.BFSTraverse();
		cout<<endl;
	}
	return 0;
}
/*
题目描述
给出一个图的邻接矩阵，对图进行深度优先搜索，从顶点0开始
注意：图n个顶点编号从0到n-1
代码框架如下：

输入
第一行输入t，表示有t个测试实例
第二行输入n，表示第1个图有n个结点
第三行起，每行输入邻接矩阵的一行，以此类推输入n行
第i个结点与其他结点如果相连则为1，无连接则为0，
数据之间用空格隔开
以此类推输入下一个示例

输出
每行输出一个图的广度优先搜索结果，结点编号之间用空格隔开

样例输入
2
4
0 0 1 1
0 0 1 1
1 1 0 1
1 1 1 0
5
0 0 0 1 1
0 0 1 0 0
0 1 0 1 1
1 0 1 0 0
1 0 1 0 0

样例输出
0 2 3 1 
0 3 4 2 1 
*/
