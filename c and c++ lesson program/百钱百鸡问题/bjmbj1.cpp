//��Ǯ��ټ�-1,��ٷ�
//����һֵǮ�壬��ĸһֵǮ����������ֵǮһ������Ǯ��ټ����ʼ��̣�ĸ�����������Σ�

#include <stdio.h>

int main()
{
	int n=100;
	printf("cock     hen      chicken\n");
	for (int i=0; i<=n; i++)
	  for (int j=0; j<=n; j++)
		for (int k=0; k<=n; k++)
		  
			if ((n==5*i+3*j+k/3)&&(k%3==0)&&(n==i+j+k))
		      printf("%d cocks, %d hens, %d chickens\n",i,j,k);
	
	return 0;
}