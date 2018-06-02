/*
题目描述
编写一个函数打印圣诞树，用户在主函数中输入打印的行数n，
调用该函数打印具有n行的圣诞树。

输入
行数n

输出
具有n行的圣诞树

样例输入
10
样例输出
         *
        ***
       *****
      *******
     *********
    ***********
   *************
  ***************
 *****************
*******************
*/
# include <stdio.h>
int shengdanshu( int x )
{
	int i,j;
	for ( i = 1 ; i <= x ; i++ )
	{
		for ( j = x - i ; j > 0 ; j-- )
			printf(" ");
		for ( j = 0 ; j < i ; j++ )
			printf("%2c",'*');
		printf("\n");
	}
	return 1;
}
int main()
{
	int x;
	scanf("%d",&x);
	shengdanshu(x);
	return 0;
}
