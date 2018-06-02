# include <iostream>
# include <stack>
using namespace std;
struct Coordinate
{
	int abscissa;
	int ordinate;
	int passable;
int main()
{
	int n, n2, i, j, transitable;
	stack <Coordinate> path;
	cin>>n;
	n2 = n * n;
	Coordinate *site = new Coordinate [n2];
	for ( i = 1 ; i <= n2 ; ++i )
	{
		cin>>transitable;
		site[i].SetAbscissaAndOrdinate(transitable,i/n+1,i%n);
	}
	
	return 0;
}
