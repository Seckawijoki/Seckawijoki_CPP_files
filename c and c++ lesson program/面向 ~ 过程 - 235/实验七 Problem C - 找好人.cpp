/*
Description
ĳѧУ����λͬѧ�е�һλ���˺��£�������������������֮��У��������λ��˭���ĺ��¡��ĸ��˵Ļش�ֱ��ǣ�
A˵��������
B˵����C
C˵����D
D˵��C��˵��
��֪����˵�����滰��һ����˵���Ǽٻ������ڱ����������µĵ�����˭��

Input
������

Output
X

(X��ʾA,,B,C,D�е�һ��)

Sample Input

Sample Output
*/
# include <iostream>
using namespace std;
int main()
{
	char x;
	int a,b,c,d,i;
	for ( i = 1 ; i <= 4 ; i++ )
	{
		switch (i)
		{
			case 1:x = 'A';break;
			case 2:x = 'B';break;
			case 3:x = 'C';break;
			case 4:x = 'D';break;	
		}
		a = ( x != 'A' );
		b = ( x == 'C' );
		c = ( x == 'D' );
		d = ( x != 'D' );
		if ( a + b + c + d == 3 )
			cout<<x<<endl;
	}
	return 0;
}
