# include <stdio.h>
# include <string.h>
void main()
{
	char str[10], *pstr;
	pstr = "12345";     //pstrָ��"12345"
	strcpy (str, pstr);   //��pstr��ָ����ַ������Ƶ�����str��
	pstr = str;
	printf ("The Length of str is: %d\n", strlen(pstr));
	//����ַ����ĳ���5
}