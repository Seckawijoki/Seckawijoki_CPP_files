//��������дһ����alltrim����ȥ���ַ����ġ�ǰ���ո񡿺͡������ո񡿡� 
#include <stdio.h>
#include <string.h>
void alltrim (char *psstr, char *pdstr);
void main ( )
{
	  char *pstr, str[20];
	  pstr = "  Good Bye!  ";
	  printf ("before alltrim: %s\n", pstr);
	  alltrim (pstr, str);
	  printf ("after  alltrim: %s\n", str);
}
void alltrim (char *psstr, char *pdstr)
{
	  char *pstart, *pend;

	  //��pstartָ����ߵ�һ���ǿո��ַ���λ��
	  pstart = psstr;   
	  while (*pstart == ' ')
		  pstart++;

	  //��pendָ���ұߵ�һ���ǿո��ַ���λ��
	  pend = pstart + strlen(pstart) - 1;  
	  while (pend > pstart && *pend == ' ')
		  pend--;

	  //��pstart��ָ����ַ���pend��ָ����ַ�������pdstr��
	  while (pstart <= pend)
		  *pdstr++ = *pstart++;
	  *pdstr = '\0';   //���ַ���������־0
}
