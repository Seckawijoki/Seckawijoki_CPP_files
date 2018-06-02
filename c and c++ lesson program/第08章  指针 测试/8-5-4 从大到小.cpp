# include <stdio.h>
void swap( int  *p1, int  *p2 )//设置函数中属于传递值。
{   
   int p;
    p  = *p1;
   *p1 = *p2;
   *p2 =  p;
}
void main (  )
{   
    int a, b;
    int *p_1, *p_2;
    scanf ("%d%d", &a, &b);
    p_1 = &a;
	p_2 = &b;
    if ( a < b )
		swap (p_1, p_2);
    printf ("\na = %d , b = %d\n", a, b);
	printf ("*p_1 = %d , *p_2 = %d\n", *p_1,*p_2);
}
