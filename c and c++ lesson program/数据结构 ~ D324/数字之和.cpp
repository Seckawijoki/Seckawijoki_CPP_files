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
问题描述 
　　给定一个十进制整数n，输出n的各位数字之和。 
输入格式 
　　输入一个整数n。 
输出格式 
　　输出一个整数，表示答案。 
样例输入 
20151220 
样例输出 
13 
样例说明 
　　20151220的各位数字之和为2+0+1+5+1+2+2+0=13。 
评测用例规模与约定 
　　所有评测用例满足：0 ≤ n ≤ 1000000000。  
*/

