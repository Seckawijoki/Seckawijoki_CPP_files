# include <iostream>
# include <stack>
using namespace std;
# define TRUE   1
# define FALSE  0
int size;
int map[512][512];
int visited[512][512];
int direction[][2] = {1, 0, 
					  0, 1, 
				 	 -1, 0, 
					  0,-1};
struct Coordinate
{
	int ordinate;
	int abscissa;
};
stack <Coordinate> path;
int goingAlong( int transverse, int perpendicular )
{
	if ( transverse > size || perpendicular > size )
		return 0;
	if ( transverse < 1    || perpendicular < 1    )
		return 0;
	if ( map[transverse][perpendicular]  == 1 )
		return 0;
	return 1;
}
int ExploringPassablePath( int line, int row )
{
	Coordinate current;
	do
	{
		if ( goingAlong(line,row) && !visited[line][row] )
		{
			current.ordinate = line;
			current.abscissa = row;
			path.push(current);
			visited[line][row] = 1;
			if ( line >= size && row >= size )
			{
				path.pop();
				return 1;
			}
			else
				++row;
		}
		else
		{
			if ( !path.empty() )
			{
				int flag = 0, k = 0;
				for ( k = 0 ; k < 4 ; ++k )
				{
					current.ordinate = path.top().ordinate;
					current.abscissa = path.top().abscissa;
					current.ordinate += direction[k][0];
					current.abscissa += direction[k][1];
					if ( goingAlong(current.ordinate,current.abscissa) 
					&& 	  !visited[current.ordinate][current.abscissa] )
					{
						line = current.ordinate;
						row = current.abscissa;
						flag = 1;
						break;
					}
				}
				if ( flag == 0 )
					path.pop();
			}
		}
	}while ( !path.empty() );
	return 0;
}
void DisplayingPassablePath()
{
	stack <Coordinate> storage;
	Coordinate copy;
	while ( !path.empty() )
	{
		storage.push(path.top());
		path.pop();
	}
	while ( !storage.empty() )
	{
		cout<<'('<<storage.top().ordinate<<','<<storage.top().abscissa<<"),";
		storage.pop();
	}
	cout<<'('<<size<<','<<size<<")\n";
}
int main()
{
	int t, i, j;
   		while( !path.empty() )
        	path.pop();
		cin>>size;
		for ( i = 1 ; i <= size ; ++i )
		for ( j = 1 ; j <= size ; ++j )
			cin>>map[i][j];
		for ( i = 1 ; i <= size ; ++i )
		for ( j = 1 ; j <= size ; ++j )
			visited[i][j] = 0;
		if ( ExploringPassablePath(1,1) == 1 )
			DisplayingPassablePath();
		else
			cout<<"no path\n";
 	return 0;
}
/*
��Ŀ����
����һ��N*N���Թ�����ʾ��ͼ�������[0,0]������Ѱ��·�������յ�[N-1, N-1]
Ҫ��ʹ�ö�ջ������ʵ�֣������㷨�ο��α�3.2.4��51ҳ

����
��һ������t����ʾ��t���Թ�
�ڶ�������n����ʾ��һ���Թ���n��n��
�������������Թ�ÿһ�е�ÿ�������״̬��0��ʾ��ͨ����1��ʾ����ͨ��
����n��
�Դ�����������һ���Թ�

���
�������Թ���·��
����Թ�������·���������no path���س�
����Թ�����·������·����ÿ�������x��y���������
����㵽�յ㣬ÿ����ĸ�����ͻ��У������Ե���END��β��
�����ʽ�ο�ʾ������

����Ĵ���ο����£�
//path�Ǳ���·���Ķ�ջ����ջ��ÿ��Ԫ�ض�����x�����y���꣬������xp��yp��ʾ
//path1��һ����ʱ��ջ����path�����ݵ��������path1��ʹ��·�����������
if (!path.empty())	//�ҵ�·��
{	//......���ɴ��룬ʵ��path�����ݵ���path1
i=0;  //���������·���Ĵ���
while (!path1.empty())
{	cpos = path1.top();
if ( (++i)%4 == 0 ) 
cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;
else
cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";
path1.pop();
}
cout<<"END"<<endl;
}
else
cout<<"no path"<<endl; //�Ҳ���·�����no path

��������
2 
8 
0 0 0 1 1 1 1 1 
1 0 0 0 1 0 0 1 
1 0 0 0 1 0 0 0 
1 1 0 0 0 0 0 1 
0 0 1 1 0 1 1 0 
0 0 0 0 0 0 1 1 
1 1 1 1 1 0 0 1 
0 0 0 0 1 0 0 0 
7 
0 0 0 1 1 1 1 
1 0 0 1 0 0 1 
1 0 0 1 0 0 0 
1 1 0 0 0 0 1 
0 0 1 1 0 1 0 
1 0 0 0 0 1 0 
0 0 0 0 1 1 0
�������
[0,0]--[0,1]--[0,2]--[1,2]-- 
[1,3]--[2,3]--[3,3]--[3,4]-- 
[4,4]--[5,4]--[5,5]--[6,5]-- 
[6,6]--[7,6]--[7,7]--END 
no path 
*/
