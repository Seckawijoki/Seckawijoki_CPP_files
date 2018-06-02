# include <iostream> 
# include <string> 
using namespace std; 
void Get_NextValue( string model, int next[] ) 
{ 
    int i = 1; 
    int j = 0; 
    next[1] = 0; 
    while ( i < model[0] ) 
    { 
        if ( j == 0 || model[i] == model[j] ) 
            next[++i] = ++j; 
        else
            j = next[j]; 
    } 
} 
int Index_KMP( string primary, string secondary, int position ) 
{ 
    int i = position, j = 1, k; 
    int length = secondary.length(); 
    int *next = new int [length]; 
    Get_NextValue(secondary, next); 
//  for ( k = 1 ; k < length ; ++k )cout<<next[k]<<' ';cout<<endl;
    while ( i <= primary[0] && j <= secondary[0] ) 
    { 
        if ( j == 0  || primary[i] == secondary[j] ) 
        { 
            ++i; 
            ++j; 
        } 
        else
            j = next[j]; 
    } 
    if ( j > secondary[0] )return i-secondary[0]; 
    else	return 0; 
} 
int main() 
{ 
    int n, i, commence, length; 
    char copy[512]; 
    string chief, vice, substitute, storage; 
    cin>>n; 
    while ( n-- ) 
    { 
        cin>>chief>>vice>>substitute; 
        storage = chief; 
          
        copy[0] = vice.length(); 
        for ( i = 0 ; i < copy[0] ; ++i ) 
            copy[i+1] = vice[i]; 
        copy[i+1] = '\0'; 
        vice = copy; 
          
        copy[0] = chief.length(); 
        for ( i = 0 ; i < copy[0] ; ++i ) 
            copy[i+1] = chief[i]; 
        copy[i+1] = '\0'; 
        chief = copy; 
          
        commence = Index_KMP(chief,vice,1); 
        cout<<storage<<endl; 
        if ( commence )chief.replace(commence,vice.length()-1,substitute);
        length = chief.length() - 1;
        for ( i = 0 ; i < length ; ++i )
        	copy[i] = chief[i+1];
        copy[i] = '\0';
        storage = copy;
        cout<<storage<<endl; 
    }
    return 0; 
} 
/*
题目描述
给出主串、模式串、替换串，用KMP算法找出模式串在主串的位置，然后用替换串的字符替换掉模式串

本题只考虑一处替换的情况，如果你想做的完美一些，能够实现多处替换那

可能需要考虑模式串和替换串长度不一致的情况

输入

第一个输入t，表示有t个实例

第二行输入第1个实例的主串，第三行输入第1个实例的模式串，第四行输入第1个实例的替换串

以此类推


输出
第一行输出第1个实例的主串

第二行输出第1个实例的主串替换后结果，如果没有发生替换就输出主串原来的内容。

以此类推

样例输入
3
aabbccdd
bb
ff
aaabbbccc
ddd
eee
abcdef
abc
ccccc

样例输出
aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef


*/
