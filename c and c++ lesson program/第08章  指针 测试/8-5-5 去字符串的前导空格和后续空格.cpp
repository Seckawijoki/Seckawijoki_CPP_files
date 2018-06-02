//【例】编写一函数alltrim用于去掉字符串的【前导空格】和【后续空格】。 
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

	  //将pstart指向左边第一个非空格字符的位置
	  pstart = psstr;   
	  while (*pstart == ' ')
		  pstart++;

	  //将pend指向右边第一个非空格字符的位置
	  pend = pstart + strlen(pstart) - 1;  
	  while (pend > pstart && *pend == ' ')
		  pend--;

	  //将pstart所指向的字符至pend所指向的字符拷贝到pdstr中
	  while (pstart <= pend)
		  *pdstr++ = *pstart++;
	  *pdstr = '\0';   //加字符串结束标志0
}
