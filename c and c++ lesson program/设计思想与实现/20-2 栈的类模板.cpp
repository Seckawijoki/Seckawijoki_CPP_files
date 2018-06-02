# include <iostream.h>
const int SIZE = 100;
template < class T >
class Stack
{
private:
	T stack[SIZE];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	~Stack(){}
	void Push( T value )
	{
		top++;
		stack[top] = value;
	}
	T Pop()
	{
		return stack[top--];
	}
	friend ostream & operator << ( ostream & , Stack<T> & );
};
template < class T >
ostream & operator << ( ostream &stream , Stack<T> &s )
{
	int i;
	for ( i = 0 ; i < s.top + 1 ; i++ )
		stream<<s.stack[i]<<' ';
	return stream;
}
int main()
{
	int i;

	int a;
	Stack<int> s1;
	for ( i = 0 ; i < 5 ; i++ )
	{
		cin>>a;
		s1.Push(a);
	}
	cout<<"Before poping stack1 : "<<s1<<endl;
	s1.Pop();
	cout<<"After  poping stack1 : "<<s1<<endl;

	double b;
	Stack<double> s2;
	for ( i = 0 ; i < 5 ; i++ )
	{
		cin>>b;
		s2.Push(b);
	}
	cout<<"Before poping stack2 : "<<s2<<endl;
	s2.Pop();
	cout<<"After  poping stack2 : "<<s2<<endl;

	char c;
	Stack<char> s3;
	for ( i = 0 ; i < 5 ; i++ )
	{
		cin>>c;
		s3.Push(c);
	}
	cout<<"Before poping stack3 : "<<s3<<endl;
	s3.Pop();
	cout<<"After  poping stack3 : "<<s3<<endl;

	return 0;
}
/*
	2 45 1003 18889 514 
	1.2345 757.3 2656.1 131.3 25.3356336
	z 2 & @ 6
*/