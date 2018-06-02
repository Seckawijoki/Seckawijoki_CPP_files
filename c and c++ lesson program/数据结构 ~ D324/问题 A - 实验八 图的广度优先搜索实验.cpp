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
��Ŀ����
1����������
����һ����㣨ʼ�㣩��������ʼ���ԣ���ͨ��ͼ�����������й������������

2���㷨
���ж�����ʱ�־visited[]����ΪFALSE
��ĳ����v0��ʼ������v0��visited[v0]=TRUE����v0�������Q
�š��������Q���գ���Ӷ���Qͷ��ȡ��һ������v,�������
�ơ������ҵ�����v���������ڶ���v�������visited[v��]==FALSE������ʸö���v����Ȼ��v���������Q����ʹvisited[v��]=TRUE��
�ǡ��ظ��ţ���

����
��һ�У������������������Ϊn��
�ڶ��У�n�����㣨�ÿո������
�����У�ͼ�бߣ��򻡣�����Ŀ
�����п�ʼ��ÿһ���Ǳߣ��������������㣨�ÿո������

���
������������Ķ������У��ÿո�������س�ǰ�޿ո�
������ĵ�һ�����㿪ʼ���������еġ�a�����㣩

��������
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

�������
a b e f c d
*/
