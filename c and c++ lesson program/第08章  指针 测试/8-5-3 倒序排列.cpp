#include <iostream.h>
#include <string.h>
void main ( )
{
  char str[22] = "I love China!", ch;
  char *p, *q;
  cout<<str<<endl;  
  p = str;                 //pָ���ַ������׵�ַ
  q = p + strlen(p) - 1;   //qָ���ַ�����ĩ��ַ
  while ( p < q )
  {                        //����p��q����ָ����ַ�
    ch = *p;      //��p��ָ����ַ�������ch��
    *p++ = *q;    //�Ƚ�qָ����ַ�����pָ����ַ���Ԫ��p����1
    *q-- = ch;    //�Ƚ�ch��ֵ����qָ����ַ���Ԫ��q�ټ�1
  }
  cout<<str<<endl;  
}
/*=====================================
		I love China!
		!anihC evol I
=====================================*/