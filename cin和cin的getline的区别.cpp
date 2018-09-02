#include<iostream>
using namespace std;
int main(){
	while (true){
		char sz1[10];
		char sz2[10];
		cout<<"cin.getline(?,10):"; 
		cin.getline(sz1, 10);
		cout<<sz1<<endl;
		cout<<"cin>>";
		cin>>sz2;
		cout<<sz2<<endl;
	}
}
