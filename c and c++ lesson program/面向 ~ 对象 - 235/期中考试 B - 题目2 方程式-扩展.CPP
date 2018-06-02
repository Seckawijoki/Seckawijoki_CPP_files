/*
题目描述
为类Equation添加以下成员函数：
void output()，以 ax+b的“习惯书写”形式（见样例2）输出a、b。

输入
输入测试数据的组数t
第一组a、b
……
第t组a、b

输出
按输入顺序，逐行输出方程
ax+b

样例输入
5
3 4
0 0
-1 0
1 -1
0 2

样例输出
3x+4
0
-x
x-1
2
*/
# include <iostream> 
using namespace std; 
class DisplayingEquation 
{ 
private: 
    int a; 
    int b; 
public: 
    DisplayingEquation() 
    { 
        a = 1; 
        b = 1; 
    } 
    DisplayingEquation( int m , int n ) 
    { 
        a = m; 
        b = n; 
    } 
    void SetA( int m ){a = m;} 
    void SetB( int n ){b = n;} 
    void SetAB( int m , int n ) 
    { 
        a = m; 
        b = n; 
    } 
    void FinalDisplay() 
    { 
             if ( a == 0  ) 
        { 
             if ( b == 0 ) 
                cout<<0<<endl; 
             else 
                cout<<b<<endl; 
        } 
        else if ( a == 1  ) 
        { 
                  if ( b >  0 ) 
                cout<<"x+"<<b<<endl; 
             else if ( b <  0 ) 
                cout<<"x"<<b<<endl; 
             else
                 cout<<"x"<<endl; 
        } 
        else if ( a == -1 ) 
        { 
                  if ( b >  0 ) 
                cout<<"-x+"<<b<<endl; 
             else if ( b <  0 ) 
                cout<<"-x"<<b<<endl; 
             else
                 cout<<"-x"<<endl; 
        } 
        else
        { 
                  if ( b >  0 ) 
                cout<<a<<"x+"<<b<<endl; 
             else if ( b <  0 ) 
                cout<<a<<"x"<<b<<endl; 
             else
                 cout<<a<<"x"<<endl; 
        } 
    } 
}; 
int main() 
{ 
    int t,m,n; 
    cin>>t; 
    while ( t-- ) 
    { 
        cin>>m>>n; 
        DisplayingEquation some(m,n); 
        some.FinalDisplay(); 
    } 
    return 0; 
} 
