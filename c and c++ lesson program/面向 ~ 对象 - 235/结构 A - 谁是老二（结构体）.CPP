/*
题目描述
定义一个结构体，包含年月日，表示一个学生的出生日期。然后在一群学生的出生日期中找出谁的出生日期排行第二
要求：出生日期的存储必须使用结构体，不能使用其他类型的数据结构。
要求程序全过程对出生日期的输入、访问、输出都必须使用结构。

输入
第一行输入t表示有t个出生日期
每行输入三个整数，分别表示年、月、日
依次输入t个实例

输出
输出排行第二老的出生日期，按照年-月-日的格式输出

样例输入
6
1980 5 6
1981 8 3
1980 3 19
1980 5 3
1983 9 12
1981 11 23

样例输出
1980-5-3
*/
# include <stdio.h> 
struct tanjoubi 
{ 
    int nenn; 
    int getsu; 
    int nichi; 
}; 
int quest( int a[] , int n ) 
{ 
    int i,j,k = 1; 
    int b[11]; 
    for ( i = 0 ; i < n ; i ++ ) 
        b[i] = a[i];     
    for ( i = 0 ; i < n ; i ++ ) 
        for ( j = i+1 ; j < n ; j ++ ) 
            if ( b[i] > b[j] ) 
            { 
                b[i] = b[i] + b[j]; 
                b[j] = b[i] - b[j]; 
                b[i] = b[i] - b[j]; 
            } 
    for ( i = 0 ; i < n ; i ++ ) 
        if ( b[1] == a[i] ) 
            return i; 
} 
int main() 
{ 
    int t,i,k; 
    int a[11]; 
    scanf("%d",&t); 
    tanjoubi hito[11]; 
    for ( i = 0 ; i < t ; i ++ ) 
        scanf("%d %d %d",&hito[i].nenn,&hito[i].getsu,&hito[i].nichi); 
    for ( i = 0 ; i < t ; i ++ ) 
        a[i] = hito[i].nenn * 10000 + hito[i].getsu * 100 + hito[i].nichi; 
    k = quest( a , t ); 
    printf("%d-%d-%d\n",hito[k].nenn,hito[k].getsu,hito[k].nichi); 
    return 0; 
} 
/* 
    for ( i = 0 ; i < t ; i ++ ) 
        printf("%d %d %d\n",hito[i].nenn,hito[i].getsu,hito[i].nichi); 
    for ( i = 0 ; i < t ; i ++ ) 
        printf("%d\n",a[i]); 
*/
