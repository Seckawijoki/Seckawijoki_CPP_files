/*Description
给定一个日期，输出这个日期是该年的第几天。

Input
输入数据有多组，每组占一行，数据格式为YYYY/MM/DD组成，具体参见sample input ,另外，可以向你确保所有的输入数据是合法的。
 
Output
对于每组输入数据，输出一行，表示该日期是该年的第几天。

Sample Input

1985/1/20 2006/3/12

Sample Output

20 71 
*/
# include <stdio.h>
# include <math.h>
int main(void)
{
	int y,m,d;
	int day( int y , int m , int d );
	while ( scanf("%d/%d/%d",&y,&m,&d) != EOF )
		day(y,m,d);
	return 0;
}

int day( int y , int m , int d )
{
	int leap = 0,x;
	if ( y %400 ==0 || ( y %4 == 0 && y %100 != 0 ) )
		leap++;
/*-------------------旧版-------------------------
	int z = 0;
	switch ( m )//顺序做！
	{
		case  1:z +=  31 , x = 31;break;//31
		case  2:z +=  59 , x = 28;break;//28
		case  3:z +=  90 , x = 31;break;//31
		case  4:z += 120 , x = 30;break;//30
		case  5:z += 151 , x = 31;break;//31
		case  6:z += 181 , x = 30;break;//30
		case  7:z += 212 , x = 31;break;//31
		case  8:z += 243 , x = 31;break;//31
		case  9:z += 273 , x = 30;break;//30
		case 10:z += 304 , x = 31;break;//31
		case 11:z += 334 , x = 30;break;//30
		case 12:z += 365 , x = 31;break;//31
	}

	leap && m > 2 ? z++ : z = z ;//卡在这里。
	z = z + d - x;
	printf("%d\n",z);
-------------------------------------------------*/
	switch ( m - 1 )//快捷：叠加形式。
	{
		case 11:d +=  30;
		case 10:d +=  31;
		case  9:d +=  30;
		case  8:d +=  31;
		case  7:d +=  31;
		case  6:d +=  30;
		case  5:d +=  31;
		case  4:d +=  30;
		case  3:d +=  31;
		case  2:leap ? d += 29 : d += 28;
		case  1:d +=  31;
		case  0:d +=   0;
	}
	printf("%d\n",d);

	return 1;
}