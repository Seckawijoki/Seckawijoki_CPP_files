#include<iostream>
using namespace std;
template<class T>
class TemplateClass{
public:
	template<class U>
	TemplateClass(const TemplateClass<U>& x){
		cout<<"Own contructor\n";
	}
	TemplateClass(){
		cout<<this<<endl;
	}
};
int main(){
	TemplateClass<double> xd;
	TemplateClass<double> xd2(xd);
	TemplateClass<int> xi(xd);
	return 0;
}
