# include <iostream.h>   
void main (  )
{   
    char  *string = "I love China!";
    cout<<string<<endl;//��������ַ���
    string += 7;
    while (*string)
    {      
        cout<<*string<<endl;//ָ�򵥸��ַ�
        string++;
    }
}
