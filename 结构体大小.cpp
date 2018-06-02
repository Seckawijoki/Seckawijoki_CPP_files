#include<stdio.h>
struct s1 {
    char ch, *ptr;
    union {
        short a, b;
        unsigned int c:2, d:1;
    }; 
    struct s1 *next;
};
int main(){
	
	printf("%d\n", sizeof(s1));
	return 0;
} 
