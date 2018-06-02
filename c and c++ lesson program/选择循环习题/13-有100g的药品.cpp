/*
有100g的药品，用天平称量，砝码只有1g、2g、5g共3种，问： 
若要求加的砝码总数为50个，有几种不同的加法？若要求总数
为30个呢？请编程求解上述问题。
*/
# include <stdio.h>
void sum( int x );
void main()
{
	int n;
	while ( 1 )
	{
		printf("请选择砝码总数：\n1.50个\n2.30个\n");
		scanf("%d",&n);
		if ( n == 1 )
			sum(50);
		else if ( n == 2 )
			sum(30);
		else
		{
			printf("输入有误！\n再一次");
			continue;
		}
	}
}

void sum( int x )
{
	int a,b,c;
	for ( c = 1 ; c <= 20 ; c++ )
		for ( b = 1 ; b <= 50 ; b++ )
			if ( x - 5 * c - 2 * b >= 0 )
				printf("%d个1g，%d个2g和%d个5g\n",x - 5 * c - 2 * b,b,c);
}