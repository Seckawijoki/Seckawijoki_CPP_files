#include <stdio.h>
void main ( )
{
   int i;
   void func ( );  //����˵��
   for (i = 1; i <= 5; i++)
      func ( );    //��������
}

void func ( )    //��������
{
   //static int j = 0;//1 2 3 4 5
   auto int j = 0;	  //1 1 1 1 1
   ++j;
   printf ("%d ", j);
}
