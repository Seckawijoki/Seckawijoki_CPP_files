/*
����ϰ1��
��������
����Ҫ��������n�������в��Ҹ�����x������ҵ������x��λ�ã���0��ʼ���������û���ҵ������"Not Found"��

�����ʽ�� 
�����ڵ�1���и���2��������n��<=20����x����2�и���n�����������־������������ͣ�����Կո�ָ��� 
�����ʽ�� 
��һ�������x��λ�ã�����"Not Found"�� 

��������1��
5 7 3 5 7 1 9
�������1��
2

��������2��
5 7 3 5 8 1 9
�������2��
Not Found
*/
# include <stdio.h>

int main(void)

{
	int a,x,n,t = 1 , b = 0;
	printf("Please input the number of the integers ,\"n\"\n");
	printf("the definite number \"x\"\n");
	printf("and the \"n\"\ integers : \n");
	scanf("%d %d",&n,&x);
	while ( n >= t )
	{
		++t;
		scanf("%d",&a);
		if ( a == x )
		{
			printf("%d\n",t - 2);
			b++;//��ϵ��һ��ע�͡�
		}
	}
	if ( b )//���ж��Ƿ������ͬ������b==0��û����ͬ�ġ�
	{
		printf("Not found.\n");
	}
	else
	{
		return 0;
	}
}
/*
	��ʼ����ȷ��ֻ���һ��"Not found."��
	���λ�����⣬δ�������Ŀ��
	����n�����ƴ���

*/