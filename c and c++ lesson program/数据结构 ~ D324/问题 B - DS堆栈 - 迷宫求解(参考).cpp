#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stack>
using namespace std;
 
int map[500][500];
int vis[500][500];
int dir[][2] = { 1, 0, 
				 0, 1, 
				-1, 0, 
				 0,-1};
int n;
 
struct Pos{
    int x,y;
};
stack <Pos> st;
 
int check(int x,int y){
    if(x>n || y>n) return 0; 
    if(x<1 || y<1) return 0;
    if(map[x][y]==1) return 0;
    return 1;
}
int findroad(int x,int y)
{
    Pos pos;
    do{
        if(check(x,y) && !vis[x][y]){
            pos.x=x,pos.y=y;
            st.push(pos);
            vis[x][y]=1;
             
            if(x==n && y==n)
                return 1;
            else
                y++;
        }
        else
        {
            if(!st.empty()){
                int flag=0;
                for(int k=0;k<4;k++){
                    pos = st.top();
                    pos.x = pos.x+dir[k][0];
                    pos.y = pos.y+dir[k][1];
                    if(check(pos.x,pos.y) && !vis[pos.x][pos.y]){
                        x = pos.x, y = pos.y;
                        flag=1;
                        break;
                    }
                }
                if(flag==0) {
                    st.pop();
                }
            }
        }
    }
    while(!st.empty());
    return 0;
}
 
void print(){
    stack<Pos> tran;
    Pos temp;
    while(!st.empty()){
        temp = st.top();
        tran.push(temp);
        st.pop();
    }
 
    int cnt=0;
    while(!tran.empty()){
        temp = tran.top();
        tran.pop();
         
        printf("[%d,%d]--",temp.x-1,temp.y-1);
        cnt++;
        if(cnt==4)
        {
            cout<<endl;
            cnt=0;
        }
    }
    cout<<"END"<<endl;
}
int main()
{
    int i,j,k,t,m;
    int tt;
    cin>>tt;
    while(tt--){
    while(!st.empty())
        st.pop();
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }  
    if(findroad(1,1)==1)
        print();
    else
        cout<<"no path"<<endl;
    }
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
