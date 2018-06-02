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
   * @param remainedGraph ��������
   * @param start Դ��
   * @param end �յ�
   * @param path ·��
   * @return �Ƿ������rGraph���ҵ�һ���� s �� t ��·��
   */
bool hasPath(int **remainedGraph, int start, int end, int *path) {
	bool *visited = new bool[V_MAX];
	queue<int> q;
	q.push(start);
	visited[start] = true;
	//��׼��BFS�㷨
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
* @param graph ����ͼ�ľ����ʾ
* @param start Դ��
* @param end �յ�
* @return �������
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
	
	  //����·���е�ÿ����,�ҵ���С������
	  for(int v=end; v != start; v=path[v]){
	    s.push(v);
	    int u = path[v];
	    min_flow = min_flow < remainedGraph[u][v] ? min_flow : remainedGraph[u][v];
	  }s.push(0);
	
	  //����·���е�ÿ����
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
	  cout<<"������"<<min_flow<<endl;
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
	cout<<"���������"<<maxFlow(graph, 0, V_MAX-1)<<endl;
}

void KeyinEdges() {
	int v_number, n, v, u, weight;
	cout<<"��ֱ����붥�����������";
	cin>>v_number>>n;
	V_MAX = v_number;
	int **graph = new int*[V_MAX];
	for ( int i = 0 ; i < V_MAX ; ++i )
		graph[i] = new int [V_MAX];
	for ( int i = 0 ; i < n ; ++i ){
	   	cin>>v>>u>>weight;
	    graph[v][u] = weight;
	  }
	cout<<"���������"<<maxFlow(graph, 0, V_MAX-1)<<endl;
}

void onePossibleRunning() {
	int v_number;
	int **graph;
	cout<<"�����붥������";
	cin>>v_number;
	V_MAX = v_number;
	produceRandomGraph(graph);
	cout<<"���������"<<maxFlow(graph, 0, V_MAX-1)<<endl;
}
int main() {
	int choice;
	cout<<"1.��������ģʽ\n"
		<<"2.��-β-Ȩ�� ģʽ\n"
		<<"3.�������ͼ�����������\n" 
		<<"��ѡ������ģʽ��";
	cin>>choice;
	switch ( choice ){
		case 1:KeyinMatrix();break; 
		case 2:KeyinEdges();break;
		case 3:
		default:onePossibleRunning();break;
	}
	return 0;
}

