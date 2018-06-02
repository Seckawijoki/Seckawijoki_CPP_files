#include <iostream>
using namespace std;
#include <cstdio> 
#include <string.h> 
#include <stdlib.h> 
#include <conio.h> 
#include<iomanip>
#include<time.h>
struct node 
{ 
    unsigned char b;       
    int count;            
    int parent,left,right;        
    char bit[256];
	int ccc;
} 
header[512],tmp; 
//C:\\Users\\wen\\Desktop\\实验\\算法设计\\//
int createTree(int n);
int jiema(int i,char *buf,int j);
void yasuo()                                     /*压缩*/
{ 
    char filename[255],buf[512]; 
    unsigned char c; char outFile[255];
    long i,j,m,n,f; 
    int min1,flength;
	int pt1; 
    FILE *ifp,*ofp; 
	
    printf("文件路径:"); 
    gets(filename); 
    ifp=fopen(filename,"rb");                        	
	if(ifp==NULL)
	{ 
		printf("文件不存在\n"); 
		return ;
	}
	printf("压缩后的文件路径：");
    gets(outFile);
    ofp=fopen(outFile,"wb");                    
	if(ofp==NULL)
	{
		printf("路径错误:");
       return ;     	
	}
	
//	ifp=fopen("C:\\Documents and Settings\\Administrator\\桌面\\实验\\算法设计\\cacm.all","rb");
//	ofp=fopen("C:\\Documents and Settings\\Administrator\\桌面\\实验\\算法设计\\acm.yasuo","wb");
    flength=0; 
    while(!feof(ifp))               
    { 
		c=fgetc(ifp);
        header[c].count++; 
        flength++; 
    }
    flength=flength-1;                   
	header[c].count=header[c].count-1;             
    for(i=0;i<512;i++)              
    { 
        if(header[i].count!=0) 
            header[i].b=(unsigned char)i; 
        else 
            header[i].b=0; 
        header[i].parent=-1; 
        header[i].left=header[i].right=-1; 
    } 
    for(i=0;i<256;i++) 
    { 
        for(j=i+1;j<256;j++) 
    	{ 
            if(header[i].count<header[j].count) 
        	{ 
                tmp=header[i]; 
                header[i]=header[j]; 
                header[j]=tmp; 
        	} 
    	} 
    } 
    for(i=0;i<256;i++)
	{
		if(header[i].count==0) 
        break;
	}
	int countOfChar=i-1;
    n=i; 
    m=2*n-1; 
    for(i=n;i<m;i++) 
    { 
        min1=999999999; 
        for(j=0;j<i;j++) 
    	{ 
            if(header[j].parent!=-1) 
                continue; 
            if(min1>header[j].count) 
        	{ 
                pt1=j; 
                min1=header[j].count; 
                continue; 
        	} 
    	} 
        header[i].count=header[pt1].count; 
        header[pt1].parent=i; 
        header[i].left=pt1; 
        min1=999999999; 
        for(j=0;j<i;j++) 
    	{ 
            if(header[j].parent!=-1)
                continue; 
            if(min1>header[j].count) 
        	{ 
                pt1=j; 
                min1=header[j].count; 
                continue; 
        	} 
    	} 
       header[i].count+=header[pt1].count; 
       header[i].right=pt1; 
       header[pt1].parent=i; 
    } 
    for(i=0;i<n;i++) 
    { 
        f=i; 
        header[i].bit[0]=0; 
        while(header[f].parent!=-1) 
    	{ 
        	j=f; 
            f=header[f].parent; 
            if(header[f].left==j) 
        	{ 
                j=strlen(header[i].bit); 
                memmove(header[i].bit+1,header[i].bit,j+1); 
                header[i].bit[0]='0'; 
        	} 
        	else 
        	{ 
                j=strlen(header[i].bit); 
                memmove(header[i].bit+1,header[i].bit,j+1); 
                header[i].bit[0]='1'; 
        	} 
    	} 
    }
//	 for(i=0;i<countOfChar;i++)
//	{
//		cout<<header[i].b<<" "<<header[i].count<<" "<<header[i].bit<<endl;
//	}
	/*哈弗曼构造结束*/
    fseek(ifp,0,SEEK_SET);          /*把文件指针指向文件的开头*/
    fwrite(&flength,sizeof(int),1,ofp);    //把哈弗曼代码写入ofp文件
    fseek(ofp,8,SEEK_SET); 
    buf[0]=0; 
    f=0; 
    pt1=8; 
    while(!feof(ifp)) 
    { 
        c=fgetc(ifp);    //从流中读取一个字符，并增加文件指针的位置
        f++; 
        for(i=0;i<n;i++) 
    	{ 
            if(c==header[i].b) break; 
    	} 
        strcat(buf,header[i].bit); //把header[i].bit所指字符串添加到buf结尾处
        j=strlen(buf);    //计算字符串buf的长度
        c=0; 
        while(j>=8) 
    	{ 
            for(i=0;i<8;i++)  
        	{ 
                if(buf[i]=='1') c=(c<<1)|1; 
                else c=c<<1; 
        	} 
            fwrite(&c,1,1,ofp); 
            pt1++; 
            strcpy(buf,buf+8); 
            j=strlen(buf); 
    	} 
        if(f==flength) 
			break; 
    } 
    if(j>0) 
    { 
        strcat(buf,"00000000"); 
        for(i=0;i<8;i++) 
    	{ 
            if(buf[i]=='1') c=(c<<1)|1; 
            else c=c<<1;
    	} 
        fwrite(&c,1,1,ofp); 
        pt1++;
    } 
    fseek(ofp,4,SEEK_SET);     /*fseek 用于二进制方式打开的文件,移动文件读写指针位置.第一个是文件流,第3个是指针零点位置,第2个是把指针移动到的地点. */
    fwrite(&pt1,sizeof(long),1,ofp); /*是要输出数据的地址,每次写入的位数,数据项的个数，目标文件地址*/
    fseek(ofp,pt1,SEEK_SET); 
    fwrite(&n,sizeof(long),1,ofp); 

    for(i=0;i<n;i++) 
    { 
        fwrite(&(header[i].b),1,1,ofp); 
        c=strlen(header[i].bit); 
        fwrite(&c,1,1,ofp);
		fwrite(&header[i].count,4,1,ofp);
	//	cout<<header[i].b<<" "<<header[i].count<<endl;
        j=strlen(header[i].bit); 
        if(j%8!=0)             /*按八位读取*/    
    	{ 
            for(f=j%8;f<8;f++) 
                strcat(header[i].bit,"0"); 
    	} 
        while(header[i].bit[0]!=0) 
    	{ 
            c=0; 			
            for(j=0;j<8;j++) 
        	{ 
                if(header[i].bit[j]=='1') c=(c<<1)|1; 
                else c=c<<1; 
        	} 
            strcpy(header[i].bit,header[i].bit+8);  /*把从header[i].bit+8地址开始且含有NULL结束符的字符串赋值到以header[i].bit开始的地址空间 */
            fwrite(&c,1,1,ofp); 
    	} 
    } 
    fclose(ifp); 
    fclose(ofp); 
    printf("压缩成功\n"); 
   
} 

