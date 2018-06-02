#include<iostream>
using namespace std;
class Base{
	public:
	virtual ~Base(){
		cout<<"Base destructs.\n";
	}
};
class Derived:public Base{
	public:
	~Derived(){
		cout<<"Derived destructs.\n";
	}
};
int main(){
	Base *pb = new Derived();
	delete pb;
	cout<<endl;
	Derived *pd = new Derived();
	delete pd;
}
