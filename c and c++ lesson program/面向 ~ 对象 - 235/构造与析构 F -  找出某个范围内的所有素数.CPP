/*
题目描述
采用埃拉托斯特尼筛法求素数的算法可用以下CSieve类来实现:
class CSieve
{
private:
        char *p_sieve;
        unsigned long num;		//num是最大范围
public:
        CSieve(unsigned long n);
        void printPrime();
        ~CSieve();
};
其中p_sieve为数组指针, 
p_sieve[i]=1表示i是素数, 
p_sieve[i]=0表示i不是素数。
编写程序采用上述类来打印某个范围内的所有素数。

输入
测试数据的组数
n1
n2
......
输出
2到n1的所有素数
2到n2的所有素数
......
样例输入
2
10
20
样例输出
2 3 5 7
2 3 5 7 11 13 17 19
*/
# include <stdio.h>
class CSieve
{
private:
	char *p_sieve;
	unsigned long number;		//num是最大范围
public:
	CSieve( unsigned long n )
	{
		number = n;
		p_sieve = new char [number+1];
	}
	void IsItAPrimeNumber()
	{
		unsigned long i;
		for ( i = 2 ; i <= number ; i ++ )
			p_sieve[i] = Judging(i);
	}
	char Judging( unsigned long i )
	{
		unsigned long j;
		if ( i == 2 )
			return '1';
		else
		{
			for ( j = 2 ; j < i ; j ++ )
				if ( i %j == 0 )
					return '0';
			return '1';
		}
	}
    void DisplayingPrime()
	{//格式错误。不得解。
		unsigned long i,k;
		for ( i = 2 , k = 0; i <= number ; i++ )
		{
			if ( p_sieve[i] == '1' )
			{
				k++;
				printf("%d ",i);
				if ( k %10 == 0 )
					printf("\n");
			}	
		}
		printf("\n");
		/*
		if ( p_sieve[i] == '1' )
			printf("%d\n",i);
		else
			printf("\n");
		*/
	}
    ~CSieve()
	{
		delete [] p_sieve;
	}
};
int main()
{
	int t;
	unsigned long number;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%ld",&number);
		CSieve sieveOne(number);
		sieveOne.IsItAPrimeNumber();
		sieveOne.DisplayingPrime();
	}
	return 0;
}
