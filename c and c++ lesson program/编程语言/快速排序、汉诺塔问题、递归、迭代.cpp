# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std;
void display(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	  cout<<setw(5)<<array[i];
  cout<<endl;
}

/*
	快速排序 递归算法 
*/
int Partition( int array[], int low, int high )
{
	int pivotkey = array[low];
	while ( low < high )
	{
		while (low < high && array[high] >= pivotkey)--high;
		array[low] = array[high];
		while (low < high && array[low]  <= pivotkey)++low;
		array[high] = array[low];
	}
	array[low] = pivotkey;
	return low;
}
void QuickSort_Recursively(int array[], int low, int high)
{
	int pivotlocation;
	if ( low < high )
	{
		pivotlocation = Partition(array,low,high);
		QuickSort_Recursively(array,low,pivotlocation-1);
		QuickSort_Recursively(array,pivotlocation+1,high);
	}
}
/*
	快速排序 迭代算法 
*/
void QuickSort_Iteratively(int array[], int low, int high) 
{  
    if(high - low < 1) return;  
    int* stk = new int[high-low+1];  
    int p = 0;  
    int l, h, m;  
    stk[p++] = low;  
    stk[p++] = high;  
    while(p != 0)  
    {  
        h=stk[--p];  
        l=stk[--p];  
        if (l<h)  
        {  
            m=Partition(array,l,h);  
            if (m-1>l)  
            {  
                stk[p++]=l;  
                stk[p++]=m-1;  
            }  
            if (m+1<h)  
            {  
                stk[p++]=m+1;  
                stk[p++]=h;  
            }  
        }  
    }  
    delete[] stk;  
}
int count;

/*
	汉诺塔问题 递归算法 
*/
void Move(int n, char a, char b)
{
    ++count;
    cout<<"第"<<setw(3)<<count<<"次移动 Move "<<n
		<<": Move from "<<a<<" to "<<b<<" !\n";
}
void HanoiTower_Recursively(int n, char a, char b, char c)
{
	if (n == 1)
    {
      Move(n, a, c);
    }
    else
    {
      HanoiTower_Recursively(n - 1, a, c, b);
      Move(n, a, c);
      HanoiTower_Recursively(n - 1, b, a, c);
    }
} 

int zhua[100]={0},zhub[100]={0},zhuc[100]={0};
char charis(char x,int n)
{
	switch(x)
	{
		case'A':
		  return (n%2 == 0) ? 'C' : 'B';
		case'B':
		  return (n%2 == 0) ? 'A' : 'C';
		case'C':
		  return (n%2 == 0) ? 'B' : 'A';
		default:
		  return'0';
	}
}
void print(char lch,char rch)
{
	if(lch=='A')
	{
		switch(rch)
		{
		case'B':
			zhub[0]++;
			zhub[zhub[0]]=zhua[zhua[0]];
			zhua[zhua[0]]=0;
			zhua[0]--;
			break;
		case'C':
			zhuc[0]++;
			zhuc[zhuc[0]]=zhua[zhua[0]];
			zhua[zhua[0]]=0;
			zhua[0]--;
			break;
		default:
			break;
		}
	}
	if(lch=='B')
	{
		switch(rch)
		{
		case'A':
			zhua[0]++;
			zhua[zhua[0]]=zhub[zhub[0]];
			zhub[zhub[0]]=0;
			zhub[0]--;
			break;
		case'C':
			zhuc[0]++;
			zhuc[zhuc[0]]=zhub[zhub[0]];
			zhub[zhub[0]]=0;
			zhub[0]--;
			break;
		default:
		  break;
		}
	}
	if(lch=='C')
	{
		switch(rch)
		{
		case'A':
			zhua[0]++;
			zhua[zhua[0]]=zhuc[zhuc[0]];
			zhuc[zhuc[0]]=0;
			zhuc[0]--;
			break;
		case'B':
			zhub[0]++;
			zhub[zhub[0]]=zhuc[zhuc[0]];
			zhuc[zhuc[0]]=0;
			zhuc[0]--;
			break;
		default:
		  break;
		}
	}
	cout<<setw(5)<<' ';
	int i;
	cout<<'(';
	for(i = 1; i <= zhua[0]; ++i)
	  cout<<zhua[i];
  cout<<')'<<'(';
	for(i = 1; i <= zhub[0]; ++i)
	  cout<<zhub[i];
  cout<<')'<<'(';
	for(i = 1; i <= zhuc[0]; ++i)
	  cout<<zhuc[i];
  cout<<')'<<endl;
}

/*
	汉诺塔问题 迭代算法 
*/
void HanoiTower_Iteratively(int n){ 
  //分配2^n个空间
  bool*isrev = new bool[(int)pow(2,n)];
  for(int i = 0; i < pow(2,n); ++i)
    isrev[i] = false;
  //循环计算是否逆序
  for(int ci = 2; ci <= n ; ++ci){
	 for (int zixh = (int)pow(2, ci-1); zixh < pow(2,ci); zixh += 4)
	  //初始值重复一次，自增值可加4，减少循环次数。
		  isrev[zixh] = isrev[(int)pow(2, ci) - zixh];
		  //该位置为中间位置，且奇次幂逆序，偶数幂不逆序
	  isrev[(int)pow(2,ci)]=((ci-1)%2 == 0) ? false : true;
	}
	char lch='A', rch;
	rch= (n %2 == 0 ? 'B' : 'C');
	cout<<setw(5)<<1;
	cout<<lch<<"->"<<rch;
	print(lch, rch);
	for(int k = 2; k < pow(2,n); ++k){
		if(k %2 == 0)
		  //charis(char, int)输出左右相邻的字母。 
		  rch = charis(lch, n);
		else
			lch = charis(rch, n);
		cout<<setw(5)<<k;
		if( isrev[k] ){
	    cout<<rch<<"->"<<lch;
		  //print(char, int)输出一次移动的过程与结果。 
			print(rch, lch);
		}	else {
	    cout<<lch<<"->"<<rch;
			print(lch, rch);
		}
	}
}
int main()
{
	int a1[] = {21,25,49,25,16,8};
	int a2[] = {21,25,49,25,16,8};
	int size = sizeof(a1)/sizeof(a1[0]);
	display(a1, size);
	QuickSort_Recursively(a1, 0, size-1);
	cout<<"快速排序：递归算法："; 
	display(a1, size);
	QuickSort_Iteratively(a2, 0, size-1);
	cout<<"快速排序：迭代算法："; 
	display(a2, size);
	count = 0;
	cout<<"汉诺塔问题：递归算法：\n"; 
	HanoiTower_Recursively(3, 'A', 'B', 'C');
	cout<<"汉诺塔问题：迭代算法：\n"; 
	HanoiTower_Iteratively(3);
	return 0;
}
