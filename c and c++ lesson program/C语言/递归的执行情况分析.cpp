#include <stdio.h>
void print (int w);
void main ( )
{  print ( 3 );  }
void print (int w)   //�ݹ麯��
{      
    int  i;
    if ( w != 0)     //�ݹ��������
    {     
      print (w-1);//�ݹ���������3��2��1����һ�������أ�1��2��3��
      for (i = 1; i <= w; ++i)
        printf ("%d ", w);
      printf ("\n");
    }
}
/*
	�����
	1
	2 2
	3 3 3
*/
