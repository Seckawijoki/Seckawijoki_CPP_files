#include<iostream>
using namespace std;
class WCoord{
private:
	int x, y;
public:
	WCoord(int _x, int _y):x(_x), y(_y){
		
	} 
	WCoord(const WCoord& c){
		x = c.x;
		y = c.y;
	}
	void print(){
		cout<<x<<" | "<<y<<endl;
	}
};
class ActorLocoMotion{
public:
	WCoord m_Position;
	ActorLocoMotion():m_Position(1,2){
		
	}
	WCoord& getPosition(){
//		return WCoord(m_Position);
		return m_Position;
	}
	WCoord getPosition(int ignored){
//		return WCoord(m_Position);
		return m_Position;
	}
};
int main(){
	ActorLocoMotion* actorLocoMotion = new ActorLocoMotion();
	WCoord position = actorLocoMotion->getPosition();
	WCoord position2 = actorLocoMotion->getPosition(0);
	position.print();
	cout<<&actorLocoMotion->m_Position<<endl;
	cout<<&position<<endl;
	cout<<&position2<<endl;
	delete actorLocoMotion; 
	cout<<&position<<endl;
	cout<<&position2<<endl;
	return 0;
}
