/*
题目描述
题目内容接上一题。

再为上述“迷你”字符串类添加拷贝构造函数；输出Constructor Copy
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
		Mini_string mt(ms);
		mt.output();
		cout << endl;
		cout << mt.spacelen() << endl;
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
evening

样例输出
Constructor Transfer
Constructor Copy
Good
5
Distructor
Distructor
Constructor Transfer
Constructor Copy
evening
8
Distructor
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
    Mini_string( Mini_string &mt ) 
    { 
        size = mt.size; 
        space = new char [size]; 
        strcpy(space,mt.space); 
        cout<<"Constructor Copy\n"; 
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
        Mini_string mt(ms); 
        mt.output(); 
        cout << endl; 
        cout << mt.spacelen() << endl; 
    } 
    return 0; 
} 
