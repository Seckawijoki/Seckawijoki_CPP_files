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
题目描述
给出一个N*N的迷宫矩阵示意图，从起点[0,0]出发，寻找路径到达终点[N-1, N-1]
要求使用堆栈对象来实现，具体算法参考课本3.2.4节51页

输入
第一行输入t，表示有t个迷宫
第二行输入n，表示第一个迷宫有n行n列
第三行起，输入迷宫每一行的每个方格的状态，0表示可通过，1表示不可通过
输入n行
以此类推输入下一个迷宫

输出
逐个输出迷宫的路径
如果迷宫不存在路径，则输出no path并回车
如果迷宫存在路径，将路径中每个方格的x和y坐标输出，
从起点到终点，每输出四个方格就换行，最终以单词END结尾，
具体格式参考示范数据

输出的代码参考如下：
//path是保存路径的堆栈，堆栈中每个元素都包含x坐标和y坐标，用属性xp和yp表示
//path1是一个临时堆栈，把path的数据倒序输出到path1，使得路径按正序输出
if (!path.empty())	//找到路径
{	//......若干代码，实现path的数据导入path1
i=0;  //以下是输出路径的代码
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
cout<<"no path"<<endl; //找不到路径输出no path

样例输入
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
样例输出
[0,0]--[0,1]--[0,2]--[1,2]-- 
[1,3]--[2,3]--[3,3]--[3,4]-- 
[4,4]--[5,4]--[5,5]--[6,5]-- 
[6,6]--[7,6]--[7,7]--END 
no path 
*/
