#include<stdio.h>
//��VS2010������ͨ��
int add(int *x, int *y, int *z){
    *x += *x;
    *y += *x;
    *z += *y;
    return *z;
 }
 
int main()
{
 //���������ڴ�����
 int a=1,b=1,c=1;
 //ע�⾭��һ��add()֮��a��b��c��ֵ�п��ܷ����ı䣬ע��ҪֵҪ��1
 printf("ָ��ͬһ�ڴ�����%d\n",add(&a,&a,&a));
 a=1,b=1,c=1;
 printf("ָ��ͬ�ڴ�����%d\n",add(&a,&b,&c));
 a=1,b=1,c=1;
 printf("x.yָ��ͬһ�ڴ�����%d\n",add(&a,&a,&b));
 a=1,b=1,c=1;
 printf("x.zָ��ͬһ�ڴ�����%d\n",add(&a,&c,&a));
 a=1,b=1,c=1;
 printf("y.zָ��ͬһ�ڴ�����%d\n",add(&a,&c,&c));
 return 0;
}
