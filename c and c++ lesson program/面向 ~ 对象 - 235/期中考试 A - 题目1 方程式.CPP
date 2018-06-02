/*
题目描述
建立一个类Equation，两个整数数据成员a、b，表达方程ax+b=0。为类编写以下成员函数：
void set( int m,int n )，m、n分别用于修改a、b的值；
int root( double &x )，若方程有解(a!=0)，返回1且将解置于x中，否则返回0；

输入
第一行输入t表示有t个测试实例
第一组a、b
……
第t组a、b

输出
如果方程有解，输出解，否则输出None

样例输入
2
1 2
0 3
样例输出
-2
None
*/
# include <iostream> 
using namespace std; 
class SimpleEquation 
{ 
private: 
    int a; 
    int b; 
    double root; 
public: 
    SimpleEquation() 
    { 
        a = 1; 
        b = 1; 
        root = 1; 
    } 
    SimpleEquation( int m , int n ) 
    { 
        a = m; 
        b = n; 
    } 
    void SetA( int m ){a = m;} 
    void SetB( int n ){b = n;} 
    void SetRoot( double x ){root = x;} 
    double GetRoot(){return root;} 
    void SetAB( int m , int n ) 
    { 
        a = m; 
        b = n; 
    } 
    int RootOfSurvival( SimpleEquation &some ) 
    { 
        if ( some.a != 0 ) 
        { 
            some.SetRoot(double(-b)/a); 
            return 1; 
        } 
        else
            return 0; 
    } 
    void RootOfDisplay( SimpleEquation &some ) 
    { 
        if ( some.RootOfSurvival(some) == 1 ) 
            cout<<some.GetRoot()<<endl; 
        else
            cout<<"None\n"; 
    } 
}; 
int main() 
{ 
    int t,m,n; 
    cin>>t; 
    while ( t-- ) 
    { 
        cin>>m>>n; 
        SimpleEquation some(m,n); 
        some.RootOfDisplay(some); 
    } 
    return 0; 
} 
