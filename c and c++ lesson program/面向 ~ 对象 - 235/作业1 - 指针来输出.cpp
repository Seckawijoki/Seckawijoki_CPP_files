/*
��д���򣬽��û������n��������ŵ�����a�У�
n���û�ָ����Ȼ������ָ������������������ÿ��Ԫ�ص�ֵ�� 
*/
# include <stdio.h>
int main()
{
	int i,n;
	int a[9999];
	int *pa;
	scanf("%d",&n);
	pa = a;
	for ( i = 0 ; i < n ; i ++ )
	{
		scanf("%d",&a[i]);
		printf("a[%d] = %d\n",i,*(pa+i));
	}
	return 0;
}