# include <iostream>
# include <queue>
using namespace std;
const int Maxlength = 20;
const int Maxdist = 99999;
class Graph
{
private:
	int matrix[Maxlength][Maxlength];
	int vertex;
	
public:
	void SetMatrix( int number, int array[Maxlength][Maxlength] )
	{
		int i, j;
		vertex = number;
		for ( i = 0 ; i < vertex ; ++i )
		for ( j = 0 ; j < vertex ; ++j )
		if ( array[i][j] )
			matrix[i][j] = array[i][j];
		else
			matrix[i][j] = Maxdist;
	}
	void ShortestPath_DIJ( int v0 )
	{
		int i, j, v, w, minimum;
		int *dist = new int [vertex];
		bool *final = new bool [vertex];
		int path[Maxlength][Maxlength];
		int length[Maxlength];
		for ( i = 0 ; i < vertex ; ++i )
		{
			final[i] = false;
			dist[i] = matrix[v0][i];
			length[i] = 2;
			for ( j = 1 ; j < vertex ; ++j )
				path[i][j] = -1;
			path[i][0] = v0;
			if ( i != v0 )path[i][1] = i;
		}
		dist[v0] = 0;
		final[v0] = true;
		for ( i = 1 ; i < vertex ; ++i )
		{
			minimum = Maxdist;
			for ( w = 0 ; w < vertex ; ++w )
			if ( final[w] == false && minimum > dist[w] )
			{
				v = w;
				minimum = dist[w];
			}
			final[v] = true;
			for ( w = 0 ; w < vertex ; ++w )
			if ( final[w] == false && minimum + matrix[v][w] < dist[w] )
			{
				++length[w];
				dist[w] = minimum + matrix[v][w];
				for ( j = 0 ; path[v][j] != -1 ; ++j )
					path[w][j] = path[v][j];
				path[w][j] = w;
			}
		}
		for ( i = 0 ; i < vertex ; ++i )
		if ( i != v0 )
		{
			cout<<v0<<'-'<<i<<'-'<<dist[i]<<"----[";
			for ( j = 0 ; path[i][j] != -1 ; ++j )
				cout<<path[i][j]<<' ';
			cout<<"]\n";
		}
		delete [] final;
		delete [] dist;
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
		cin>>n;
		zu.ShortestPath_DIJ(n);
	}
	return 0;
}
/*
��Ŀ����
����һ��ͼ���ڽӾ����ٸ���ָ������v0���󶥵�v0��������������·��
���������£�

����
��һ������t����ʾ��t������ʵ��
�ڶ�������n����ʾ��1��ͼ��n�����
��������ÿ�������ڽӾ����һ�У��Դ���������n��
��i�����������������������Ϊ1����������Ϊ0������֮���ÿո����
����������v0����ʾ��v0��������������·������
�Դ�����������һ��ʾ��

���
ÿ�����v0��ĳ���������̾�������·��
ÿ�и�ʽ��v0���-����������----[���·��]��������ο�ʾ������

��������
1
5
0 5 0 7 15
0 0 5 0 0
0 0 0 0 1
0 0 2 0 0
0 0 0 0 0
0

�������
0-1-5----[0 1 ]
0-2-9----[0 3 2 ]
0-3-7----[0 3 ]
0-4-10----[0 3 2 4 ]
*/
