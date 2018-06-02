# include <iostream> 
using namespace std; 
class SequenceList 
{ 
private: 
    int *array; 
    int length; 
public: 
    SequenceList() 
    { 
        array = NULL; 
        length = 0; 
    } 
    SequenceList( int *list, int size ) 
    { 
        int i; 
        length = size; 
        array = new int [length+1]; 
        for ( i = 1 ; i <= length ; ++i ) 
            array[i] = list[i]; 
    } 
    ~SequenceList() 
    { 
        delete [] array; 
    } 
    int SqList_Bisearching( int item ) 
    { 
        int low = 1; 
        int high = length; 
        int middle = length + 1; 
        while ( low <= high ) 
        { 
            middle = ( low + high ) /2; 
            if ( item == array[middle] ) 
                return middle; 
            else if ( item >  array[middle] ) 
                low = middle + 1; 
            else if ( item <  array[middle] ) 
                high = middle - 1; 
        } 
        return 0; 
          
    } 
}; 
int main() 
{ 
    int n, t, i, strayer, result; 
    int *list; 
    cin>>n; 
    list = new int [n+1]; 
    for ( i = 1 ; i <= n ; ++i ) 
        cin>>list[i]; 
    SequenceList sequencial(list,n); 
    cin>>t; 
    while ( t-- ) 
    { 
        cin>>strayer; 
        result = sequencial.SqList_Bisearching(strayer); 
        if ( result >  n || result  < 1 ) 
            cout<<"error\n"; 
        else
            cout<<result<<endl; 
    } 
    delete [] list; 
    return 0; 
} 

/*
��Ŀ����
����һ�����к�Ҫ���ҵ���ֵ���ҳ���ֵ�ڶ����е�λ�ã�����λ�ô�1��ʼ
Ҫ��ʹ���۰�����㷨

����
��һ������n����ʾ������n������
�ڶ�������n�����ݣ��������������ÿո����
����������t����ʾ��t��Ҫ���ҵ���ֵ
������������t����ֵ������t��

���
ÿ�����һ��Ҫ���ҵ���ֵ�ڶ��е�λ�ã�������Ҳ��ɹ�������ַ���error

��������
8
11 22 33 44 55 66 77 88
3
22
88
99

�������
2
8
error

*/
