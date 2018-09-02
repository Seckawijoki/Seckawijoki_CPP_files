#include<iostream>
using namespace std;
#include<string>
int main(){
	string firstname;
	string lastname;
	string grade;
	string age;
	cout<<"first name:";
	getline(std::cin>>std::ws, firstname);
	cout<<"last name:";
	getline(std::cin>>std::ws, lastname);
	cout<<"grade:";
	getline(std::cin>>std::ws, grade);
	cout<<"age:";
	getline(std::cin>>std::ws, age);
	cout<<"name:"<<lastname<<", "<<firstname<<endl;
	cout<<"grade:"<<(char)(grade[0]+1)<<endl;
	cout<<"age:"<<age<<endl;
	 
	return 0;
}
