#include <iostream>
using namespace std;
class Base
{
public:
	Base(){}
//	virtual ~Base(); // equals below
	virtual ~Base() = 0;
	virtual void Hiberarchy() const = 0;	
};
Base::~Base()
{
	cout<<"~Base()\n";
}
void Base::Hiberarchy() const 
{
	cout<<"Base::Hiberarchy()\n";
}
class Derived:public Base
{
public:	
	Derived(){}
	virtual void Hiberarchy() const 
	{
		Base::Hiberarchy();
		cout<<"Derived::Hiberarchy()\n";
	}
	virtual void foo(){}	
	~Derived()
	{
		cout<<"~Derived()\n";
	}
};
int main()
{
	Base *pBase = new Derived();
	pBase->Hiberarchy();
	pBase->Base::Hiberarchy();
	delete pBase;
	return 0;
} 
