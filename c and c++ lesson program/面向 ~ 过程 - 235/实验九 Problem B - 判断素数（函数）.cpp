/*
Description
дһ���ж������ĺ�����������������һ��������
����Ƿ���������Ϣ��

Input
�жϴ�����ÿ��������������� ��

Output
ÿ�ε������Ƿ�Ϊ����

Sample Input
4
17
5
6
19

Sample Output
prime
prime
not prime
prime
*/
# include <iostream> 
using namespace std; 
int prime( int x ) 
{ 
    int i,j; 
    if ( x == 0 || x == 1 || x == 2 ) 
    { 
        cout<<"prime\n"; 
        return 0; 
    } 
    else if ( x %2 == 0 ) 
    { 
        cout<<"not prime\n"; 
        return 0; 
    } 
    else
    { 
        int tg = 0; 
        for ( i = 3 ; i <= x / 2 ; i += 2 ) 
        { 
            if ( x %i == 0 ) 
            { 
                tg++; 
                cout<<"not prime\n"; 
                break; 
            } 
        } 
        if ( !tg ) 
            cout<<"prime\n"; 
    } 
    return 1; 
} 
int main() 
{ 
    int x,n; 
    cin>>n; 
    while ( n-- ) 
    { 
        cin>>x; 
        prime(x); 
    } 
    return 0; 
} 
