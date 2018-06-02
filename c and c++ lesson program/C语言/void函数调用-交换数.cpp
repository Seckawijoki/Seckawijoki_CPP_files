#include <stdio.h>
void swap (int a, int b); 
void main ( )
{   
    int x = 7, y = 11;
    printf ("before swapped: ");
    printf ("x=%d, y=%d\n", x, y);
    swap (x, y);   
    printf ("after  swapped: ");
    printf ("x=%d, y=%d\n", x, y);
}

void swap (int a, int b)
{   
    int temp;
    temp = a; 
    a = b; 
    b = temp;
}
