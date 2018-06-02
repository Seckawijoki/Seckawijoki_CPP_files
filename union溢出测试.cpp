#include<stdio.h>
union Test
 {
    char a[4];
    short b;
 };
int main(){
 Test test;
 test.a[0]=256;
 test.a[1]=255;
 test.a[2]=254;
 test.a[3]=253;
 printf("%d\n",test.b);
}
