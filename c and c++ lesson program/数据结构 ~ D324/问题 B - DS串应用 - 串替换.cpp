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
��Ŀ����
����������ģʽ�����滻������KMP�㷨�ҳ�ģʽ����������λ�ã�Ȼ�����滻�����ַ��滻��ģʽ��

����ֻ����һ���滻����������������������һЩ���ܹ�ʵ�ֶദ�滻��

������Ҫ����ģʽ�����滻�����Ȳ�һ�µ����

����

��һ������t����ʾ��t��ʵ��

�ڶ��������1��ʵ���������������������1��ʵ����ģʽ���������������1��ʵ�����滻��

�Դ�����


���
��һ�������1��ʵ��������

�ڶ��������1��ʵ���������滻���������û�з����滻���������ԭ�������ݡ�

�Դ�����

��������
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

�������
aabbccdd
aaffccdd
aaabbbccc
aaabbbccc
abcdef
cccccdef


*/
