#include <iostream>
using namespace std;

int main(){
	const int ki = 21;
	const int* kpi = &ki;
	
	int modifier = ki;
	--modifier;
	cout<<"ki = "<<ki<<endl
		<<"&ki = "<<&ki<<endl
		<<"kpi = "<<kpi<<endl
		<<"modifier = "<<modifier<<endl
		<<"&modifier = "<<&modifier<<endl;
//	int* modifier2 = &ki;
//	int& modifier3 = ki;
	int* modifier4 = const_cast<int*>(&ki);
	cout<<"modifier4 = "<<modifier4<<endl;
	++*modifier4;
	cout<<"*modifier4 = "<<*modifier4<<endl;
	++modifier4; 
	cout<<"modifier4 = "<<modifier4<<endl;
	
	int* modifier5 = (int*)(kpi);
	cout<<"modifier5 = "<<modifier5<<endl;
	++*modifier5;
	cout<<"*modifier5 = "<<*modifier5<<endl;
	++modifier5; 
	cout<<"modifier5 = "<<modifier5<<endl;
	
	cout<<"ki = "<<ki<<endl;
	return 0;
} 
