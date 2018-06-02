# include <iostream.h>
# include <iomanip.h>

const long double e = 2.718281828;

int main()

{
	cout<<setprecision(10)<<e<<endl;

	cout<<setiosflags(ios::scientific)<<e<<endl;
	cout<<setiosflags(ios::scientific)<<setprecision(8)<<e<<endl;

	cout<<setiosflags(ios::fixed)<<setprecision(8)<<e<<endl;
	//由于setiosflags(ios::fixed)的影响,置于科学计数法后方可使科学计数法正常表达



	return 0;
}