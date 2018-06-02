# include <iostream>
# include <iomanip>
using namespace std;
int temp[128]; 
int index = 0;
int addOne(int x){
	return x+1;
}
int square(int x){
	return x*x;
}
int f(int x){
	return x;
}
int* map(int (*f)(int), int array[], int length){
	for (int i = 0; i < length; ++i){
		temp[index++] = f(array[i]);
	}
	return temp;
}
int addition(int x, int y){
	return x+y;
}
int multiple(int x, int y){
	return x*y;
}
int squareAddition(int r, int x){
	return r+x*x;
}
int positive(int r, int x){
	return x > 0 ? r+1 : r;
}
int reduce(int (*f)(int, int), int array[], int length){
	if (length <= 1) return f(0, array[0]); 
  if (length == 2) return f(array[0], array[1]); 
  int r = f(0, array[0]); 
	for (int i = 1; i < length; ++i){
		r = f(r, array[i]);
	}
	return r;
}
void display(int array[], int length){
	for (int i = 0; i < length; ++i)
		cout<<setw(3)<<array[i]<<' ';
}
int main(){
	int *copy;
	int array[] = {1,2,3,4,5};
	int length = sizeof(array)/sizeof(int);
	display(array, length);cout<<endl;
	
	copy = map(addOne, array, length);
	display(array, length);
	cout<<"加1后：";
	display(copy, length);cout<<endl;
	delete []copy;
	
	int add = reduce(addition, array, length);
	display(array, length);
	cout<<"和："<<add<<endl;
	delete []copy;
	
	int mul = reduce(multiple, array, length);
	display(array, length);
	cout<<"积："<<mul<<endl;
	delete []copy;
	
	copy = map(square, array, length);
	int sqrAdd = reduce(addition, copy, length);
	display(array, length);
	cout<<"平方和："<<sqrAdd<<endl;
	delete []copy;
	
	int array2[] = {-1,1,0,-2,5};
	int length2 = sizeof(array2)/sizeof(int);
	int p = reduce(positive, array2, length2);
	display(array2, length2);
	cout<<"正数的个数："<<p<<endl;
	
	int a1[] = {1,2};
	int a2[] = {3,4,5};
	int a3[] = {6};
	index = 0;
	int *a;
	int l1 = sizeof(a1)/sizeof(int);
	int l2 = sizeof(a2)/sizeof(int);
	int l3 = sizeof(a3)/sizeof(int);
	a = map(f, a1, l1);
	a = map(f, a2, l2);
	a = map(f, a3, l3);
	display(a1, l1);cout<<endl;
	display(a2, l2);cout<<endl;
	display(a3, l3);cout<<endl;
	cout<<"展平数组后：\n";
	display(a, l1+l2+l3);
	

	return 0;
} 
