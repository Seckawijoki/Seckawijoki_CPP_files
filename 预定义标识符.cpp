#include<stdio.h>  
#include<windows.h>  
#include<stdlib.h>  
int main()  
{  
    printf("file->%s\nline->%d\ndata->%s\ntime->%s\n",__FILE__,__LINE__,__DATE__,__TIME__);  
    system("pause");  
    return 0;  
}  
