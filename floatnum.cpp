#include <iostream>
int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	float tub = 10.0 / 3.0;
	double mint = 10.0 / 3.0;
	const float million = 1.0e6;
	cout << "tub = "<< tub
	<<", a million tubs = "<<million * tub
	<<", \nand ten million tubs = "
	<<10 * million * tub<<endl;
	cout<<"mint = "<<mint <<" and a million mints = "<<million * mint<<endl;
	
	cout.setf(ios::fixed, ios::floatfield);
	float tub2 = 10.0 / 3.0;
	double mint2 = 10.0 / 3.0;
	const float million2 = 1.0e6;
	cout << "tub2 = "<< tub2
	<<", a million tubs2 = "<<million2 * tub2
	<<", \nand ten million tubs2 = "
	<<10 * million2 * tub2<<endl;
	cout<<"mint2 = "<<mint2 <<" and a million mints2 = "<<million2 * mint2<<endl;
	return 0;
}
