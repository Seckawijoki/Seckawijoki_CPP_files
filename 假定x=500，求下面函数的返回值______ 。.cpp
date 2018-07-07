#include <iostream>
using namespace std;


int fun(int x)
{
    int countx = 0;
    while (x)
    {
        countx++;
        x = x & (x - 1);
    }
    return countx;
}
int main()
{
	cout<<fun(500)<<endl;
	return 0;
}
