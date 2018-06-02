# include <iostream.h>

int main()

{
	int x,y,z;
	x = 1;
	y = 1;
	z = 1;
	x = x || y && z;
	cout<<x<<","<<( x && !y || z )<<endl;

	return 0;
}
/*	
	在Vc6.0的运行结果是：
	1，1
*/