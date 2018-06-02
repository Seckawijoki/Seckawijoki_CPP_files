/*
Description
定义一个大小为10的整型数组，让用户从键盘输入10个数据；
然后让用户输入一个数据，在数组中查找该数据第一次出现的位置，
找到了，输出该元素的下标，
找不到，输出“Not found”。

Input
测试数据的组数

第一组测试数据的10个元素的值
第一组要查找的值
第二组测试数据的10个元素的值
第二组要查找的值
.........

Output
输出查找的情况

Sample Input
3
11 22 33 44 55 66 7 8 9 100
55
12 34 56 78 -4 -5 -7 90 99 23
100
-9 56 91 92 90 38 39 21 34 61
61

Sample Output
4
Not found
9

*/
# include <iostream> 
using namespace std; 
int main() 
{ 
    int n,i,x[10],y,tg; 
    cin>>n; 
    while ( n-- ) 
    { 
        tg = 1; 
        for ( i = 0 ; i < 10 ; i++ ) 
            cin>>x[i];     
        cin>>y;    
        for ( i = 0 ; i < 10 ; i++ ) 
        { 
            if ( x[i] == y ) 
            { 
                tg--; 
                cout<<i<<endl; //看清要输出的下标。
                break; 
            } 
        } 
        if ( tg )  
            cout<<"Not found"<<endl; 
    } 
    return 0; 
} 
/************************************************************** 
    Problem: 1029 
    User: 2014150076 
    Language: C++ 
    Result: Accepted 
    Time:0 ms 
    Memory:1268 kb 
****************************************************************/