/*
【练习3】
组个最小数
给定数字0-9各若干个。你可以以任意顺序排列这些数字，但必须全部使用。目标是使得最后得到的数尽可能小（注意0不能做首位）。

 例如：给定两个0，两个1，三个5，一个8，我们得到的最小的数就是10015558。 
现给定数字，请编写程序输出能够组成的最小的数。

输入格式： 
每个输入包含1个测试用例。每个测试用例在一行中给出10个非负整数，顺序表示我们拥有数字0、数字1、……数字9的个数。
整数间用一个空格分隔。10个数字的总个数不超过50，且至少拥有1个非0的数字。 
输出格式： 
在一行中输出能够组成的最小的数。 

输入样例：
2 2 0 0 0 3 0 0 1 0
输出样例：
10015558
*/
# include <stdio.h>

int main(void)
{
	printf("请输入10个整数：");
	int i = 1 , j = 2 , num[11];
	while ( i <= 10 )
	{
		scanf("%d",&num[i]);
		i++;
	}

	i = 1;
	while ( i <= 10)
	{
		while ( j <= 11 - i)
		{
			if ( num[i] < num[j] && num[j] != 0 )
			{
				num[i] = num[i] + num[j];//a = a + b
				num[j] = num[i] - num[j];//b = a - b
				num[i] = num[i] - num[j];//a = a - b
			}
			j++;
		}
		i++;
	}

	i = 1;
	if ( num[1] == 0 )
	{
		while ( i <= 9 )
		{
			if ( num[i] != 0 )
			{
				num[i] = num[i] + num[1];//a = a + b
				num[1] = num[i] - num[1];//b = a - b
				num[i] = num[i] - num[1];//a = a - b
				break;
			}
		}
	}

	i = 1;
	while ( i <= 10 )
	{
		printf("%d",num[i]);
	}
	return 0;
}