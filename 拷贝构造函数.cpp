#include <iostream>
using namespace std;
class Coordinate{
private:
	int m_iX, m_iY;
//	Coordinate(const Coordinate& c){}
public:
	Coordinate(int a, int b):m_iX(a),m_iY(b){
		
	}
	Coordinate(Coordinate& c){
		m_iX = c.m_iX;
		m_iY = c.m_iY;
		cout<<"&evaluated = "<<(int*)(this)<<" | &evaluatee = "<<&c<<endl;
	}
	Coordinate(const Coordinate& c){
		m_iX = c.m_iX;
		m_iY = c.m_iY;
		cout<<"&evaluated = "<<(int*)(this)<<" | &evaluatee = "<<&c<<endl;
	}	
};
void FunctionPassParam(Coordinate c){
	cout<<"FunctionPassParam(): &c = "<<&c<<"\n";
} 
Coordinate FunctionReturnInstance(){
	Coordinate c(2,2);
	cout<<"FunctionReturnInstance(): &c = "<<&c<<"\n";
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
