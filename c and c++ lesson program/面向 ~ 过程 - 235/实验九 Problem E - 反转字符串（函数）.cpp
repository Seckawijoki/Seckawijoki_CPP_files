/*
Description
写一函数，使输入的一个字符串按反序存放，在主函数中输入输出反序后的字符串。

Input
一行字符

Output
逆序后的字符串

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
