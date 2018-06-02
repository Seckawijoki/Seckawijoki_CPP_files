/*
闰年：

1.普通年能整除4且不能整除100的为闰年。（如2004年就是闰年,1900年不是闰年）

2.世纪年能整除400的是闰年。(如2000年是闰年，1900年不是闰年)
*/
# include <iostream.h>

int main()
{
	int year;
	while ( 1 )
	{
		cin>>year;
		if ( ( year %4 == 0 && year %100 != 0 ) || ( year %400 == 0 ) )
			cout<<year<<"是闰年\n";
		else
			cout<<year<<"不是闰年\n";
	}
	return 0;
}
