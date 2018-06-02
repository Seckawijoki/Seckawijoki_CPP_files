/*
题目描述
题目描述接上一题。

再为上述“迷你”字符串类添加方法void scat（Mini_string s），将“自己”与s相连（s在后）
主函数如下：\\注意：主函数不可修改

int main()
{
    int t;
    char s[1024];
    cin >> t;
    while( t-- )
    {
		cin >> s;
		Mini_string ms(s);
		cin >> s;
		Mini_string mt(s);
		mt.scat(ms);
		mt.output();
		cout << endl;
		cout << mt.spacelen() << endl;
	}
	return 0;
}
输入
测试数据的组数 t
第一个“尾”串
第一个原串
........
第t个“尾”串
第t个原串

输出
参考输出示例

样例输入
1
evening
Good

样例输出
Constructor Transfer
Constructor Transfer
Constructor Copy
Distructor
Goodevening
12
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
    void scat( Mini_string s ) 
    { 
        int i; 
        char *p; 
        p = new char [size+1]; 
        strcpy(p,space); 
        size += strlen(s.space); 
        space = new char [size]; 
        strcpy(space,p); 
        for ( i = strlen(p) ; i < size ; i ++ ) 
            space[i] = s.space[i-strlen(p)]; 
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
        cin >> s; 
        Mini_string mt(s); 
        mt.scat(ms); 
        mt.output(); 
        cout << endl; 
        cout << mt.spacelen() << endl; 
    } 
    return 0; 
} 
