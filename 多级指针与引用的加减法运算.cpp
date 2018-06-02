# include <stdio.h>
# include <typeinfo>
int main(){
	int a[2][2][3]= { {{1,2,3},{4,5,6}},{{7,8,9},{10,11,12}}};
  int *ptr=(int *)(&a+1);
  printf("%d %d\n", *(int*)(a+1), *(ptr-1));
  printf("%s\n", typeid(&a + 1).name());
  printf("%s\n", typeid((int*)(&a + 1)).name());
  printf("%s\n", typeid(a + 1).name());
  printf("%s\n", typeid((int*)(a + 1)).name());
}