void jieya()                                  /*解压*/
{ 
    char filename[255],buf[255],bx[255]; 
    unsigned char c;  char outFile[255];
    long i,j,m,n,f,p,l; 
    long flength; 
    FILE *ifp,*ofp; 
	
    printf("要解压的文件路径："); 
    gets(filename); 
    ifp=fopen(filename,"rb");                        
	if(ifp==NULL)
	{ 
		printf("打开文件出错\n"); 
	  return ;     	
	}
	printf("解压后的文件路径:");
    gets(outFile); 
    ofp=fopen(outFile,"wb");                     
	if(ofp==NULL)
	{
		printf("路径出错\n");     	
		return ;
	}
	
//	ifp=fopen("C:\\Documents and Settings\\Administrator\\桌面\\实验\\算法设计\\acm.yasuo","rb");
//	ofp=fopen("C:\\Documents and Settings\\Administrator\\桌面\\实验\\算法设计\\acm.jieyasuo","wb");
//	ifp=fopen("C:\\Users\\wen\\Desktop\\实验\\算法设计\\acm.yasuo","rb");
//	ofp=fopen("C:\\Users\\wen\\Desktop\\实验\\算法设计\\acm.jieyasuo","wb");
    fread(&flength,sizeof(long),1,ifp); 
    fread(&f,sizeof(long),1,ifp); 
    fseek(ifp,f,SEEK_SET); 
    fread(&n,sizeof(long),1,ifp); 
    for(i=0;i<n;i++) 
    { 
        fread(&header[i].b,1,1,ifp); 
        fread(&c,1,1,ifp); 
        p=(long)c; 
        header[i].ccc=p; 
		fread(&header[i].count,4,1,ifp);
        header[i].bit[0]=0; 
        if(p%8>0) m=p/8+1; 
        else m=p/8; 
        for(j=0;j<m;j++) 
    	{ 
            fread(&c,1,1,ifp); 
        	f=c; 
            itoa(f,buf,2); 
            f=strlen(buf); 
            for(l=8;l>f;l--) 
        	{ 
                strcat(header[i].bit,"0"); 
        	} 
            strcat(header[i].bit,buf); 
    	} 
        header[i].bit[p]=0; 
    } 
    for(i=0;i<n;i++) 
    { 
        for(j=i+1;j<n;j++) 
    	{ 
            if(strlen(header[i].bit)>strlen(header[j].bit)) 
        	{ 
                tmp=header[i]; 
                header[i]=header[j]; 
                header[j]=tmp; 
        	} 
    	} 
    }
	int head=createTree(n);
    p=strlen(header[n-1].bit); 
    fseek(ifp,8,SEEK_SET); 
    m=0; 
    bx[0]=0; 
    while(1) 
    { 
        while(strlen(bx)<(unsigned int)p) 
    	{ 
            fread(&c,1,1,ifp); 
        	f=c; 
            itoa(f,buf,2); 
            f=strlen(buf); 
            for(l=8;l>f;l--) 
        	{ 
                strcat(bx,"0"); 
        	} 
            strcat(bx,buf); 
    	} 
		/*
        for(i=0;i<n;i++) 
    	{ 
            if(memcmp(header[i].bit,bx,header[i].ccc)==0) break; 
    	} */
		int jj=jiema(head,bx,-1);
        strcpy(bx,bx+header[jj].ccc); 
        c=header[jj].b; 
        fwrite(&c,1,1,ofp); 
        m++; 
        if(m==flength) break; 
    } 
    fclose(ifp); 
    fclose(ofp); 
  //  printf("解压成功\n"); 
    return; 
}
int findMin(int len)
{
	int min=99999999;
	int minIndex;
	for(int i=0;i<len;i++)
	{
		if(header[i].count!=-1)
		{
			if(header[i].count<min)
			{
				min=header[i].count;
				minIndex=i;
			}
		}
	}
	return minIndex;
}
int jiema(int i,char *buf,int j)
{
	if(header[i].left==-1&&header[i].right==-1)
	{
		return i;
	}
	if(buf[j+1]=='0')
	{
		return jiema(header[i].left,buf,j+1);
	}else if(buf[j+1]=='1')
	{
		return jiema(header[i].right,buf,j+1);
	}
}

int createTree(int len)
{
	int i;
	int min1,min2;
	int c1,c2;
	for(i=0;i<len-1;i++)
	{
		min1=findMin(len+i);
		c1=header[min1].count;
		header[min1].count=-1;
		min2=findMin(len+i);
		c2=header[min2].count;
		header[min2].count=-1;
		header[len+i].left=min1;
		header[len+i].right=min2;
		header[len+i].count=c1+c2;
	}
	return len+len-2;
}

int main()                   /*主函数*/
{
	int c;
	double start,end;
	double sum;
	while(true)
	{
		cout<<"1.压缩   2.解压缩"<<endl;
		cin>>c;
		if(c==1)
		{
			sum=0;
			for(int i=0;i<1;i++)
			{
				start=clock();
				yasuo();
				end=clock();
				sum+=end-start;
			}
			cout<<"压缩时间: "<<sum/1<<"ms"<<endl;
		}
		else if(c==2)
		{
			sum=0;
			for(int j=0;j<1;j++)
			{
				start=clock();
				jieya();
				end=clock();
				sum+=end-start;
			}
			cout<<"解压时间: "<<sum/1<<"ms"<<endl;
		}
	}
}

