#include <iostream>
#include<iomanip>
using namespace std;

void main ( )
{   
  int i, j;
  for (i = 1; i < 10; i++)
       cout<<setw(4)<<i;
  cout<<"\n---------------------------------------\n";
  for (i = 1; i < 10; i++)
      for (j = 1; j < 10; j++)
           //printf((j==9) ? "%4d\n" : "%4d", i * j);
           if (j==9) cout<<setw(4)<<i*j<<"\n";
		   else cout<<setw(4)<<i*j;
}
