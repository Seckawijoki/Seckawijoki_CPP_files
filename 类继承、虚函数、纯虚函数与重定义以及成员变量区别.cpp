# include <iostream>
# include <cstring>
# include <cstdio>
# include <typeinfo>
using namespace std;
/*
	Name: 
	Copyright: 
	Author: 
	Date: 17/05/18 11:35
	Description: 
*/
class Readable{
	public:
		int page;
		virtual void read() = 0;
		virtual void showPage() = 0;
		void getMaterial(){
			cout<<"It's made of wood.\n";
		}
}; 
class Magazine:public Readable{
	public:
		Magazine(){
			page = 50;
		}
		void showPage(){
			cout<<"The Magazine has "<<page<<" pages.\n";
		}
		void read(){
			cout<<"reading a magazine.\n";
		}
};
class Newspaper:public Readable{
	public:
		Newspaper(){
			page = 4;
		}
		void showPage(){
			cout<<"The newspaper only has "<<page<<" pages.\n";
		}
		void read(){
			cout<<"reading a newspaper.\n";
		}
};
class Asset{
	public:
		double amount;
		Asset(){
			amount = 123456789;
		} 
};
class Person{
	public:
		int age;
		Person(){
		}
		virtual void read(Readable *r) = 0;
		virtual void showAge(){
			cout<<"age = "<<age<<endl;
		}
		virtual void showName() = 0;
};
class Parent:public Person{
	public:
		Asset *pa;
		string name;
		Parent(){
			age = 50;
			name = "parent";
			pa = new Asset();
		}
		virtual ~Parent(){
			cout<<"Parent destructs.\n";
			if (pa != NULL)delete pa; 
		}
		void read(Readable *r){
			cout<<"Parent ";r->read();
		}
		virtual void showAge(){
			cout<<"Parent age = "<<age<<endl;
		}
		void showName(){
			cout<<"Parent name = "<<name<<endl;
		}
		virtual void isParent(){
			cout<<"I'm a parent.\n";
		}
		void showFamily(){
			cout<<"In the "<<name<<"'s family.\n";
		}
};
class Child: public Parent{
	public:
		string name;
		Child():Parent(){
			age = 20;
			name = "child";
		}
		~Child(){
			cout<<"Child destructs.\n";
			if (pa != NULL)delete pa; 
		}
		void read(Readable *r){
			cout<<"Child ";r->read();
		}
		void showAge(){
			cout<<"Child age = "<<age<<endl;
		}
		void showName(){
			cout<<"Child name = "<<name<<endl;
		}
		void isParent(){
			cout<<"I'm not a parent.\n";
		}
		void showFamily(){
			cout<<"When "<<name<<" get married, he/she will have a new family.\n";
		}
};
void showAsset(Parent p){
	cout<<p.pa->amount<<endl;
}
int main(){
	Person *p0;; 
	Person *p1 = new Parent();
	Person *p2 = new Child();
	Parent *p3 = new Child();
	Child *p4 = new Child();
	cout<<"p1->age = "<<p1->age<<endl;
	cout<<"p2->age = "<<p2->age<<endl; 
	cout<<"p3->age = "<<p3->age<<endl; 
	p1->showAge();
	p2->showAge();
	p3->showAge();
	p4->showAge();
	p1->showName();
	p2->showName();
	p3->showName();
	p4->showName();
	cout<<"p3->name = "<<p3->name<<endl;
	cout<<"p4->name = "<<p4->name<<endl;
	p3->isParent();
	p4->isParent();
	p3->showFamily();
	p4->showFamily();
	
	delete p3;
	delete p4;
	
	
	cout<<endl;	
	Person *p = new Child();
	Readable *r = new Magazine();
	r->read();
	delete r;
	r = new Newspaper();
	r->read();
	p->read(r);
	p->read(new Magazine());
	p->read(new Newspaper());
	delete p;
	delete r;
//	cout<<*p3<<endl;
}

