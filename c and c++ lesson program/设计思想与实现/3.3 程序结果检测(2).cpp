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
	��Vc6.0�����н���ǣ�
	1��1
*/