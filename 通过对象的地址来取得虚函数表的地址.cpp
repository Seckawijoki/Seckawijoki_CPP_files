#include<iostream>
using namespace std;
class Base{
public:
    Base(int i) :baseI(i){};
    virtual void print(void){ cout << "调用了虚函数Base::print()\n"; }
    virtual void setI(){cout<<"调用了虚函数Base::setI()\n";}
    virtual ~Base(){cout<<"析构\n";}
private:
    int baseI;
};
int main(){
	  typedef void(*Fun)(void);
	  Base b(10);
    Fun vfunc = (Fun)*( (int *)*(int*)(&b));
    cout << "第一个虚函数的地址是：" << (int *)*(int*)(&b) << endl;
    cout << "通过地址，调用第一个虚函数：\n";
    vfunc();
    Fun vfunc2 = (Fun)*( (int *)(*(int*)(&b)+1));
    cout << "第二个虚函数的地址是：" << (int *)(*(int*)(&b)+1) << endl;
    cout << "通过地址，调用第二个虚函数：\n";
    vfunc2(); 
}
