/*
Description
дһ��������ʹ������һ����ά���飨��������ת�ã������л�����

Input
һ��3x3�ľ���

Output
ת�ú�ľ���

Sample Input
1 2 3
4 5 6
7 8 9

Sample Output
1 4 7 
2 5 8 
3 6 9 
*/
# include <iostream> 
using namespace std; 
int jzzz( int a[][3] ); 
int jzzz( int a[][3] ) 
{ 
    int i,j; 
    for ( i = 0 ; i < 3 ; i++ ) 
    {   for ( j = 0 ; j < 3 ; j++ ) //ֱ�������
            cout<<a[j][i]<<' '; 
        cout<<'\n'; 
    } 
    return 1; 
} 
int main() 
{ 
    int i,j,a[3][3]; 
    for ( i = 0 ; i < 3 ; i++ ) 
        for ( j = 0 ; j < 3 ; j++ ) 
            cin>>a[i][j]; 
    jzzz(a); 
    return 0; 
}
