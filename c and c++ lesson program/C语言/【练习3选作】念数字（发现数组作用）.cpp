/*
����ϰ3ѡ����������
����һ�����������ÿ�����ֶ�Ӧ��ƴ����������Ϊ����ʱ�������"fu"�֡�ʮ�����ֶ�Ӧ��ƴ�����£� 
0: ling 1: yi 2: er 3: san 4: si 5: wu 6: liu 7: qi 8: ba 9: jiu

��ʾ��
1.ÿ�����ֶ�Ӧ��ƴ�����ö�ά�ַ������ţ�
char a[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

2.��һ��������ת��Ϊ�ַ����ķ�����
char str[255];
sprintf(str, "%d", -100); //��-100תΪ10���Ʊ�ʾ���ַ�����ֵ��str���顣

�����ʽ�� 
������һ���и���һ���������磺 1234 �� 
��ʾ������������������������� 
�����ʽ�� 
��һ����������������Ӧ��ƴ����ÿ�����ֵ�ƴ��֮���ÿո�ֿ�����ĩû�����Ŀո��� yi er san si��

����������
-600
���������
fu liu ling ling
*/
# include <iostream.h>
int main(void)
{
	int i,j,x;
	char ch;
	char a[11][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu","fu"};//�洢���á�//δ������������á�
	for ( i = 0 ; i < 11 ; i++ )
	{
		for ( j = 0 ; j < 5 ; j++ )
			cout<<a[i][j];
		cout<<endl;
	}
	while ( 1 )
	{
		cin>>ch;
		switch ( ch )
		{
			case ('-'):x = 11;break;
			case ('0'):x = 0;break;
			case ('1'):x = 1;break;
			case ('2'):x = 2;break;
			case ('3'):x = 3;break;
			case ('4'):x = 4;break;
			case ('5'):x = 5;break;
			case ('6'):x = 6;break;
			case ('7'):x = 7;break;
			case ('8'):x = 8;break;
			case ('9'):x = 9;break;
			default :cout<<'\n';
		}
		for ( j = 0 ; j < 5 ; j++ )
			cout<<a[x][j];
		cout<<' ';
	}
	return 0;
}