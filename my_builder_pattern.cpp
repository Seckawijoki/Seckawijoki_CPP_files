#include <iostream>
#include <string>
#include <cstring>
#include "icomputer.h"
using namespace std;
class Thinkpad: public IComputer
{
	
};
class ThinkpadBuilder:public IComputer::IComputerBuilder
{
public:
	ThinkpadBuilder():super(new Thinkpad())
	{
	}
};
int main()
{
	
}
 
