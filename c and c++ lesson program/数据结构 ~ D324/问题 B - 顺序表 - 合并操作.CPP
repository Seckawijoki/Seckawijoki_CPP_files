/*
题目描述
建立顺序表的类，属性包括：数组、实际长度、最大长度（设定为1000）

已知两个递增序列，把两个序列的数据合并到顺序表中，并使得顺序表的数据递增有序


输入
第1行先输入n表示有n个数据，接着输入n个数据，表示第1个序列，要求数据递增互不等

第2行先输入m表示有m个数据，接着输入m个数据，表示第2个序列，要求数据递增互不等


输出
顺序表内容包括顺序表的实际长度和数据，数据之间用空格隔开

第1行输出创建后的顺序表内容

样例输入
3 11 33 55
5 22 44 66 88 99

样例输出
8 11 22 33 44 55 66 88 99 

*/
# include <iostream> 
# include <cmath> 
using namespace std; 
  
# define ok     0 
# define error -1 
  
class SeqList 
{ 
private: 
    int *list; 
    int maxsize; 
    int size; 
public: 
    SeqList() 
    { 
        size = 0; 
        maxsize = 1000; 
        list = new int [maxsize]; 
    } 
    SeqList( int *array , int length ) 
    { 
        size = length; 
        maxsize = 1000; 
        list = new int [maxsize]; 
        int i = 0; 
        for ( i =  0  ; i < size ; i++ ) 
            list[i] = array[i]; 
    } 
    ~SeqList() 
    { 
        delete [] list; 
    } 
    void MergeList( SeqList &sqa , SeqList &sqb ) 
    { 
        size = sqa.size + sqb.size; 
        int i,j; 
        for ( i = 0 ; i < sqa.size ; i++ ) 
            list[i] = sqa.list[i]; 
        for ( j = 0  ; j < sqb.size ; i++, j++ ) 
            list[i] = sqb.list[j]; 
        for ( i =  0  ; i < size ; i++ ) 
        for ( j = i+1 ; j < size ; j++ ) 
            if ( list[i] > list[j] ) 
            { 
                list[i] = list[i] + list[j]; 
                list[j] = list[i] - list[j]; 
                list[i] = list[i] - list[j]; 
            } 
    } 
    void Display() 
    { 
        int i = 0; 
        cout<<size<<' '; 
        for ( i =  0  ; i < size ; i++ ) 
            cout<<list[i]<<' '; 
        cout<<endl; 
    } 
};  
int main() 
{ 
    int i,  m,n, *aa, *bb; 
    cin>>m; 
    aa = new int [m]; 
    for ( i = 0 ; i < m ; i++ )  cin>>aa[i]; 
      
    cin>>n; 
    bb = new int [n]; 
    for ( i = 0 ; i < n ; i++ )  cin>>bb[i]; 
      
    SeqList sqa(aa,m), sqb(bb,n), sqc; 
    sqc.MergeList(sqa,sqb); 
    sqc.Display(); 
    delete [] aa; 
    delete [] bb; 
    return 0; 
} 
