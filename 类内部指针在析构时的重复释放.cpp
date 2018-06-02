# include <iostream>
using namespace std;
class A{
	public:
		A(){
			i = 0;
		}
   int i;
};
class B{
public:
   A *p;
   B(){p=new A;}
   ~B(){
//   	 cout<<"B destructs.\n"; 
	   delete p;
	 }
};
void sayHello(B b){
//	cout<<"sayHello\n";
}
int main(){
	B b;
//	cout<<"Before sayHello(B)\n";
	cout<<b.p->i<<endl;
	sayHello(b);
	cout<<b.p->i<<endl;
//	cout<<"After sayHello(B)\n";
//	B b2, b3;
//	b2 = b3;
//	sayHello(b2);
} 
