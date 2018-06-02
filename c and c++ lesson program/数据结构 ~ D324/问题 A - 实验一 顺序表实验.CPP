/*
题目描述
1、问题描述
给出初始数据
实现顺序表的定义、创建、查找、插入、删除

2、算法
顺序表：一维数据数组、最大长度、实际长度
顺序表的创建：参数初始化
顺序表的查找：给出位置i的数据
顺序表的插入：位置i和后面的数据全部后移一位，在指定位置i插入一个数据，长度加1
顺序表的删除：位置i后面的数据全部前移一位，覆盖掉位置i的数据，长度减一

输入
第一行：测试次数
每次测试分5行：
第1行：第一个数字n表示样本数目，其后跟n个样本
第2行：查找数据的位置
第3行：插入新数据位置、新数据
第4行：第一个待删除数据的位置
第5行：第二个待删除数据的值

输出
每次测试分6行：
第1行：顺序表创建后，数据数组按顺序排列的全部数据
第2行：按指定位置给出数据
第3行：插入新数据后，数据数组按顺序排列的全部数据
第4行：删除一个数据，数据数组按顺序排列的全部数据
第5行：是否找到待删除数据的位置（1—找到，0—未找到），待删除数据的位置（0表示未找到）
        （如果有多个，则删除从最后一个数据元素开始，第一个找到的数据元素），查找次数（从最后一个数据元素开始查找）
第6行：删除一个数据，数据数组按顺序排列的全部数据


样例输入
5 2 4 3 5 7
4
2 9
3
4

样例输出
2 4 3 5 7
5
2 9 4 3 5 7
2 9 3 5 7
0 0 6
2 9 3 5 7

*/
# include <iostream> 
using namespace std; 
   
# define ok     0 
# define error -1 
   
class SqList 
{ 
private: 
    int *list; 
    int maxsize; 
    int size; 
public: 
    SqList() 
    { 
        maxsize = 1000; 
        size = 0; 
        list = new int [maxsize]; 
    } 
    SqList( int *array, int length ) 
    { 
        size = length;  
        list = new int [maxsize]; 
        int j; 
        for ( j = 0 ; j < size ; j++ ) 
            list[j] = array[j]; 
    } 
    ~SqList() 
    { 
        delete [] list; 
    } 
    int list_size() 
    { 
        return size; 
    } 
    int list_insert( int i , int item ) 
    { 
        if ( i > size || i < 1 ) 
        { 
            cout<<"error\n"; 
            return error; 
        } 
        else
        { 
            i--; 
            int j; 
            for ( j = size ; j >= i ; j-- ) 
                list[j+1] = list[j]; 
            list[i] = item; 
            size++; 
            return ok; 
        } 
    } 
    int list_delete_location( int i ) 
    { 
        if ( i > size + 1 || i < 1 ) 
        { 
            cout<<"error\n"; 
            return error; 
        } 
        else
        { 
            size--; 
            int j; 
            for ( j = --i ; j <= size ; j++ ) 
                list[j] = list[j+1]; 
            return ok; 
        } 
    }  
    int list_delete_value( int item ) 
    { 
        int i, existence = 0; 
        for ( i = 0 ; i < size ; i++ ) 
            if ( list[i] == item ) 
            { 
                existence++; 
                break; 
            } 
        if ( !existence ) 
        { 
            cout<<"error\n"; 
            return error; 
        } 
        else
        { 
            size--; 
            int j; 
            for ( j = i ; j <= size ; j++ ) 
                list[j] = list[j+1]; 
            return ok; 
        } 
    } 
    int list_get( int i ) 
    { 
        if ( i > size + 1 || i < 1 ) 
        { 
            cout<<"error\n"; 
            return error; 
        } 
        else
            return list[--i]; 
    } 
    void list_display() 
    { 
        int j; 
        cout<<size<<' '; 
        for ( j = 0 ; j < size ; j++ ) 
            cout<<list[j]<<' '; 
        cout<<endl; 
    } 
    friend ostream & operator << ( ostream &stream , SqList &sq ) 
    { 
        int j; 
        for ( j = 0 ; j < sq.size ; j++ ) 
            stream<<sq.list[j]<<' '; 
        return stream; 
    } 
}; 
int main() 
{ 
    int length, *array, i,j, item, booleanvalue; 
    cin>>length; 
    array = new int [length]; 
    for ( j = 0 ; j < length ; j++ ) 
        cin>>array[j]; 
   
    SqList list123(array,length); 
    cout<<list123<<endl; 
   
    cin>>i; 
    booleanvalue = list123.list_get(i); 
    if ( booleanvalue != error ) cout<<booleanvalue<<endl; 
      
    cin>>i>>item; 
    booleanvalue = list123.list_insert(i,item); 
    if ( booleanvalue == ok ) cout<<list123<<endl; 
   
    cin>>i; 
    booleanvalue = list123.list_delete_location(i); 
    if ( booleanvalue == ok ) cout<<list123<<endl; 
      
    cin>>item; 
    booleanvalue = list123.list_delete_value(item); 
    if ( booleanvalue == ok ) cout<<list123<<endl; 
   
    delete [] array; 
    return 0; 
} 
