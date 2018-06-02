# include <iostream.h>

int main()

{
	int x,y;
	cout<<"请输入一个数进行分段函数的计算：";
	cin>>x;
	if ( x > 2 && x <= 10 )
		y = x * ( x + 2 );
	else if ( x > -1 && x <= 2 )
		y = 2 * x;
	else
		y = x - 1;
	cout<<y<<endl;

	return 0;
}