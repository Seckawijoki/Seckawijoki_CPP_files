# include <iostream> 
using namespace std; 
int main() 
{ 
    string number; 
    int i, digit, sum = 0; 
    cin>>number; 
    digit = number.length(); 
    for ( i = 0 ; i < digit ; ++i ) 
    if ( number[i] >= '0' && number[i] <= '9' ) 
        sum += number[i] - '0'; 
    cout<<sum<<endl; 
    return 0; 
} 
/* 
�������� 
��������һ��ʮ��������n�����n�ĸ�λ����֮�͡� 
�����ʽ 
��������һ������n�� 
�����ʽ 
�������һ����������ʾ�𰸡� 
�������� 
20151220 
������� 
13 
����˵�� 
����20151220�ĸ�λ����֮��Ϊ2+0+1+5+1+2+2+0=13�� 
����������ģ��Լ�� 
�������������������㣺0 �� n �� 1000000000��  
*/

