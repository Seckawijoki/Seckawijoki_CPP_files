#include<iostream>
using namespace std;
class ClassA
{
public:
    virtual ~ ClassA(){};
    virtual void FunctionA(){};
};
class ClassB
{
public:
   virtual void FunctionB(){};
};
class ClassC : public ClassA,public ClassB
//class ClassC : public ClassB,public ClassA
{
    public:
};
int main(){

ClassC aObject;
ClassA* pA=&aObject;
ClassB* pB=&aObject;
ClassC* pC=&aObject;
cout<<&aObject<<endl<<pA<<endl<<pB<<endl<<pC<<endl;
}
