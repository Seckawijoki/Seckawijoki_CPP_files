#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<cmath>
using namespace std;

int V[10001][10001];
int vy[100010];
int flag[100010];
int f[10000];
int w[100000],v[100000];
int maxV,c,n;
string maxStr;
int max(int a,int b)
{
	if(a>b)
		return a;
	else return b;
}

int dt(int w[],int v[],int c,int n)
{
	int i,j;
	
	for(i=0;i<=n;i++)
	{
		V[i][0]=0;
	}
	
	for(i=0;i<=c;i++)
		V[0][i]=0;
	
	for(i=1;i<=n;i++)
		for(j=1;j<=c;j++)
		{
			if(j<w[i])
				V[i][j]=V[i-1][j];
			else
				V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
		}
		j=c;
		for(i=n;i>=1;i--)
		{
			if(V[i][j]>V[i-1][j])
			{
				flag[i]=1;
				j=j-w[i];
			}
			else
				flag[i]=0;
		}
		return V[n][c];
}
//优化
int hy(int w[],int v[],int c,int n)
{
	int i,j;
	for(i=0;i<=c;i++)
		vy[i]=0;
	for (i = 1; i <= n; i++)
    {
        for (int j = c; j >= w[i]; j--)
        {
            vy[j] = max(vy[j], vy[j - w[i]] + v[i]);
        }
       
    }
		return vy[c];
}

void baoli(int n,int c)
{
	int num,maxv=0,i;
	int f[10000],f1[10000];
	 for(num=0;num<pow(2,n);num++) 
        {  
			int oo=0;
            int k=num,tempw=0,tempv=0;     
            for(i=0;i<n;i++)  
            {  
                if(k%2==1){     
                    tempw+=w[i+1];  
                    tempv+=v[i+1]; 
					f[oo++]=i+1;
                }
                k=k/2;        
            }
			f[oo]=-1;
            if(tempw<=c){  
                if(tempv>maxv)
				{
                    maxv=tempv;
					for(int kk=0;f[kk]!=-1;kk++)
						f1[kk]=f[kk];
					f1[kk]=-1;
				}
            }  
        }  
      
        cout<<"暴力法总价值:"<<maxv<<endl;
		cout<<"物品：";
		for(int kk=0;f1[kk]!=-1;kk++)
				cout<<f1[kk]<<" ";
		cout<<endl;
}

int main()
{
	int i,j;
	double start,end;
	string tempStr;
	while(true)
	{
		srand(time(0));
		cin>>n;
		c=10;
		int s;
		for(int k=c;k<=10;k+=1000)
		{
			double sum=0;
			for(int jjj=0;jjj<1;jjj++)
			{
				for(i=1;i<=n;i++)
				{
				//	cin>>w[i];
					w[i]=rand()%(k-1)+1;
				//	cout<<w[i]<<" ";
				}
			//	cout<<endl;
				for(i=1;i<=n;i++)
				{
				//	cin>>v[i];
					v[i]=rand()%100+1;
				//	cout<<v[i]<<" ";
				}
				baoli(n,c);
				
			//	cout<<endl;
				start=clock();
				s=dt(w,v,k,n);
				cout<<"动态规划价值："<<s<<endl;
				cout<<"所放物品：";
				for(j=1;j<=n;j++)
				if(flag[j]==1)
					cout<<j<<' ';
				cout<<endl;
			//	hy(w,v,k,n);
				end=clock();
				sum+=end-start;
			}
	//		cout<<"优化耗时："<<sum/10<<"ms"<<endl;
	//		cout<<"所放物品：";
	//		for(j=1;j<=n;j++)
	//			if(flag[j]==1)
	//				cout<<j<<' ';
	//		cout<<endl<<"动态规划法总价值:"<<s<<endl;
	//		cout<<hy(w,v,k,n)<<endl;
			
		}
			
		
		
	}
	return 0;
}