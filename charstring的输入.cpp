#include<iostream>
using namespace std;
int main(){
	char firstname[256];
	char lastname[256];
	char grade[256];
	char age[256];
	cout<<"first name:";
	cin.getline(firstname,256);
	cout<<"last name:";
	cin.getline(lastname,256);
	cout<<"grade:";
	cin.getline(grade,256);
	cout<<"age:";
	cin.getline(age,256);
	cout<<"name:"<<lastname<<", "<<firstname<<endl;
	cout<<"grade:"<<(char)(grade[0]+1)<<endl;
	cout<<"age:"<<age<<endl;
	 
	return 0;
}
