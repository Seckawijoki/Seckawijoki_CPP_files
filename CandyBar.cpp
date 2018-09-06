#include<iostream>
using namespace std;
struct CandyBar{
public:
	CandyBar(){
		
	}
	CandyBar(string l, double w, int c){
		label = l;
		weight = w;
		calory = c;
	}
	string label;
	double weight;
	int calory;
	friend ostream& operator << (ostream &o, CandyBar &cb){
		o<<"label:"<<cb.label<<", weight = "<<cb.weight<<", calory = "<<cb.calory<<endl;;
		return o;
	}
	friend istream& operator >> (istream &i, CandyBar &cb){
		cout<<"label:";
		getline(std::cin>>std::ws, cb.label);
		cout<<"weight:";
		i>>cb.weight;
		cout<<"calory:";
		i>>cb.calory;
		return i;
	}
};
int main(){
	CandyBar snack("Mocha Munch", 2.3, 350);
	cout<<snack<<endl;
	
	CandyBar snacks[3] = {CandyBar("Mocha", 2.2, 330), CandyBar("Munch", 3.3, 550), CandyBar("Mocha Munch", 2.3, 350)};
	cout<<snacks[0]<<endl<<snacks[1]<<endl<<snacks[2]<<endl;
	
	CandyBar *p_Snacks = new CandyBar[2];
	cin>>p_Snacks[0]>>p_Snacks[1];
	cout<<p_Snacks[0]<<p_Snacks[1];
	return 0;
}
