#include <stdio.h>
void main ( )
{
  int m, n, r;
  printf ("Please input two positive integer: ");
  scanf ("%d%d", &m, &n);
  while (n != 0)
  {
    r = m % n;   //ว๓ำเสý
    m = n;
    n = r;
  }
  printf ("Their greatest common divisor is %d\n", m);
}
