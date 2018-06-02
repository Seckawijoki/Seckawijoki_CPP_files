/*
Description
写一函数，将两个字符串中的元音字母复制到另一个字符串，然后输出。

Input
一行字符串

Output
顺序输出其中的元音字母（aeiuo）

Sample Input
abcde
Sample Output
ae
*/
# include <iostream> 
# include <cstring> 
using namespace std; 
int fzyy( char a[] , char b[] ) 
{ 
    int i,j = 0,n; 
    n = strlen(a); 
    for ( i = 0 ; i < n ; i++ ) 
    { 
        if ( a[i] == 'a' || 
             a[i] == 'e' || 
             a[i] == 'i' || 
             a[i] == 'o' || 
             a[i] == 'u' ) 
        { 
            b[j] = a[i]; 
            j++; 
        } 
    }
	b[j] = '\0';
    return strlen(b); 
} 
int main() 
{ 
    int i,n; 
    char a[33],b[33] = {'\0'}; 
    cin>>a; 
    n = fzyy(a,b); 
    for ( i = 0 ; i < n ; i++ ) 
        cout<<b[i]; 
    return 0; 
} 
