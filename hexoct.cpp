#include<iostream>
 
int main()
{
    using namespace std;
    int chest = 42;
    int waist = 0x42;
    int inseam = 042;
 
    cout << "Monsieur cuts a striking figure!\n";
    cout << "chest = " << chest << "\n";
    cout << "waist = " << waist << "\n";
    cout << "inseam = " << inseam << "\n\n";
    
    cout <<dec<< "chest = " << chest << "\n";
    cout <<hex<< "waist = " << waist << "\n";
    cout <<oct<< "inseam = " << inseam << "\n";
    return 0;
}
