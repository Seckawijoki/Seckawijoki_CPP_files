/*
题目描述
定义一个栈类Stack，实现栈与栈之间的相互赋值。
成员top表示栈顶指针，max表示栈的最大长度，
inflate函数表示栈中存放的数据超过栈的最大长度时，
扩大栈的长度，保证能继续插入数据。
Stack类的基本形式如下：

要求如下：
1.实现Stack类；
2.push()函数能一直插入数据，当超过栈的最大长度时，调用inflate函数扩大栈的最大长度。
3.初始化2个Stack对象，对第二个对象执行一次pop操作后，交换这2个对象，并输出栈中的内容。

输入
第一行输入2个栈的大小。
第二行输入第一个栈的元素。
第三行输入第二个栈的元素。

输出
输出第二个对象pop操作，2个对象交换之后，每个对象的元素。

样例输入
3 4
1 2 3
4 5 6 7
样例输出
456
123
提示
34
12
*/
# include <iostream>
using namespace std;
class Stack
{
public:
	int *space,top,max;	
	void inflate( int length )
	{
		if ( max < length )
		{
			max = length;
			space = new int [max];
		}
	}
	Stack( int size = 10 )
	{
		max = size;
		space = new int [max];
		top = 0;
	}
	~Stack()
	{
		if ( space != NULL )
			delete [] space;
	}
	int Pop()
	{
		if ( top < max )
		{
			top--;
			return space[top+1];
		}
		else
			return 0;
	}
	void Push( int value )
	{
		top++;
		space[top-1] = value;
	}
	Stack & operator = ( Stack & rightValue )
	{
		int i;
		top = rightValue.top;
		max = rightValue.max;
		space = new int [max];
		for ( i = 0 ; i < max ; i++ )
			space[i] = rightValue.space[i];
		return *this;
	}
	void Display()
	{
		int i;
		for ( i = 0 ; i < top ; i++ )
			cout<<space[i];
		cout<<endl;
	}
};
int main()
{
	int m,n,i;
	int *sp1,*sp2;
	cin>>m>>n;
	Stack st1,st2,st3;
	sp1 = new int [m];
	sp2 = new int [n];
	for ( i = 0 ; i < m ; i++ )
	{
		cin>>sp1[i];
		st1.Push(sp1[i]);
	}
	for ( i = 0 ; i < n ; i++ )
	{
		cin>>sp2[i];
		st2.Push(sp2[i]);
	}
	st2.Pop();
	st3 = st1;
	st1 = st2;
	st2 = st3;
	st1.Display();
	st2.Display();
	delete [] sp1;
	delete [] sp2;
	return 0;
}