#include <stdio.h>
void mergestr (char s1[ ], char s2[ ], char s3[ ]);
//形参数组和实参数组的长度可以不相同，因为在调用时，只传送首地址而不检查形参数组的长度。
//多维数组也可以作为函数的参数。在函数定义时对形参数组可以指定每一维的长度，也可省去第一维的长度。      
void main ( )
{
    char str1[ ] = {"Hello "};
    char str2[ ] = {"china!"};
    char str3[40];
    mergestr (str1, str2, str3); 
    printf ("%s\n", str3);
}
void mergestr (char s1[ ], char s2[ ], char s3[ ]) 
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++)  //将s1复制到s3中
        s3[i] = s1[i];
    for (j = 0; s2[j] != '\0'; j++)  //将s2复制到s3的后边
        s3[i+j] = s2[j];
    s3[i+j] = '\0';            //置字符串结束标志
}
