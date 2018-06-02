//1. 输入起始年号，输出50年内的闰年。
# include <stdio.h>
void leap( int y );
void main()
{
	int y, i = 1;
	scanf("%d",&y);
	for ( i = 1 ; i <= 51 ; i++,y++ )
		leap( y );
}

void leap( int y )
{
	!( y %400 ) || ( !( y %4 )  && y %100 ) ? printf("%d    ",y) : 1 ;
//	y %400 == 0 || (  y %4 == 0 && y %100 != 0) ? printf("%d    ",y) : 1 ;
}
