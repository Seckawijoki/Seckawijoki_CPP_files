/*
Description
青年歌手大奖赛中，评委会给参赛选手打分。
选手得分规则为去掉一个最高分和一个最低分，然后计算平均得分，请编程输出某选手的得分。

Input
输入数据有多组，每组占一行，每行的第一个数是n(2<n<=100)，表示评委的人数，然后是n个评委的打分。
 
Output
对于每组输入数据，输出选手的得分，结果保留2位小数，每组输出占一行。

Sample Input

3 99 98 97 
4 100 99 98 97

Sample Output

98.00 
98.50 
*/
# include <stdio.h>
int main()
{
	int n,i,j,sum;
	int x[101];//下表必须明确，不能是任何变量。
	while ( scanf("%d",&n) != EOF )
	{
	
		for ( i = 0 ; i < n ; i++ )
			scanf("%d",&x[i]);
		for ( i = 0 ; i < n ; i++ )
			for ( j = i + 1 ; j < n ; j++ )
				x[i] > x[j] ? x[i] = x[i] + x[j] ,
							  x[j] = x[i] - x[j] ,
							  x[i] = x[i] - x[j] : 1 ;
		for ( sum = 0 , i = 1 ; i < n - 1 ; i++ )
			sum += x[i];
		printf("%.2f\n",double(sum)/ (n - 2) );
	}
	return 0;
}