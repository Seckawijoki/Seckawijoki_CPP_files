/*==================================*
	  ��ͣ�1��+ 2��+ 3��+ ���� +12��
		���õ��ú�����

	  2014��11��18�� 16:56:43��
  		�����Ե�������
*==================================*/
# include <iostream.h>

int main()
{
	int i,sum = 0;
	int mul( int i );
	for ( i = 1 ; i <= 12 ; i++ )
		sum += mul( i );
	cout<<"��ͣ�1��+ 2��+ 3��+ ���� +12��="<<sum<<endl;
	return 1;
}
/*--------------�ƺ�������-------------------
int sum( int n )
{
	int mul( int n );
	if ( n == 1 )
		return 1;
	return sum( mul( n - 1 ) ) + mul( n );
}
*/
int mul( int i )
{
	if ( i <= 1 )
		return 1;
	return mul( i - 1 ) * i;
}