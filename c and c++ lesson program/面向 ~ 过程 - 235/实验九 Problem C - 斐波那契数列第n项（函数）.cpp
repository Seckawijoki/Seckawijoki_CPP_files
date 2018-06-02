/*
Description
斐波那契数列的定义如下：
F_0=0 
F_1=1 
F_n = F_{n-1}+ F_{n-2} 
也就是说，斐波那契数列由0 和1开始，
之后的每一项是之前的两数相加，例如:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,...
要求用函数实现，求斐波那契数列第n项的值。
（不能使用递归函数）

Input
n

Output
斐波那契数列在第n项的值

Sample Input
8
Sample Output
21
*/
# include <iostream> 
using namespace std;  
int fbnqsl( int n ) 
{ 
    int i,x[50] = {0,1}; 
    for ( i = 2 ; i <= n ; i++ ) 
        x[i] = x[i-1] + x[i-2]; 
    cout<<x[n]<<endl; 
    return 1; 
} 
int main() 
{ 
    int x; 
    cin>>x; 
    fbnqsl(x); 
    return 0; 
} 
