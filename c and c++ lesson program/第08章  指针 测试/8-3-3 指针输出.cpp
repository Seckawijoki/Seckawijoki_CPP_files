# include <stdio.h>
void main ( )
{   
   int i, *p, a[7];
   p = a;
   for (i = 0; i < 7; i++)
       scanf ("%d", p++);
  printf ("\n");

   for (i = 0; i < 7; i++, p++)
      printf ("%d\n",*p);
}
// 5 8 7 6 2 7 3
