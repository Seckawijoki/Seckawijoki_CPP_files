# include <iostream.h>
# include <cstdio>
# include <iomanip.h>
# include <math.h>
int main()
{
	float i,q,sum;//��С�������ɲ���Ҫ̫�ߵľ�ȷ�ȡ�
	int n;
	while ( 1 )
	{
		scanf("%d %f",&n,&q);
		sum = 0;
		for ( i = 0 ; i <= n ; i++ )//n = ���� - 1
			sum += pow( q , i );//ֱ����ָ��������

		cout<<"����Ϊ"<<q<<",����Ϊ"<<n<<"�ĵȱ����е�ǰ"<<n<<"���Ϊ��"
			<<setiosflags(ios::fixed)<<setprecision(3)<<sum<<endl;
	}
	return 0;
}
