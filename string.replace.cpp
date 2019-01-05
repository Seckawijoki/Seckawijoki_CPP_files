#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	string str = "{\"userId\":\"2153341278248881\",\"nickName\":\"Elliott Deng\"}";
	string substr = "12345";
	str=str.replace(0,5,substr,substr.find("1"),4); //用substr的指定字符串替换str指定字符串
	cout << str << endl;
	return 0; 
}
