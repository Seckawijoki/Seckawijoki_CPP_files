#include<iostream>
using namespace std;
class Base{
public:
    Base(int i) :baseI(i){};
    virtual void print(void){ cout << "�������麯��Base::print()\n"; }
    virtual void setI(){cout<<"�������麯��Base::setI()\n";}
    virtual ~Base(){cout<<"����\n";}
private:
    int baseI;
};
int main(){
	  typedef void(*Fun)(void);
	  Base b(10);
    Fun vfunc = (Fun)*( (int *)*(int*)(&b));
    cout << "��һ���麯���ĵ�ַ�ǣ�" << (int *)*(int*)(&b) << endl;
    cout << "ͨ����ַ�����õ�һ���麯����\n";
    vfunc();
    Fun vfunc2 = (Fun)*( (int *)(*(int*)(&b)+1));
    cout << "�ڶ����麯���ĵ�ַ�ǣ�" << (int *)(*(int*)(&b)+1) << endl;
    cout << "ͨ����ַ�����õڶ����麯����\n";
    vfunc2(); 
}
