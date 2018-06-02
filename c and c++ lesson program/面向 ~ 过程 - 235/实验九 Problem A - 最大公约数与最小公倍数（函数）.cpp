/*
Description
写两个函数，分别求两个正整数的最大公约数和最小公倍数，在主函数中调用这两个函数，并输出结果。两个正整数由键盘输入。

Input

测试数据的组数n
第一组测试数据
第二组测试数据
.....
第n组测试数据

Output
第一组测试数据的最大公约数  第一组测试数据的最小公倍数
第二组测试数据的最大公约数  第二组测试数据的最小公倍数
......
第n组测试数据的最大公约数  第n组测试数据的最小公倍数

Sample Input
4
2 8
8 4
72 60
9 7

Sample Output
2 8
4 8
12 360
1 63


*/
# include <iostream> 
using namespace std; 
int zdgys( int a , int b ) 
{ 
    int r = 1; 
    while ( r ) 
    { 
        r = a %b; 
        a = b; 
        b = r;   
    } 
    return a; 
} 
int main() 
{ 
    int n,a,b,r; 
    cin>>n; 
    while ( n-- ) 
    { 
        cin>>a>>b; 
        if ( a < b ) 
        { 
            a = a + b; 
            b = a - b; 
            a = a - b;   
        } 
        r = zdgys(a,b); 
        cout<<r<<' '<<a*b/r<<endl; 
    } 
    return 0; 
} 
  
