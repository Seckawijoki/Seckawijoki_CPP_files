#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
#include <iostream>  
#include <math.h>  
#include <time.h>
#include <stdlib.h>
using namespace std;  
const double eps = 1e-6;  
const int MAXN = 1000100;  
const double INF = 1e20;  
struct Point  
{  
    double x,y;  
}; 
//�������ľ���
double dist(Point a,Point b)  
{  
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));  
}  
Point p[MAXN];  
Point tmpt[MAXN];
bool cmpxy(Point a,Point b)  
{  
    if(a.x != b.x)return a.x < b.x;  
    else return a.y < b.y;  
}  
bool cmpy(Point a,Point b)  
{  
    return a.y < b.y;  
} 
double min(double a,double b)
{
	if(a<b)return a;
	else return b;
}
//���η�
double Closest_Pair_F(int left,int right)  
{  
    double d = INF;  
    if(left == right)return d;  
    if(left + 1 == right)  
        return dist(p[left],p[right]);  
    int mid = (left+right)/2;  
    double d1 = Closest_Pair_F(left,mid);  
    double d2 = Closest_Pair_F(mid+1,right);  
    d = min(d1,d2); 
    int k = 0,i,j;  
    for(i = left; i <= right; i++)  
    {  
		//������������е���������С�ڵ���d�ĵ�
        if(fabs(p[mid].x - p[i].x) <= d)  
            tmpt[k++] = p[i];  
    }  
	//����������
    sort(tmpt,tmpt+k,cmpy);
	//�������С�ģ�����d
    for(i = 0; i <k; i++)  
    {  
        for(j = i+1; j < k && tmpt[j].y - tmpt[i].y < d; j++)  
        {  
            d = min(d,dist(tmpt[i],tmpt[j]));  
        }  
    }  
    return d;  
}  
//������
double Closest_Pair_M(int n) 
{     
	double  d;     
	double  Dist=INF;  
	for (int i=0;i<n-1;i++)  
	{   
		for (int j=i+1;j<=n-1;j++)   
		{    
			d=(p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y);    
			if(d<=Dist)    
			{     
				Dist=d;       
			}   
		}  
	}  return Dist;   
} 
  
int main()  
{  
    int n,i,j,k;  
	int choice;
	double start,finish,d,sum;
//	scanf("%d",&n);
	n=100;
    while(true)  
    {  
		printf("1��������    2�����η�\n");
		scanf("%d",&choice);
		sum=0;
		srand((int)time(NULL));
		for(k=n;k<=100000;k=k*10)
		{
			for(i = 0; i < k; i++) 
			{
				p[i].x=(double)rand()/RAND_MAX;
				p[i].y=(double)rand()/RAND_MAX;
				//printf("%.2lf,%.2lf\n ",p[i].x,p[i].y);
			}
			if(choice==1)
			{
				for(j=0;j<1;j++)
				{
					start=clock();
					Closest_Pair_M(k);
					finish=clock();
					sum+=finish-start;
				}
				printf("��ģΪ��%d ��������ʱ��%.2lfms\n",k,sum/1); 
			}
			else if(choice==2)
			{
				for(j=0;j<1;j++)
				{
					start=clock();
					sort(p,p+k,cmpxy);  
					Closest_Pair_F(0,k-1);
					finish=clock();
					sum+=finish-start;
				}
				printf("��ģΪ��%d ���η���ʱ��%.2lfms\n",k,sum/1); 
			}
		}
		
    }  
    return 0;  
}  

