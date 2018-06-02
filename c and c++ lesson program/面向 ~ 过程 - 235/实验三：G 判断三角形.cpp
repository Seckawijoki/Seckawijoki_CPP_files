#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	while ( 1 )
	{
		cin>>a>>b>>c;//层层镶嵌才有包含关系。原来分开的只是并列关系，而互不相关。
		if ( ( a + b > c ) && ( b + c > a ) && ( a + c > b ) )
			if ( a == b || b == c || a == c  )
				if ( a == b && b == c && a == c )
						cout<<"构成等边三角形"<<endl;
				else
					cout<<"构成等腰三角形"<<endl;
			else
				cout<<"构成普通三角形"<<endl;
		else
			cout<<"不能构成三角形"<<endl;
	}
	return 0;
}