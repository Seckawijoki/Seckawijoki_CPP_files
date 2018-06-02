#include <iostream.h>
#include <string.h>
void main ( )
{
  char str[22] = "I love China!", ch;
  char *p, *q;
  cout<<str<<endl;  
  p = str;                 //p指向字符串的首地址
  q = p + strlen(p) - 1;   //q指向字符串的末地址
  while ( p < q )
  {                        //交换p和q各自指向的字符
    ch = *p;      //将p所指向的字符保存在ch中
    *p++ = *q;    //先将q指向的字符赋给p指向的字符单元，p再增1
    *q-- = ch;    //先将ch的值赋给q指向的字符单元，q再减1
  }
  cout<<str<<endl;  
}
/*=====================================
		I love China!
		!anihC evol I
=====================================*/