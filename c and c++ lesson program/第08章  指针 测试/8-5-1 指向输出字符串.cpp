# include <iostream.h>   
void main (  )
{   
    char  *string = "I love China!";
    cout<<string<<endl;//输出整条字符串
    string += 7;
    while (*string)
    {      
        cout<<*string<<endl;//指向单个字符
        string++;
    }
}
