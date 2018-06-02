/*
Description
定义一个10个元素的整型数组，输入10个整数到数组，对数组排序，然后输出。
注意：输出时，每个元素之间以空格相间，但最后一个元素后面没有空格，直接换行。

Input
测试数据的组数n
第一组测试数据
第二组测试数据
..........

Output
排序后的第一组数据
排序后的第二组数据
.........

Sample Input
2
23 1 -5 6 -9 8 7 65 99 -100
99 87 0 -34 -23 123 34 -59 81 -2

Sample Output
-100 -9 -5 1 6 7 8 23 65 99
-59 -34 -23 -2 0 34 81 87 99 123

*/
# include <iostream> 
using namespace std; 
int main() 
{ 
    int n,i,j,x[10]; 
    cin>>n; 
    while ( n-- ) 
    { 
        for ( i = 0 ; i < 10 ; i++ ) 
            cin>>x[i];     
        for ( i = 0 ; i < 10 ; i++ ) 
        { 
            for ( j = i + 1 ; j < 10 ; j++ ) 
            { 
                if ( x[i] > x[j] ) 
                { 
                    x[i] = x[i] + x[j]; 
                    x[j] = x[i] - x[j]; 
                    x[i] = x[i] - x[j]; 
                } 
            } 
        } 
        for ( i = 0 ; i < 10 ; i++ ) 
            i == 9 ? cout<<x[i]<<'\n' : cout<<x[i]<<' '; 
    } 
    return 0; 
} 
/************************************************************** 
    Problem: 1030 
    User: 2014150076 
    Language: C++ 
    Result: Accepted 
    Time:0 ms 
    Memory:1268 kb 
****************************************************************/
