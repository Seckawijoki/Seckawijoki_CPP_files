#include <iostream>
using namespace std;
class Coordinate{
private:
	int m_iX, m_iY;
	Coordinate(const Coordinate& c){
		m_iX = c.m_iX;
		m_iY = c.m_iY;
		cout<<"&evaluated = "<<(int*)(this)<<" | &evaluatee = "<<&c<<endl;
	}
public:
	Coordinate(int a, int b):m_iX(a),m_iY(b){
	}
};
void FunctionPassParam(Coordinate c){
	cout<<"FunctionPassParam()\n";
} 
Coordinate FunctionReturnInstance(){
	cout<<"FunctionReturnInstance()\n";
	Coordinate c(2,2);
	return c;
}
int main()
{
	Coordinate c(0,0);
	FunctionPassParam(c);
	Coordinate c2 = FunctionReturnInstance();
	Coordinate c3 = c2; 
	Coordinate c4(c3); 
	return 0;
} 
