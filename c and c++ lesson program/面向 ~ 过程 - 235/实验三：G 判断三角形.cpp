#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	while ( 1 )
	{
		cin>>a>>b>>c;//�����Ƕ���а�����ϵ��ԭ���ֿ���ֻ�ǲ��й�ϵ����������ء�
		if ( ( a + b > c ) && ( b + c > a ) && ( a + c > b ) )
			if ( a == b || b == c || a == c  )
				if ( a == b && b == c && a == c )
						cout<<"���ɵȱ�������"<<endl;
				else
					cout<<"���ɵ���������"<<endl;
			else
				cout<<"������ͨ������"<<endl;
		else
			cout<<"���ܹ���������"<<endl;
	}
	return 0;
}