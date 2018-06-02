/*
【练习3】
用天平找小球
三个球A、B、C，大小形状相同且其中有一个球与其他球重量不同。要求找出这个不一样的球。

输入格式： 
输入在一行中给出3个正整数，顺序对应球A、B、C的重量。 
输出格式： 
在一行中输出唯一的那个不一样的球。 

输入样例：
1 1 2
输出样例：
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
	算法不简便。
	不等号符号搞错。

*/