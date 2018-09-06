#include<iostream>
using namespace std;
struct PizzaCompany{
public:
	string companyname;
	double diameter;
	double weight;
	friend ostream& operator << (ostream& o, PizzaCompany& pc){
		o<<"Company Name:"<<pc.companyname<<", Pizza diameter = "<<pc.diameter<<", Pizza weight = "<<pc.weight<<endl;
		return o;
	}
	friend istream& operator >> (istream& i, PizzaCompany& pc){
		cout<<"Pizza diameter:";
		i>>pc.diameter;
		cout<<"Pizza company name:";
		getline(std::cin>>std::ws, pc.companyname);
		cout<<"Pizza weight:";
		i>>pc.weight;
		return i;
	}
};
int main(){
	PizzaCompany pc;
	cin>>pc;
	cout<<pc;
	return 0;
}
