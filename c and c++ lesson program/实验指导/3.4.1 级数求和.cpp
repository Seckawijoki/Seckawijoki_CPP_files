/*============================*
	������ͨ�ʽ��ǰn��ͣ�
	              x^n
	(-1)^(n+1) * -----
	              n !

*============================*/

# include <iostream.h>
# include <iomanip.h>
# include <math.h>
int main()
{
	int i = 1 , x , n , mul = 1 , k = 1 ;
	double y = 1 , z = 0 ;
	cout<<"�������ͨ�ʽ��ͣ�\n";
	cout<<"              x^n\n";
	cout<<"(-1)^(n+1) * -----\n";
	cout<<"              n !\n";
	cout<<"\n������x��n��";
	cin>>x>>n;
	while ( i <= n )
	{
		for ( int j = 1 ; j <= i ; j++ )
			mul = mul * j ;
		//cout<<mul<<endl;//���Խ׳�ʱ��
		y = y + ( k * pow( x , i ) ) / double(mul) ;
		i++;
		k *= -1;
		mul = 1;
	}
	cout<<"\n�����\n"<<setiosflags(ios::showpoint)
		<<setiosflags(ios::fixed)<<setprecision(8)<<y<<endl;
	return 0;
}
/*
	��δ���
	1.����longΪlong double��
	2.�׳���׼��
	3.�׳�ֵû�з���1��
	4.�������Ϊ0ʱ�������߼�˳�����⡣
*/