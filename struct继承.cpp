#include <stdio.h>
struct A{
  void foo(){printf("foo");}
  virtual void bar(){printf("bar");}
  A(){bar();}
};
struct B:A{
  void foo(){printf("b_foo");}
  void bar(){printf("b_bar");}
};
int main()
{
	A *a = new B();
	a->foo();
	a->bar();
	delete a; 
	return 0;
}

