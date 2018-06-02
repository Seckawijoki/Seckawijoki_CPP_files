/*
编写程序，利用指针操作，编写一个函数将字符串反序，
在主函数中调用该函数将用户输入的一个字符串反序输出。
*/
#include <stdio.h>
#include <string.h>
void reverse( char *str , char *qr )
{
	char *pstart;
	pstart = str + strlen(str) - 1;
	while( str <= pstart )
	{
		*qr++ = *pstart--;
		*qr = '\0';
	}
}
int main()
{
	char *str , ps[33] , qr[33];//需开辟内存~
	str = ps;
	scanf("%s",str);
	reverse(str,qr);
	printf("%s\n",qr);
	return 0;
}
