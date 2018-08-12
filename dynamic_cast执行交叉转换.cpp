#include<iostream>
using namespace std;
#define SAFE_DELETE(p) if ((p) != NULL){delete (p); (p) = NULL;}
class Base{
public:
	Base(){
	}
	virtual void foo() = 0;
	virtual void foo2() = 0;
	virtual ~Base() = 0;
}; 
Base::~Base(){
	
}
class Derived: public Base{
public:
	int m_iX, m_iY; 
	Derived(){
	}
	void func(){
		cout<<"Derive::func()\n";
	} 
	void foo(){
		cout<<"Derive::foo()\n";
	}
	virtual void foo2(){
		cout<<"Derive::foo2()\n";
	}
	~Derived(){
	}
};
class Derived2: public Base{
public:
	double m_dbAngle, m_dbDistance;
	Derived2(){
	} 
	void func2(){
		cout<<"Derive2::func2()\n";
	} 
	void foo(){
		cout<<"Derive2::foo()\n";
	}
	virtual void foo2(){
		cout<<"Derive2::foo2()\n";
	}
	~Derived2(){
	}
}; 
void func(Base *pb){
	Derived *pd1 = static_cast<Derived*>(pb);
	Derived *pd2 = dynamic_cast<Derived*>(pb);
	cout<<"origin : &pb = "<<pb<<endl;
	cout<<"static_cast : &pd1 = "<<pd1<<endl;
	cout<<"dynamic_cast : &pd2 = "<<pd2<<endl;
	pd1->foo();
	pd1->foo2();
	pd1->func();
	cout<<"pd1->m_iX = "<<pd1->m_iX<<endl;
	cout<<"pd1->m_iY = "<<pd1->m_iY<<endl;
	if (pd2){
		pd2->foo();
		pd2->foo2();
		pd2->func(); 
		cout<<"pd2->m_iX = "<<pd2->m_iX<<endl;
		cout<<"pd2->m_iY = "<<pd2->m_iY<<endl;
	}
	cout<<endl;
}
int main(){;
	try {	
		Base* pb = new Derived();
		Derived* pd = new Derived();
		Derived2* pd2 = new Derived2();
		pd->m_iX = 2;
		pd->m_iY = 3;
		pd2->m_dbAngle = 90;
		pd2->m_dbDistance = 10;
		func(pb);
		func(pd);
		func(pd2);
		
//		Derived* pd3 = static_cast<Derived*>(pd2);//compile error 
		Derived* pd4 = dynamic_cast<Derived*>(pd2);
//		cout<<"static_cast : &pd3 = "<<pd3<<endl;
		cout<<"dynamic_cast : &pd4 = "<<pd4<<endl;
	} catch (exception& e) {
		
	}
	return 0;
}
