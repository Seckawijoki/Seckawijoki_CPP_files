#include<stdio.h>
#include<iostream>
using namespace std;

void Josegh(int m, int n)
{
	int a[100], i, j;
	
	//给小孩编号         
	for (i = 0; i < m; i++)     
		a[i] = i+1;             
	int k = 1; //标识处理第k个离开的小孩         
	i = -1; //数组下标(下一个值0就是第一个小孩的下标)         
	//处理获胜前的小孩         
	for(;;)
	{
		for (j = 0; j < n;)
		{
			i=(i+1)%m; //对下标加1求模
			if(a[i]!=0) //如果该元素的小孩在圈中，则承认数数有效              
				j++;
		}
		if(k==m)
			break; //该小孩是最后一个(胜利者)吗？         
		cout << a[i] << ' '; //输出离开的小孩之编号          
		a[i]=0; //标识该小孩已离开     
		k++; //准备处理下一个圈中小孩
	}
	cout << a[i] << endl; //输出胜利者
}

int main()
{
	int t, m, n;

	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		Josegh(m, n);
	}

	return 0;
}