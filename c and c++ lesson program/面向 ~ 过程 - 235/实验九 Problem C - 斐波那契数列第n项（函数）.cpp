/*
Description
쳲��������еĶ������£�
F_0=0 
F_1=1 
F_n = F_{n-1}+ F_{n-2} 
Ҳ����˵��쳲�����������0 ��1��ʼ��
֮���ÿһ����֮ǰ��������ӣ�����:
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233,...
Ҫ���ú���ʵ�֣���쳲��������е�n���ֵ��
������ʹ�õݹ麯����

Input
n

Output
쳲����������ڵ�n���ֵ

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
