/*
����ϰ3��
����ƽ��С��
������A��B��C����С��״��ͬ��������һ������������������ͬ��Ҫ���ҳ������һ������

�����ʽ�� 
������һ���и���3����������˳���Ӧ��A��B��C�������� 
�����ʽ�� 
��һ�������Ψһ���Ǹ���һ������ 

����������
1 1 2
���������
C
*/
# include <stdio.h>

int main(void)
{
	int a,b,c;

	printf("Please input the three numbers of balls : ");
	
	start:
	scanf("%d %d %d",&a,&b,&c);

	if ( a != b && a != c && b == c )
	{	
		printf("A is the different . \n");
	}
	if ( b != a && b != c && a == c )
	{
		printf("B is the different . \n");
	}
	if ( c != a && c != b && a == b )
	{
		printf("C is the different . \n");
	}
	else
	{	
		printf("Error , please be again : \a");
		goto start;
	}
	if ( a == b && b == c && a == c)
	{	
		printf("No difference !\n");
		printf("Can be again : \n");
		goto start;
	}


	printf("Can be again : \n");
	goto start;
}
/*
	�㷨����㡣
	���Ⱥŷ��Ÿ��

*/