/*
Description
����ͼ�������û�������ʾ���֣�

���ڣ���������һ�������Ļ������������������Щ��������ʾ�����ֵķ�Χ
��Ҫ��ʹ��ȫ���Ļ������������ֲ�����0��ͷ����

Input
����ĵ�һ������T��ʾ�ж�����������ݣ�1��T��100����
ÿ���������Ϊһ�У�ֻ��һ���������������������еĻ���������n��2��n��100����

Output
Ϊÿ������������һ�У���2��������ɣ�
�ֱ��Ӧ����ʾ����С�������������м�ʹ��һ���ո������

Sample Input
3
3
6
7
Sample Output
7 7
6 111
8 711
*/
# include <stdio.h>
int match( int x );
int match( int x )
{
	int a,b,j;
	//min:
	if ( ((x-1) / 7) %2 == 0 )//ż����7��������֮��
	{
		switch ( x %7 )
		{
			case 1:printf(""); 
				break;
			case 2:printf("1"); goto rear; break;
			case 3:printf("7"); goto rear; break;
			case 4:printf("4"); goto rear; break;
			case 5:printf("2"); goto rear; break;
			case 6: printf("6");
					for ( j = 1 ; j <= (x / 7) - 1 ; j++ )
					{
						printf("8");	
					}
					x > 7 ? printf("0") : 1 ;
					break;
		}
		rear:
		{
			for ( j = 1 ; j <= x / 2 ; j++ )
			{
				printf("8");	
			}
		}
		printf("<�ո�>"); 
	}
	else
	{
	
	}

	//max:
	b = x / 2;
	if ( b )
	{
		if ( x %2 && x >= 3 )
		{
			printf("7");
			b--;
		}
		for ( j = 1 ; j <= b ; j++ )
			printf("1");
		printf("\n");
	}
	return 1;
}

int main()
{
	int i,x,n;
	scanf("%d",&n);
	for ( i = 1 ; i <= n ; i++ )
	{
		scanf("%d",&x);
		match(x);
	}
	return 0;
}