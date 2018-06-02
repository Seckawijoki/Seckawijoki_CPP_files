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
��Ŀ����
����һ��ͼ���ڽӾ��󣬶�ͼ������������������Ӷ���0��ʼ
ע�⣺ͼn�������Ŵ�0��n-1
���������£�

����
��һ������t����ʾ��t������ʵ��
�ڶ�������n����ʾ��1��ͼ��n�����
��������ÿ�������ڽӾ����һ�У��Դ���������n��
��i�����������������������Ϊ1����������Ϊ0��
����֮���ÿո����
�Դ�����������һ��ʾ��

���
ÿ�����һ��ͼ�Ĺ��������������������֮���ÿո����

��������
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

�������
0 2 3 1 
0 3 4 2 1 
*/
