# include <iostream.h>
# include <iomanip.h>
class RMB
{
protected:
	unsigned int yuan;
	unsigned int jf;
public:
	RMB( double v = 0.0 )
	{
		yuan = v;
		jf = ( v - yuan ) * 100.0 + 0.5;
	}
	operator double()
	{
		return yuan + jf / 100.0;
	}
	void display( ostream &out )
	{
		out<<"гд"<<setfill('0')<<setw(8)
			<<yuan<<'.'
			<<setfill('0')<<setw(2)<<jf
			<<setfill(' ');
	}
};
ostream &operator << ( ostream &oo , RMB &d )
{
	d.display(oo);
	return oo;
}
int main()
{
	RMB rmb(1.58);
	cout<<"Initially rmb = "<<rmb<<endl;
	rmb = 2.0 * rmb;
	cout<<"Then      rmb = "<<rmb<<endl;
	return 0;
}