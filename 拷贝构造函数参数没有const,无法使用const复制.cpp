#include <iostream>
using namespace std;
class Coordinate{
private:
	int m_iX, m_iY;
public:
	Coordinate(int a, int b):m_iX(a),m_iY(b){
	}
	Coordinate(Coordinate& c){
		m_iX = c.m_iX;
		m_iY = c.m_iY;
		cout<<"&evaluated = "<<(int*)(this)<<" | &evaluatee = "<<&c<<endl;
	}
};
int main()
{
	const Coordinate c(0,0);
	Coordinate c0 = c;
	return 0;
} 
