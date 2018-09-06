#include<iostream>
#include<string>
using namespace std;
int main(){
	string firstname, lastname;
	cout<<"firstname:";
	getline(std::cin>>std::ws, firstname);
	cout<<"lastname:";
	getline(std::cin>>std::ws, lastname);
	string name = lastname + "," + firstname; 
	cout<<"fullname:"<<name<<endl;
	lastname.append(",").append(firstname);
	cout<<"lastname:"<<lastname<<endl;
	return 0;
} 
