/*
Description
����һ�����źõ�9��Ԫ�ص����飬������һ����Ҫ��ԭ������Ĺ��ɽ������������С�

Input
��һ�У�ԭʼ���С� �ڶ��У���Ҫ��������֡�

Output
����������

Sample Input
1 7 8 17 23 24 59 62 101
50
Sample Output
1
7
8
17
23
24
50
59
62
101

*/
# include <iostream> 
using namespace std; 
int main() 
{ 
    int i,x[10],y; 
    for ( i = 0 ; i < 9 ; i++ ) 
        cin>>x[i]; 
    cin>>y; 
    for ( i = 8 ; i >= 0 ; i-- ) 
    { 
        if ( y < x[i] ) 
            x[i+1] = x[i]; 
        else if ( y >= x[i] ) 
        { 
            x[i+1] = y; 
            break; 
        } 
    } 
    for ( i = 0 ; i < 10 ; i++ ) 
        cout<<x[i]<<"\n"; 
    return 0; 
} 
/************************************************************** 
    Problem: 1031 
    User: 2014150076 
    Language: C++ 
    Result: Accepted 
    Time:0 ms 
    Memory:1268 kb 
****************************************************************/