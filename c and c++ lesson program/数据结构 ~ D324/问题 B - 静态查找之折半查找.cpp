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
题目描述
给出一个队列和要查找的数值，找出数值在队列中的位置，队列位置从1开始
要求使用折半查找算法

输入
第一行输入n，表示队列有n个数据
第二行输入n个数据，都是正整数，用空格隔开
第三行输入t，表示有t个要查找的数值
第四行起，输入t个数值，输入t行

输出
每行输出一个要查找的数值在队列的位置，如果查找不成功，输出字符串error

样例输入
8
11 22 33 44 55 66 77 88
3
22
88
99

样例输出
2
8
error

*/
