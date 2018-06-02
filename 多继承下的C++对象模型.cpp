#include<iostream>
#include<typeinfo>
#include<cstdio>
using namespace std;
class Base{
public:
    Base(int i) :baseI(i){};
    virtual ~Base(){}
    int getI(){ return baseI; }
    static void countI(){};
    virtual void print(void){ cout << "Base::print()"; }
private:
    int baseI;
    static int baseS;
};
class Base_2{
public:
    Base_2(int i) :base2I(i){};
    virtual ~Base_2(){}
    int getI(){ return base2I; }
    static void countI(){};
    virtual void print(void){ cout << "Base_2::print()"; }
private:
    int base2I;
    static int base2S;
};
 
class Drive_multyBase :public Base, public Base_2
{
public:
    Drive_multyBase(int d) :Base(1000), Base_2(2000) ,Drive_multyBaseI(d){};
    virtual void print(void){ cout << "Drive_multyBase::print" ; }
    virtual void Drive_print(){ cout << "Drive_multyBase::Drive_print" ; }
private:
    int Drive_multyBaseI;
};
int main(){
	typedef void(*Fun)(void);
	Drive_multyBase d(3000);
    //[0]
    cout << "[0]Base::vptr";
    cout << "\t地址：" << (int *)(&d) << endl;
 
        //vprt[0]析构函数无法通过地址调用，故手动输出
        cout << "  [0]" << "Derive::~Derive" << endl;
 
        //vprt[1]
        cout << "  [1]";
        Fun fun1 = (Fun)*((int *)*((int *)(&d))+1);
//        fun1();
        cout << "\t地址:\t" << *((int *)*((int *)(&d))+1) << endl;
 
 
        //vprt[2]
        cout << "  [2]";
        Fun fun2 = (Fun)*((int *)*((int *)(&d)) + 2);
        fun2();
        cout << "\t地址:\t" << *((int *)*((int *)(&d)) + 2) << endl;
 
 
    //[1]
    cout << "[1]Base::baseI=" << *(int*)((int *)(&d) + 1);
    cout << "\t地址：" << (int *)(&d) + 1;
    cout << endl;
 
 
    //[2]
    cout << "[2]Base_::vptr";
    cout << "\t地址：" << (int *)(&d)+2 << endl;
 
        //vprt[0]析构函数无法通过地址调用，故手动输出
        cout << "  [0]" << "Drive_multyBase::~Derive" << endl;
 
        //vprt[1]
        cout << "  [1]";
        Fun fun4 = (Fun)*((int *)*((int *)(&d))+1);
//        fun4();
        cout << "\t地址:\t" << *((int *)*((int *)(&d))+1) << endl;
 
    //[3]
    cout << "[3]Base_2::base2I=" << *(int*)((int *)(&d) + 3);
    cout << "\t地址：" << (int *)(&d) + 3;
    cout << endl;
 
    //[4]
    cout << "[4]Drive_multyBase::Drive_multyBaseI=" << *(int*)((int *)(&d) + 4);
    cout << "\t地址：" << (int *)(&d) + 4;
    cout << endl;
 
    getchar();
    return 0;
}
