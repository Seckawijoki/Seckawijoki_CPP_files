#include <iostream>
#include <exception>
using namespace std;
class MyException:public exception{
private:
	string m_strTitle;
public:
	virtual const char* what() const throw(){
		return "MyException";
	}
	MyException(){
		cout<<"MyException(): (int*)this = "<<(int*)this<<endl;
	}
	MyException(const string& title){
		m_strTitle = title;
		cout<<"MyException(const char*): (int*)this = "<<(int*)this<<endl;
	}
	~MyException() throw(){
		cout<<"~MyException() : (int*)this = "<<(int*)this<<endl;
	}
};
double ZeroDivided(double x, double y){
	return x/y;
}
int main()
{
	try {
//		throw 1;
//		throw "error";
//		MyException e;
		MyException e("Seckawijoki");
		throw e;
//		int* myarray = new int[100000000];
//		ZeroDivided(1,0);
	} catch (int i) {
		cout<<"catch int : "<<i<<endl;
	} catch (const char* cstr) {
		cout<<"catch char* : "<<cstr<<endl;
	} catch (double) {
		cout<<"catch double"<<endl;
	} catch (exception& e) {
		cout<<"Standard Exception: "<<e.what()<<endl;
	}
	return 0;
}
