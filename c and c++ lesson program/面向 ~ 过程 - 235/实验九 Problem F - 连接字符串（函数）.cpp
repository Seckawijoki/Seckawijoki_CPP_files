/*
Description
写一函数，将两个字符串连接

Input
两行字符串

Output
链接后的字符串

Sample Input
123
abc
Sample Output
123abc
*/
# include <iostream> 
# include <cstdlib> 
# include <cstring> 
using namespace std;  
int ljzf( char a[] , char b[] ) 
{ 
    strcat(a,b); 
    return strlen(a); 
} 
int main() 
{ 
    char a[33] , b[33]; 
	int n;
    cin>>a; 
    cin>>b; 
    n = ljzf(a,b); 
    for ( int i = 0 ; i < n ; i++ ) 
        cout<<a[i];
	cout<<endl;
    return 0; 
} 
