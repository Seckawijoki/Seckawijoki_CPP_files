#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
	stringstream stream;
	string sz = "46735746537";
	long long ll;
	stream<<sz;
	if (stream >> ll){
		cout<<ll<<endl;
	} else {
		cout<<"Transform error:"<<sz<<" is not a digit\n";
	}
	sz = "161246j3h5jk3gh57g6467";
	stream<<sz;
	if (stream >> ll){
		cout<<ll<<endl;
	} else {
		cout<<"Transform error:"<<sz<<" is not a digit\n";
	}
	return 0;
} 
