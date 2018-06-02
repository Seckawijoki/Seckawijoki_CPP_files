/*
题目描述
题目描述接上一题。
再为上述“迷你”字符串类添加
有参（转换）构造函数Mini_string(char *s)，s为字符串。
“申请”space指向的空间，恰好能够放置s；
输出Constructor Transfer并换行。

主函数如下：//注意：不可修改主函数
int main()
{
    int t;
    char s[1024];
    cin >> t;
	while( t-- )
    {
		cin >> s;
		Mini_string ms(s);
		ms.output();
		cout << endl;
		cout << ms.spacelen() << endl;
    }
	return 0;
}
输入
测试数据的组数 t
第一个串
........
第t个串

输出
参考输出示例

样例输入
2
Good
Evening
样例输出
Constructor Transfer
Good
5
Distructor
Constructor Transfer
Evening
8
Distructor
*/
# include <iostream> 
# include <cstring> 
using namespace std; 
class Mini_string 
{ 
private: 
    char *space; 
    int size; 
public: 
    Mini_string() 
    { 
        space = new char ('\0'); 
        size = 1; 
        cout<<"Constructor Default\n"; 
    } 
    Mini_string(char *s) 
    { 
        size = strlen(s)+1; 
        space = new char [size]; 
        strcpy(space,s); 
        cout<<"Constructor Transfer\n"; 
    } 
    ~Mini_string() 
    { 
        delete [] space; 
        cout<<"Distructor\n";  
    } 
    void output(){cout<<space;} 
    int spacelen(){return size;} 
}; 
int main() 
{ 
    int t; 
    char s[1024]; 
    cin >> t; 
    while( t-- ) 
    { 
        cin >> s; 
        Mini_string ms(s); 
        ms.output(); 
        cout << endl; 
        cout << ms.spacelen() << endl; 
    } 
    return 0; 
} 
