# include <iostream.h>
# include <iomanip.h>

const long double e = 2.718281828;

int main()

{
	cout<<setprecision(10)<<e<<endl;

	cout<<setiosflags(ios::scientific)<<e<<endl;
	cout<<setiosflags(ios::scientific)<<setprecision(8)<<e<<endl;

	cout<<setiosflags(ios::fixed)<<setprecision(8)<<e<<endl;
	//����setiosflags(ios::fixed)��Ӱ��,���ڿ�ѧ�������󷽿�ʹ��ѧ�������������



	return 0;
}