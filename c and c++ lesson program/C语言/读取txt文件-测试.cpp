#include "stdio.h"
#include "string.h"
void main()
{
 int n;
    FILE *fin;
 char s[25];
 fin=fopen("F:\��\�ѱ�\351-378.txt","r");
 fgets(s,25,fin);/*��fgets����һ�е�����s��*/
         n=strlen(s);
 fseek(fin,n+1,SEEK_SET);/*���ļ�ָ���Ƶ���һ��*/
 fgets(s,25,fin);/*��ȡ�ڶ��е��ַ���*/
 printf("%s",s);
    }


//     fp=fopen("F:\��\�ѱ�\351-378.txt","r");
