/*
Description
д�����������ֱ������������������Լ������С�����������������е������������������������������������ɼ������롣

Input

�������ݵ�����n
��һ���������
�ڶ����������
.....
��n���������

Output
��һ��������ݵ����Լ��  ��һ��������ݵ���С������
�ڶ���������ݵ����Լ��  �ڶ���������ݵ���С������
......
��n��������ݵ����Լ��  ��n��������ݵ���С������

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
  
