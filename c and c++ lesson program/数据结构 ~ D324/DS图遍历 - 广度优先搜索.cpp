# include <iostream>
# include <queue>
using namespace std;
const int Maxlength = 20;
class Graph
{
private:
	bool visited[Maxlength];
	int matrix[Maxlength][Maxlength];
	int vertex;
	void BFS( int v )
	{
		int i, k, u, w;
		int *adjacent = new int [vertex];
		queue <int> visiting;
		for ( i = 0 ; i < vertex ; ++i )
			visited[i] = false;
		for ( v = 0 ; v < vertex ; ++v )
		if ( visited[v] == false )
		{
			visited[v] = true;
			cout<<v<<' ';
			visiting.push(v);
			while ( visiting.empty() == false )
			{
				u = visiting.front();
				visiting.pop();
				for ( i = 0 ; i < vertex ; ++i )
					adjacent[i] = -1;
				for ( i = 0, k = 0 ; i < vertex ; ++i )
				if ( matrix[u][i] == 1 && i != u )
					adjacent[k++] = i;
				for ( i = 0, w = adjacent[i] ; w != -1 ; )
				{
					if ( visited[w] == false )
					{
						visited[w] = true;
						cout<<w<<' ';
						visiting.push(w);
					}
					w = adjacent[++i];
				}
			}
		}
		delete [] adjacent;
	}
public:
	void SetMatrix( int number, int array[Maxlength][Maxlength] )
	{
		int i, j;
		vertex = number;
		for ( i = 0 ; i < vertex ; ++i )
		for ( j = 0 ; j < vertex ; ++j )
			matrix[i][j] = array[i][j];
	}
	void BFSTraverse()
	{
		BFS(0);
		cout<<endl;
	}
};
int main()
{
	int t;
	cin>>t;
	while ( t-- )
	{
		int i, j, n;
		int array[Maxlength][Maxlength] = {0};
		cin>>n;
		for ( i = 0 ; i < n ; ++i )
		for ( j = 0 ; j < n ; ++j )
			cin>>array[i][j];
		Graph zu;
		zu.SetMatrix(n,array);
		zu.BFSTraverse();
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
第i个结点与其他结点如果相连则为1，无连接则为0，数据之间用空格隔开
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
