# include <iostream>
using namespace std;
const int Maxlength = 20;
class Graph
{
private:
	bool visited[Maxlength];
	int matrix[Maxlength][Maxlength];
	int vertex;
	void DFS( int v )
	{
		int i, k, w;
		int *adjacent = new int [vertex];
		
		visited[v] = true;
		cout<<v<<' ';
		for ( i = 0 ; i < vertex ; ++i )
			adjacent[i] = -1;
		for ( i = 0, k = 0 ; i < vertex ; ++i )
		if ( matrix[v][i] == 1 && v != i )
			adjacent[k++] = i;
		
		for ( i = 0, w = adjacent[i] ; w != -1 ; )
		{
			if ( visited[w]  == false )
				DFS(w);
			w = adjacent[i++];
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
	void DFSTraverse()
	{
		int i;
		for ( i = 0 ; i < vertex ; ++i )
			visited[i] = false;
		for ( i = 0 ; i < vertex ; ++i )
		if ( visited[i] == false )
			DFS(i);
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
		zu.DFSTraverse();
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
ÿ�����һ��ͼ�����������������������֮���ÿո����

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
0 2 1 3 
0 3 2 1 4 
*/
