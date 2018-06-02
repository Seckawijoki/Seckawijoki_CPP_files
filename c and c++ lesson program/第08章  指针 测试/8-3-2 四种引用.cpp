# include <stdio.h>
void main( )
{    
   int a[5], *pa, i;
   for (i = 0; i < 5; i++)
       a[i]=i+1;
    pa = a;
	for (i = 0; i < 5; i++)//输出地址
        printf ("pa+%d:%d\n", i, pa+i);
printf("\n");
    for (i = 0; i < 5; i++)//输出指向数值
        printf ("*(pa+%d):%d\n", i, *(pa+i));
printf("\n");
    for (i = 0; i < 5; i++)//输出指向数值
        printf ("*(a+%d):%d\n", i, *(a+i));
printf("\n");
    for (i = 0; i < 5; i++)//输出数值
        printf ("pa[%d]:%d\n", i, pa[i]);
printf("\n");
    for (i = 0; i < 5; i++)//输出数值
        printf("a[%d]:%d\n", i, a[i]);
printf("\n");
}
