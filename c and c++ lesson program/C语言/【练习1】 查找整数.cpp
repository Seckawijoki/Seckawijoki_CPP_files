/*
【练习1】
查找整数
本题要求从输入的n个整数中查找给定的x。如果找到，输出x的位置（从0开始数）；如果没有找到，输出"Not Found"。

输入格式： 
输入在第1行中给出2个正整数n（<=20）和x，第2行给出n个整数。数字均不超过长整型，其间以空格分隔。 
输出格式： 
在一行中输出x的位置，或者"Not Found"。 

输入样例1：
5 7 3 5 7 1 9
输出样例1：
2

输入样例2：
5 7 3 5 8 1 9
输出样例2：
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
			b++;//联系下一个注释。
		}
	}
	if ( b )//来判断是否存在相同整数。b==0即没有相同的。
	{
		printf("Not found.\n");
	}
	else
	{
		return 0;
	}
}
/*
	开始难以确认只输出一个"Not found."。
	输出位置问题，未看清楚题目。
	不对n作限制处理。

*/