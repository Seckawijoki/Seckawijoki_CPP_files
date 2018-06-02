/*
Description
定义一个大小为10的整型数组，从键盘任意输入10个数据存入数组，统计负数的个数。

Input
测试数据的组数n
第一组测试数据
第二组测试数据

........

第n组测试数据

Output
第一组测试数据中负数的个数
第二组测试数据中负数的个数
.......
第n组测试数据中负数的个数

Sample Input
3
-1 3 4 -10 -5 -90 7 8 0 -2
5 6 -32 -9 12 23 -46 -65 -70 -100
-2 -3 -4 -6 7 8 12 2 34 12

Sample Output
5
6
4
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
            if (i == j)  
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