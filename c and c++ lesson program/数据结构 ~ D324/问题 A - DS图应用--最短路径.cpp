# include <iostream>
# include <cstdio>
using namespace std;
const int Longest = 20;
const int Infinity = 9999;
class Graph
{
private:
	int matrix[Longest][Longest];
	int vertex;
public:
	void SetMatrix( int point, int array[Longest][Longest] )
	{
		int i, j;
		vertex = point;
		for ( i = 0 ; i < vertex ; ++i )
		for ( j = 0 ; j < vertex ; ++j )
			matrix[i][j] = Infinity;
		for ( i = 0 ; i < vertex ; ++i )
		for ( j = 0 ; j < vertex ; ++j )
		if ( array[i][j] )
			matrix[i][j] = array[i][j];
	}
	void ShortestPath_DIJ( int v0 )
	{
		int i, j, k, v, w, min;
		int *dist = new int [vertex];
		bool *final = new bool [vertex];
		int path[Longest][Longest];
		int length[Longest];
		
		for ( i = 0 ; i < vertex ; ++i )
			final[i] = false;
		for ( i = 0 ; i < vertex ; ++i )
			dist[i] = matrix[v0][i];
		
		for ( i = 0 ; i < vertex ; ++i )
		for ( j = 0 ; j < vertex ; ++j )
			path[i][j] = -1;
			
		
		for ( i = 0 ; i < vertex ; ++i )
		{
			path[i][0] = v0;
			if ( i != v0 )
			path[i][1] = i;
		}
		for ( i = 0 ; i < vertex ; ++i )
			length[i] = 2;
		
		dist[v0] = 0;
		final[v0] = true;
		//��ʼ��ѭ���� 
		for ( i = 1 ; i < vertex ; ++i )
		{
			min = Infinity;
			for ( w = 0 ; w < vertex ; ++w )
			if ( !final[w] ) if ( dist[w] < min )
			{
				v = w;
				min = dist[w];
			}
			final[v] = true;
			for ( w = 0 ; w < vertex ; ++w )
			if ( !final[w] && ( min + matrix[v][w] ) < dist[w] )
			{
				++length[w];
				dist[w] = min + matrix[v][w];
				for ( j = 0 ; path[v][j] != -1 ; ++j )
					path[w][j] = path[v][j];
				path[w][j] = w;
			}
			
			cout<<"==============path��"<<i<<"��==============\n";
			for ( k = 0 ; k < vertex ; ++k, cout<<endl )
			for ( j = 0 ; j < vertex ; ++j )
				printf("%3d",path[k][j]);
			cout<<"--------------dist��"<<i<<"��--------------\n";
			for ( j = 0 ; j < vertex ; ++j )
				printf("%d  ",dist[j]);
			cout<<"\n****************************************\n";
			
		}
		
		for ( i = 0 ; i < vertex ; ++i )
		{
			if ( i != v0 )
			{
				cout<<v0<<'-'<<i<<'-';
				cout<<dist[i]<<"----[";
				for ( j = 0 ; path[i][j] != -1 ; ++j )
					cout<<path[i][j]<<' ';
				cout<<"]\n";
			}
		}
		delete [] dist;
		delete [] final;
	}
};
int main ()
{
	int i, j, t;
	int point, v0;
	int array[Longest][Longest] = {0};
	Graph zu;
	cin>>t;
	while ( t-- )
	{
		cin>>point;
		for ( i = 0 ; i < point ; ++i )
		for ( j = 0 ; j < point ; ++j )
			cin>>array[i][j];
		zu.SetMatrix(point,array);
		cin>>v0;
		zu.ShortestPath_DIJ(v0);
	}
	return 0;
}
/*
��Ŀ����
����һ��ͼ���ڽӾ����ٸ���ָ������v0��
�󶥵�v0��������������·��

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
