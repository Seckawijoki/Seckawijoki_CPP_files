/*
����ϰ4ѡ����
Ȼ���Ǽ���
	��ʱ����������λ���ֱ�ʾһ��ʱ�䣬����1106��ʾ11����6�֡����ڣ���ĳ���Ҫ������ʼʱ������ŵ�ʱ��������ֹʱ�䡣 
�����������֣���һ����������������λ���ֱ�ʾ��ǰʱ�䣬�ڶ������ֱ�ʾ��������
���㵱ǰʱ�侭����ô����Ӻ��Ǽ��㣬���Ҳ��ʾΪ��λ���֡�
��СʱΪ��λ��ʱ��û��ǰ�����㣬��5��30�ֱ�ʾΪ530��
	ע�⣬�ڶ������ֱ�ʾ�ķ��������ܳ���60��Ҳ�����Ǹ����� 

�����ʽ��
������һ���и���2���������ֱ�����λ���ֱ�ʾ����ʼʱ�䡢�Լ�//���ŵķ�����//������Կո�ָ���
  ע�⣺����ʼʱ���У���СʱΪ��λ��ʱ��û��ǰ�����㣬��5��30�ֱ�ʾΪ530�����ŵķ��������ܳ���60��//Ҳ�����Ǹ�����//

�����ʽ��
�����λ���ֱ�ʾ����ֹʱ�䡣//��Ŀ��֤��ʼʱ�����ֹʱ����ͬһ���ڡ�//

����������
1120 110

���������
1310

*/

//�޸İ�//
# include <stdio.h>
# include <math.h>

void main()

{
	int a,b,c,t;
	printf("Please input the present time ( eg : 1120 )\n");
	printf("and the passing minutes with a space separation : ");

	start:
	scanf("%d %d",&t,&c);
	a = t / 100;
	b = t %100;

/*
----------------�ɰ��ж�����----------------

	int x,y;
	y = c%60;//����ʱ��������ķ�����
	x = ( c - y ) / 60;//����ʱ���е�Сʱ��

	//���жϸ�����//

	if ( a >= 0 && a < 24 && b >= 0 && b < 60 )
	{
		b = b + y;

		if ( b >= 0 && b < 60 )
		{
			a = a + x;	
		}
		else if ( b < 0 )
		{
			b = b + 60;
			a = a + x - 1;
		}
		else
		{
			b = b - 60;
			a = a + x + 1;
		}


		if ( a >= 24 )
			{
				printf("\n");
				printf("It is the second day ! Please be again : ");
				goto start;
			}

		else if ( a < 0 )
			{
				printf("\n");
				printf("It was yesterday ! Please be again : ");
				goto start;
			}
		else 
		{
		printf("The result is %d:%d\n",a,b);
		}

	}
	else 
	{
		printf("\n");
		printf("You have input the wrong numbers , please input the right again : ");
		goto start;
	}
*/

//-----------ֱ���㷨------------
	b = b + c;
	a = a + b / 60;
	b = b %60;
	if ( b < 0 || a < 0 )
	{
		printf("It was yesterday ! Please be again : ");
		goto start;
	}
	if ( a >= 24 )
	{
		printf("\n");
		printf("It is the second day ! Please be again : ");
		goto start;
	}

	printf("The result is %d:%d\n",a,b);

	printf("\n");
	printf("You can do it again : ");
	goto start;

}
/*
	���������ų�����
	
	1st error:ǰһ����ж�δ�С�

*/