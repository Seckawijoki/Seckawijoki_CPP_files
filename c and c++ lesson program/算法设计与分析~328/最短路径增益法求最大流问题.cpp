# include <iostream>
# include <queue>
# include <stack> 
# include <iomanip>
# include <cstdlib>
# include <time.h>
using namespace std;
const int max_weight = 100;
const int max_size = 32;
int V_MAX = 6;
  /**
   * @param remainedGraph 残留网络
   * @param start 源点
   * @param end 终点
   * @param path 路径
   * @return 是否可以在rGraph中找到一条从 s 到 t 的路径
   */
bool hasPath(int **remainedGraph, int start, int end, int *path) {
	bool *visited = new bool[V_MAX];
	queue<int> q;
	q.push(start);
	visited[start] = true;
	//标准的BFS算法
	while(q.size() > 0){
	  int top = q.front();
	  for(int i=0; i<V_MAX; i++){
	    if(!visited[i] && remainedGraph[top][i] > 0){
	      q.push(i);
	      visited[i] = true;
	      path[i] = top;
	    }
	
	  }
	}
	return visited[end] == true;
}

/**
* 
* @param graph 有向图的矩阵表示
* @param start 源点
* @param end 终点
* @return 最大流量
*/
int maxFlow(int **graph,int start, int end) {
	int **remainedGraph = new int*[V_MAX];
	for(int i=0; i<V_MAX; i++){
		remainedGraph[i] = new int[V_MAX];
		for(int j=0; j<V_MAX; j++)
			remainedGraph[i][j] = graph[i][j];
	}
	
	int maxFlow = 0;
	
	int *path = new int[V_MAX];
	while(hasPath(remainedGraph, start, end, path)){
	  stack <int> s;
	  int min_flow = 2<<31;
	
	  //更新路径中的每条边,找到最小的流量
	  for(int v=end; v != start; v=path[v]){
	    s.push(v);
	    int u = path[v];
	    min_flow = min_flow < remainedGraph[u][v] ? min_flow : remainedGraph[u][v];
	  }s.push(0);
	
	  //更新路径中的每条边
	  for(int v=end; v != start; v=path[v]){
	    int u = path[v];
	    remainedGraph[u][v] -= min_flow; 
	    remainedGraph[v][u] += min_flow;
	  }
	  maxFlow += min_flow;
	  while ( !s.empty() ){
	    cout<<s.top()<<" -> ";
	    s.pop();
	  }
	  cout<<"流量："<<min_flow<<endl;
	}
	
	
	for ( int i = 0 ; i < V_MAX ; ++i )
		delete []remainedGraph[i];
	delete []remainedGraph;
	delete []path;
	return maxFlow;
}

void printMatrix(int **graph){
	for ( int i = 0 ; i < V_MAX ; ++i ){
		for ( int j = 0 ; j < V_MAX ; ++j )
			cout<<setw(9)<<graph[i][j];
		cout<<endl; 
	}
} 

void produceRandomGraph(int **graph){
	graph = new int *[V_MAX];
	for ( int i = 0 ; i < V_MAX ; ++i )
		graph[i] = new int [V_MAX];
	int _01value;
	for ( int i = 0 ; i < V_MAX - 1 ; ++i ){
		graph[i][0] = 0;
		for ( int j = 1 ; j < V_MAX ; ++j ){
			if ( rand() %2 == 1 ){
				graph[i][j] = 1 + (int)((double)rand() /RAND_MAX * max_weight);
				graph[i][j] = rand() %max_weight;
			}
		}
	}
	for ( int j = 0 ; j < V_MAX ; ++j )
		graph[V_MAX-1][j] = 0;
	printMatrix(graph);
}

void KeyinMatrix() {
	int v_number, v, u, weight;
	cin>>v_number;
	V_MAX = v_number;
	int **graph = new int*[V_MAX];
	for ( int i = 0 ; i < V_MAX ; ++i ){
		graph[i] = new int [V_MAX];
		for ( int j = 0 ; j < V_MAX ; ++j )
			cin>>graph[i][j];
	}
	cout<<"最大流量："<<maxFlow(graph, 0, V_MAX-1)<<endl;
}

void KeyinEdges() {
	int v_number, n, v, u, weight;
	cout<<"请分别输入顶点数与边数：";
	cin>>v_number>>n;
	V_MAX = v_number;
	int **graph = new int*[V_MAX];
	for ( int i = 0 ; i < V_MAX ; ++i )
		graph[i] = new int [V_MAX];
	for ( int i = 0 ; i < n ; ++i ){
	   	cin>>v>>u>>weight;
	    graph[v][u] = weight;
	  }
	cout<<"最大流量："<<maxFlow(graph, 0, V_MAX-1)<<endl;
}

void onePossibleRunning() {
	int v_number;
	int **graph;
	cout<<"请输入顶点数：";
	cin>>v_number;
	V_MAX = v_number;
	produceRandomGraph(graph);
	cout<<"最大流量："<<maxFlow(graph, 0, V_MAX-1)<<endl;
}
int main() {
	int choice;
	cout<<"1.矩阵输入模式\n"
		<<"2.首-尾-权重 模式\n"
		<<"3.随机生成图（输入点数）\n" 
		<<"请选择输入模式：";
	cin>>choice;
	switch ( choice ){
		case 1:KeyinMatrix();break; 
		case 2:KeyinEdges();break;
		case 3:
		default:onePossibleRunning();break;
	}
	return 0;
}

