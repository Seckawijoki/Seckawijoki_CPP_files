/*
【练习3选作】念数字
输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出"fu"字。十个数字对应的拼音如下： 
0: ling 1: yi 2: er 3: san 4: si 5: wu 6: liu 7: qi 8: ba 9: jiu

提示：
1.每个数字对应的拼音可用二维字符数组存放：
char a[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

2.把一个整型数转化为字符串的方法：
char str[255];
sprintf(str, "%d", -100); //将-100转为10进制表示的字符串赋值给str数组。

输入格式： 
输入在一行中给出一个整数，如： 1234 。 
提示：整数包括负数、零和正数。 
输出格式： 
在一行中输出这个整数对应的拼音，每个数字的拼音之间用空格分开，行末没有最后的空格。如 yi er san si。

输入样例：
-600
输出样例：
fu liu ling ling
*/
# include <iostream.h>
int main(void)
{
	int i,j,x;
	char ch;
	char a[11][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};//存储作用。//未发现数组的作用。
	for ( i = 0 ; i < 11 ; i++ )
	{
		for ( j = 0 ; j < 5 ; j++ )
			cout<<a[i][j];
		cout<<endl;
	}
	while ( 1 )
	{
		cin>>ch;
		switch ( ch )
		{
			case ('-'):x = 11;break;
			case ('0'):x = 0;break;
			case ('1'):x = 1;break;
			case ('2'):x = 2;break;
			case ('3'):x = 3;break;
			case ('4'):x = 4;break;
			case ('5'):x = 5;break;
			case ('6'):x = 6;break;
			case ('7'):x = 7;break;
			case ('8'):x = 8;break;
			case ('9'):x = 9;break;
			default :cout<<'\n';
		}
		for ( j = 0 ; j < 5 ; j++ )
			cout<<a[x][j];
		cout<<' ';
	}
	return 0;
}