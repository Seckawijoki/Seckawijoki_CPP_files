/*
2. ����4��4�ж�����b����Ԫ��Ϊb[i][j]=i+j+1(i,j=0,1,2,3)�����ʵ�֣�
(1)��ڶ���Ԫ��֮�͡�
(2)�������Ԫ�ص�ƽ��ֵ��
(3)������b�е����������С�������Խ���Ԫ�ص�ƽ���͡�
*/
#include <iostream.h>
void main()
{
	int b[4][4],i,j;
	/*Ϊ����b��Ԫ�ظ�ֵ*/
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
	//��ڶ���Ԫ��֮��
	int sum_line2=0;
	for(j=0;j<4;j++)
		sum_line2+=b[1][j];
	cout<<"sum_line2="<<sum_line2<<endl;
	//�������Ԫ��֮ƽ��ֵ
	int sum_col3=0;
	for(i=0;i<4;i++)
		sum_col3+=b[i][2];
	cout<<"ave_col3="<<sum_col3/4.0<<endl;
	//�����������С�������Խ���Ԫ��֮ƽ����
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
