/*
Description
����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����
Input
һ���ַ�
Output
ͳ��ֵ

Sample Input
aklsjflj123 sadf918u324 asdf91u32oasdf/.';123

Sample Output
23 16 2 4
*/
# include <iostream.h>
# include <iomanip.h>
# include <cstdio>
int main()
{
	char c;
	int num = 0 , letter = 0 , point = 0 ,space = 0 , cr = 0;
	for (;;)
	{
		do 
		{
			scanf("%c",&c);
			if ( c >= '0' && c <= '9' )
				num++;
			else if ( ( c >= 'a' && c <= 'z' ) || ( c >= 'A' && c <= 'Z' ) )
				letter++;
			else if ( c == ' ' )
				space++;
			else 
				point++;
			if ( c == '\n' )//�����������ѭ����
				break;
		}while ( 1 );
		cout<<"ͳ�ƽ����\n"
			<<"���֣�"<<num<<endl
			<<"��ĸ��"<<letter<<endl
			<<"�ո�"<<space<<endl
			<<"������"<<point<<endl<<endl;
	}
	return 0;
}

