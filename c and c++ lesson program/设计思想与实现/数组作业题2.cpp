/*
2. 设有4行4列队数组b，其元素为b[i][j]=i+j+1(i,j=0,1,2,3)。编程实现：
(1)求第二列元素之和。
(2)求第三列元素的平均值。
(3)求数组b中的最大数，最小数及主对角线元素的平方和。
*/
#include <iostream.h>
void main()
{
	int b[4][4],i,j;
	/*为数组b各元素赋值*/
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			b[i][j]=i+j+1;
			cout<<" "<<b[i][j];

		}
		cout<<endl;	
	}
	cout<<"--The result--"<<endl;
	//求第二行元素之和
	int sum_line2=0;
	for(j=0;j<4;j++)
		sum_line2+=b[1][j];
	cout<<"sum_line2="<<sum_line2<<endl;
	//求第三行元素之平均值
	int sum_col3=0;
	for(i=0;i<4;i++)
		sum_col3+=b[i][2];
	cout<<"ave_col3="<<sum_col3/4.0<<endl;
	//求最大数，最小数及主对角线元素之平方和
	int max_elem=b[0][0],min_elem=b[0][0],sum_diag=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(b[i][j]>max_elem)max_elem=b[i][j];
			if(b[i][j]<min_elem)min_elem=b[i][j];
			if(i==j)sum_diag+=b[i][j]*b[i][j];
		}
	}
	cout<<"max_elem="<<max_elem<<endl;
	cout<<"min_elem="<<min_elem<<endl;
	cout<<"sum_diag="<<sum_diag<<endl;
}
