#include <stdio.h>
#include <unistd.h>  
#define _XOPEN_SOURCE 600
int main(){

    int i0;
    int pid;
    for (i0 = 0; i0 < 2; i0++) { 
        printf("before: pid = %d\n", getpid());
				pid = fork(); 
        printf("after: pid = %d\n", getpid());
        printf("-"); 
    } 
}
