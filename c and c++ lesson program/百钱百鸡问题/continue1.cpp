//���0-20֮���ż��--continue���

#include <iostream.h>
int main()
{
	cout<<"The even numbers are as follows:\n";
	for(int i=0; i<=20; i++)
	{
		if(i%2) continue;
		cout<<i<<' ';
	}
	cout<<"\n";

	return 0;
}