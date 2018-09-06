#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char firstname[256], lastname[256];
	cout<<"firstname:";
	cin.getline(firstname,256);
	cout<<"lastname:";
	cin.getline(lastname,256);
	char name[512];
	strcpy(name, lastname);
	strcat(name, ",");
	strcat(name, firstname);
	cout<<"fullname:"<<name<<endl;
	strcat(lastname, ",");
	strcat(lastname, firstname);
	cout<<"lastname:"<<lastname<<endl; 
	return 0;
}
