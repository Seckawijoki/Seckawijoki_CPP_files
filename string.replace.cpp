#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string str = "{\"userId\":\"2153341278248881\",\"nickName\":\"Elliott Deng\"}";
	string substr = "12345";
	str=str.replace(0,5,substr,substr.find("1"),4); //��substr��ָ���ַ����滻strָ���ַ���
	cout << str << endl;
	return 0; 
}
