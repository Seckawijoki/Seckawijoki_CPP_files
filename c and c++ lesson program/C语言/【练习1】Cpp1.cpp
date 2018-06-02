#include<stdio.h>
#include<math.h>
double variance(int a[10])
{
     double ave,k=0,q;
	 int i,sum=0;
     for(i=0;i<10;i++)
	 {
		 sum=sum+a[i];
	 }
	     ave=sum/i;
    for(i=0;i<10;i++)
	 {
	     k+=pow((a[i]-ave),2);
	 }
		 q=k/i;
	 
	   return q;

}


void main()
{

    
    
	int a[10],z,i;
	double y;
	for(i=0;i<10;i++)
       scanf("%d",&a[i]);
	y=variance(a);
	printf("%.2lf",y);

}