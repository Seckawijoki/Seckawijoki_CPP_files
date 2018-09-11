#include<iostream>
using namespace std;
int main(){
	char c;
	int count = 0;
	cin.get(c);
	while (cin.fail() == false){
		cout<<c;
		++count;
		cin.get(c);
	}
	cout<<endl<<count<<" characters read\n";
	return 0;
}
