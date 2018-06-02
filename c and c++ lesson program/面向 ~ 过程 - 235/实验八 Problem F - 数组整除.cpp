/*
Description

输入20个整数，输出其中能被数组中其它元素整除的那些数组元素。


Input
Output
Sample Input
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
Sample Output
4
6
8
9
10
12
14
15
16
18
20
21
*/
# include <iostream> 
using namespace std; 
int main() 
{ 
    int i,j,x[40]; 
    for ( i = 0 ; i < 20 ; i++ ) 
    cin>>x[i]; 
    for ( i = 0 ; i < 20 ; i++ ) 
    { 
        for ( j = 0 ; j < 20 ; j++ ) 
        { 
            if ( i == j )  
                continue; 
            if ( x[i] %x[j] == 0 ) 
            { 
                cout<<x[i]<<endl; 
                break; 
            } 
        } 
    } 
    return 0; 
} 
/************************************************************** 
    Problem: 1043 
    User: 2014150076 
    Language: C++ 
    Result: Accepted 
    Time:0 ms 
    Memory:1268 kb 
****************************************************************/