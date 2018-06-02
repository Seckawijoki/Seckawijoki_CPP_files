#include <stdio.h>
void  main ( )
{   
  int *p1,*p2,*p, a, b;
  scanf ("%d%d", &a, &b);
  p1 = &a;
  p2 = &b;
  printf("p1 = %d , p2 = %d\n",p1,p2);
  if (a < b)//通过指针交换变量值。交换地址。
  {
	  p  = p1;
	  p1 = p2;
	  p2 = p ;
  }
  printf("p1 = %d , p2 = %d\n",p1,p2);
  printf("a = %d, b = %d\n", a, b);
  printf("max = %d, min = %d\n", *p1, *p2);
}
/*============================================
		1 9999
		p1 = 1638196 , p2 = 1638192
		p1 = 1638192 , p2 = 1638196
		a = 1, b = 9999
		max = 9999, min = 1
		Press any key to continue
============================================*/