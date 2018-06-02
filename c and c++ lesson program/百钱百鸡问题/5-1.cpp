//5-1.cpp
#include <stdio.h>
void main ( )
{
  int i = 1,j=1;    
  while (i <= 9)
  {
     j = 1;
    while (j <= 9)
    {
       printf ("%d * %d = %d\n", i, j, i * j);
       j++;
    }
    i++;
  }

}