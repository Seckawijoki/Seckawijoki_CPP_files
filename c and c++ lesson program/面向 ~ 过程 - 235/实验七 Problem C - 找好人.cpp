/*
Description
某学校有四位同学中的一位做了好事，不留名，表扬信来了之后，校长问这四位是谁做的好事。四个人的回答分别是：
A说：不是我
B说：是C
C说：是D
D说：C胡说。
已知三人说的是真话，一个人说的是假话，现在编程求出做好事的到底是谁？

Input
无输入

Output
X

(X表示A,,B,C,D中的一人)

Sample Input

Sample Output
*/
# include <iostream>
using namespace std;
int main()
{
	char x;
	int a,b,c,d,i;
	for ( i = 1 ; i <= 4 ; i++ )
	{
		switch (i)
		{
			case 1:x = 'A';break;
			case 2:x = 'B';break;
			case 3:x = 'C';break;
			case 4:x = 'D';break;	
		}
		a = ( x != 'A' );
		b = ( x == 'C' );
		c = ( x == 'D' );
		d = ( x != 'D' );
		if ( a + b + c + d == 3 )
			cout<<x<<endl;
	}
	return 0;
}
