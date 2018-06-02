/*
【练习4选作】
然后是几点
	有时候人们用四位数字表示一个时间，比如1106表示11点零6分。现在，你的程序要根据起始时间和流逝的时间计算出终止时间。 
读入两个数字，第一个数字以这样的四位数字表示当前时间，第二个数字表示分钟数，
计算当前时间经过那么多分钟后是几点，结果也表示为四位数字。
当小时为个位数时，没有前导的零，即5点30分表示为530。
	注意，第二个数字表示的分钟数可能超过60，也可能是负数。 

输入格式：
输入在一行中给出2个整数，分别是四位数字表示的起始时间、以及//流逝的分钟数//，其间以空格分隔。
  注意：在起始时间中，当小时为个位数时，没有前导的零，即5点30分表示为530；流逝的分钟数可能超过60，//也可能是负数。//

输出格式：
输出四位数字表示的终止时间。//题目保证起始时间和终止时间在同一天内。//

输入样例：
1120 110

输出样例：
1310

*/

//修改版//
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
----------------旧版判断做法----------------

	int x,y;
	y = c%60;//流逝时间中余出的分钟数
	x = ( c - y ) / 60;//流逝时间中的小时数

	//需判断负数。//

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

//-----------直接算法------------
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
	负数的流逝成立。
	
	1st error:前一天的判断未有。

*/