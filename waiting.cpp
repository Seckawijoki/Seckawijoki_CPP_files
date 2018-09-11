#include<iostream>
using namespace std;
#include<ctime>
int main(){
	cout<<"Enter the delay time, in seconds: ";
	float seconds;
	cin>>seconds;
	clock_t delay = seconds * CLOCKS_PER_SEC;
	cout<<"starting\a\n";
	clock_t start = clock();
	while (clock() - start < delay);
	cout<<"done\a\n"; 
	return 0;
} 
