/*
	��ʽ��
	Pai/4 = 1 - 1/3 + 1/5 - 1/7 + ...

	һֱ�ӵ����һ��ľ���ֵС��10^(-8)��
*/
# include <iostream.h>
# include <math.h>
# include <iomanip.h>

int main()

{
	long double y = 1 , x = 1 , k = -1;
	while ( fabs( 1 / ( 2 * x + 1 ) ) > 1e-8 )
	{
		y = y + k / ( 2 * x + 1 );
		x++;	
		k *= -1;
	}
	cout<<"��Լ���� "
		<<setprecision(9)<<double( 4 * fabs( y ) )<<endl;

	return 0;
}
/*
	�����
	3.14159263
*/