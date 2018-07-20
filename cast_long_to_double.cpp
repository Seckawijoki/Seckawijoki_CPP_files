#include <iostream>
#include <climits>
int main()
{
  using namespace std;	
  long l1 = 2e9;
  long l2 = -2e9;
  long l3 = LONG_MIN;
  long l4 = LONG_MAX;
  unsigned long long l5 = 3e10;
  unsigned long long l6 = ULONG_MAX;
  cout<<l1<<endl<<l2<<endl<<l3<<endl<<l4<<endl<<l5<<endl<<l6<<endl<<endl;
  cout<<double(l1)<<endl<<double(l2)<<endl<<double(l3)<<endl<<double(l4)<<endl<<double(l5)<<endl<<double(l6)<<endl;
  return 0;
} 
