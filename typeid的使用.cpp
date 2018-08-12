#include <iostream>
using namespace std;
#include <typeinfo>
#include <string>

class Base{
	
};
class Derived: public Base{
	
};
class Base2{
public:
	virtual void foo() = 0;
	virtual ~Base2(){
		
	}
};
class Derived2: public Base2{
public:
	void foo(){
		
	}
	~Derived2(){
		
	}
};
int main(){
	char c = 'A';
	int i = 50;
	long l = 100000000L;
	float f = 1.0f;
	double db = 3.14;
	const char* cstr = "cstr";
	string str = "string";
	double *p_db = NULL;
	const double *pk_db = NULL;
	cout<<"c has type: "<<typeid(c).name()<<endl;
	cout<<"i has type: "<<typeid(i).name()<<endl;
	cout<<"l has type: "<<typeid(l).name()<<endl;
	cout<<"f has type: "<<typeid(f).name()<<endl;
	cout<<"d has type: "<<typeid(db).name()<<endl;
	cout<<"cstr has type: "<<typeid(cstr).name()<<endl;
	cout<<"str has type: "<<typeid(str).name()<<endl;
	cout<<"p_db has type: "<<typeid(p_db).name()<<endl;	
	cout<<"pk_db has type: "<<typeid(pk_db).name()<<endl;
	
	const type_info& r1 = typeid(cout<<i);
	cout<<"\ncout<<i has type: "<<r1.name()<<endl;
	const type_info& r2 = typeid(printf("%d", i));
	cout<<"print(\"%d\", i) has type: "<<r2.name()<<endl;  
	
	Derived d;
	Base& b = d;
	cout<<"reference to non-polymorphic base: "<<typeid(b).name()<<endl;
	
	Derived2 d2;
	Base2& b2 = d2;
	cout<<"reference to polymorphic base: "<<typeid(b2).name()<<endl;
	
	try {
		cout<<"p_db points to "<<typeid(*p_db).name()<<endl;
		Derived2* bad_ptr = NULL;
		cout<<typeid(*bad_ptr).name()<<endl;
	} catch (const bad_typeid& e){
		cout<<"caught "<<e.what()<<endl;
	} 
	
	return 0;
}
