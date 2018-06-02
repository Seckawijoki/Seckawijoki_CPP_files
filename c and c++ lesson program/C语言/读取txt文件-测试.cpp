#include "stdio.h"
#include "string.h"
void main()
{
 int n;
    FILE *fin;
 char s[25];
 fin=fopen("F:\书\已背\351-378.txt","r");
 fgets(s,25,fin);/*用fgets读第一行到数组s中*/
         n=strlen(s);
 fseek(fin,n+1,SEEK_SET);/*将文件指针移到下一行*/
 fgets(s,25,fin);/*读取第二行的字符串*/
 printf("%s",s);
    }


//     fp=fopen("F:\书\已背\351-378.txt","r");
