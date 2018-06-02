/*
题目描述
题目描述接上一题。

再为上述“迷你”字符串类添加方法int appearin（char c），返回c在字符串中出现的次数。
主函数如下：\\注意：主函数不可修改
int main()
{
    int t;
    char s[1024],c;
    cin >> t;
    while( t-- )
    {
		cin >> s;
		Mini_string ms(s);
		cin >> c;
		cout << ms.appearin(c) << endl;
    }
	return 0;
}

输入
测试数据的组数 t
第一个串
第一个字符
........
第t个串
第t个字符

输出
参考输出示例

样例输入
1
evening
e

样例输出
Constructor Transfer
2
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
    int appearin( char letter ) 
    { 
        int i,length = strlen(space),time = 0; 
        for ( i = 0 ; i < length ; i ++ ) 
            if ( space[i] == letter ) 
                time++; 
        return time; 
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
    char s[1024],c; 
    cin >> t; 
    while( t-- ) 
    { 
        cin >> s; 
        Mini_string ms(s); 
        cin >> c; 
        cout << ms.appearin(c) << endl; 
    } 
    return 0; 
} 
