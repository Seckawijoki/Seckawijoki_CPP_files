#include <stdio.h>
void main ( )
{
   int i;
   void func ( );  //函数说明
   for (i = 1; i <= 5; i++)
      func ( );    //函数调用
}

void func ( )    //函数定义
{
   //static int j = 0;//1 2 3 4 5
   auto int j = 0;	  //1 1 1 1 1
   ++j;
   printf ("%d ", j);
}
