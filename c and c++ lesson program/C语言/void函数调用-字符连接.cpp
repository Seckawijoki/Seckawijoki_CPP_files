#include <stdio.h>
void mergestr (char s1[ ], char s2[ ], char s3[ ]);
//�β������ʵ������ĳ��ȿ��Բ���ͬ����Ϊ�ڵ���ʱ��ֻ�����׵�ַ��������β�����ĳ��ȡ�
//��ά����Ҳ������Ϊ�����Ĳ������ں�������ʱ���β��������ָ��ÿһά�ĳ��ȣ�Ҳ��ʡȥ��һά�ĳ��ȡ�      
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
    for (i = 0; s1[i] != '\0'; i++)  //��s1���Ƶ�s3��
        s3[i] = s1[i];
    for (j = 0; s2[j] != '\0'; j++)  //��s2���Ƶ�s3�ĺ��
        s3[i+j] = s2[j];
    s3[i+j] = '\0';            //���ַ���������־
}
