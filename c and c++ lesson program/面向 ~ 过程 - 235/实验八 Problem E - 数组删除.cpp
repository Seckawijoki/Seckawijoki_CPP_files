/*
Description
定义一个10个元素的整型数组，首先输入10个元素的值，
然后输入需要删除的元素的值，如果数组中存在该元素，
删除它，并输出删除后的数组的其余元素
（注意，数组元素之间以空格分隔，最后一个元素后换行）；
如果数组中不存在该元素，输出“Not found”。

Input
测试数据的组数n
第一组测试数据的10个元素
需要删除的值
第二组测试数据的10个元素
需要删除的值
.........

Output
删除指定元素后的数组输出
或
Not found

Sample Input
3
1 2 3 4 5 6 7 8 9 10
5
1 21 32 4 5 69 7 88 9 102
11
100 21 3 4 54 6 7 8 19 10
100

Sample Output
1 2 3 4 6 7 8 9 10
Not found
21 3 4 54 6 7 8 19 10

*/
# include <iostream> 
using namespace std; 
int main() 
{ 
    int n,i,x[10],y,a[10],tg,k[10],l; 
    cin>>n; 
    while ( n-- ) 
    { 
        l = 0; 
        tg = 0; 
        for ( i = 0 ; i < 10 ; i++ ) 
            cin>>x[i]; 
        cin>>y; 
        for ( i = 0 ; i < 10 ; i++ ) 
        { 
            if ( y == x[i] ) 
            { 
                l++; 
                tg++; 
            } 
            a[i] = x[i+l]; 
        } 
        if ( tg ) 
        { 
            for ( i = 0 ; i < 9 - l ; i++ ) 
                cout<<a[i]<<' '; 
            cout<<a[i]<<'\n'; 
        } 
        else 
            cout<<"Not found\n"; 
    } 
    return 0; 
} 
/************************************************************** 
    Problem: 1042 
    User: 2014150076 
    Language: C++ 
    Result: Accepted 
    Time:0 ms 
    Memory:1268 kb 
****************************************************************/