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
��Ŀ����
����һ��ͼ���ڽӾ��󣬶�ͼ������������������Ӷ���0��ʼ
ע�⣺ͼn�������Ŵ�0��n-1
���������£�

����
��һ������t����ʾ��t������ʵ��
�ڶ�������n����ʾ��1��ͼ��n�����
��������ÿ�������ڽӾ����һ�У��Դ���������n��
��i�����������������������Ϊ1����������Ϊ0������֮���ÿո����
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
