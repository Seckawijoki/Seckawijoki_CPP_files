#include <stdio.h>
void print (int w);
void main ( )
{  print ( 3 );  }
void print (int w)   //递归函数
{      
    int  i;
    if ( w != 0)     //递归结束条件
    {     
      print (w-1);//递归中先输入3，2，1，再一步步返回（1，2，3）
      for (i = 1; i <= w; ++i)
        printf ("%d ", w);
      printf ("\n");
    }
}
/*
	结果：
	1
	2 2
	3 3 3
*/
