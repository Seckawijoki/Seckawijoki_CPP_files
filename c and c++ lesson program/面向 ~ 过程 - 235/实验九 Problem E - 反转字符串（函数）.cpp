/*
Description
дһ������ʹ�����һ���ַ����������ţ�������������������������ַ�����

Input
һ���ַ�

Output
�������ַ���

Sample Input
123456abcdef

Sample Output
fedcba654321
*/
# include <iostream> 
# include <cstring> 
using namespace std; 
int fzzf( char a[] , char b[] , int m ) 
{ 
    int i; 
    for ( i = 0 ; i <= m ; i++ ) 
        b[m-i] = a[i]; 
    return 1; 
} 
int main() 
{ 
    char a[30] , b[30] = {'\0'};
	cin>>a;
	int m = strlen(a);
    fzzf(a,b,m); 
    for ( int i = 1 ; i <= m ; i++ ) 
        cout<<b[i]; 
    cout<<endl; 
    return 0; 
} 
