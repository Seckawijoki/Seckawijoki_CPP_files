/*
��Ŀ����
��һ���ַ����а����Ŀո�ȫ��ɾ����

����
��һ������T��ʾ��T������ʵ��
�ڶ�����ÿ������һ���ַ������ٰ���һ���ǿո��ַ���������T��

���
���ɾ���ո����ַ���

��������
4
Shen Zhen
  China  Go
          A
AB    CD  EF

�������
ShenZhen
ChinaGo
A
ABCDEF
*/
# include <stdio.h>
# include <string.h>
int space_delete( char str[] )
{
	int i,j = 0 ,l = strlen(str);
	char ch[55];
	for ( i = 0 ; i <= l ; i ++ )
		if ( str[i] != ' ' )
			ch[j++] = str[i];
	ch[j] = '\0';
	printf("%s\n",ch);
	return 1;
}
int main()
{
	int t;
	char str[55];
	scanf("%d",&t);	
	getchar();		//�ڴˡ������¡�
	while ( t-- )
	{
		gets(str);
		space_delete(str);
	}
	return 0;
}