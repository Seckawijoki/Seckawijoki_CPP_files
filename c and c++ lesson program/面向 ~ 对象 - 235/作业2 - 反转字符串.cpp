/*
��д��������ָ���������дһ���������ַ�������
���������е��øú������û������һ���ַ������������
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
	char *str , ps[33] , qr[33];//�迪���ڴ�~
	str = ps;
	scanf("%s",str);
	reverse(str,qr);
	printf("%s\n",qr);
	return 0;
}
