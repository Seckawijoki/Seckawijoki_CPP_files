# include <stdio.h>
# include <string.h>
void main()
{
	char str[10], *pstr;
	pstr = "12345";     //pstr指向"12345"
	strcpy (str, pstr);   //将pstr所指向的字符串复制到数组str中
	pstr = str;
	printf ("The Length of str is: %d\n", strlen(pstr));
	//输出字符串的长度5
}