/*
题目描述
题目描述接上一题。

再为上述“迷你”字符串类添加方法int substr（Mini_string& s），
若s中的串是“自身”串的一部分（子串），
返回s在“自身”串出现的首位置（下标），否则返回-1。

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
		cin >> s;
		Mini_string mt(s);
		cout << ms.substr(mt) << endl;
    }
	return 0;
}

输入
测试数据的组数 t
第1个自身串
第1个参数串
.......
第t个自身串
第t个参数串

输出
参考样例输出

样例输入
2
Abcd#bcd
bcd
Abcd#bcd
xy
样例输出
Constructor Transfer
Constructor Transfer
1
Distructor
Distructor
Constructor Transfer
Constructor Transfer
-1
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
    Mini_string( char *s ) 
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
    int substr( Mini_string &s ) 
    { 
        if ( strlen(space) < strlen(s.space) ) 
            return -1; 
        else
        { 
            int i,j,length = strlen(s.space); 
            char *p = new char [strlen(s.space)+1]; 
            for ( i = 0 ; i <= strlen(space) - length ; i ++ ) 
            { 
                for ( j = 0 ; j < length ; j ++ ) 
                    p[j] = space[i+j]; 
                p[j] = '\0'; 
            //  cout<<strlen(p)<<"====="<<p<<"====="<<s.space<<endl; 
                if ( strcmp(p,s.space) == 0 ) 
                { 
                    int k; 
                    for ( k = 0 ; k < length ; k ++ ) 
                        if ( p[k] != s.space[k] ) 
                            return -1; 
                    return i; 
                } 
            } 
            return -1; 
        } 
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
        cout << ms.substr(mt) << endl; 
    } 
    return 0; 
} 
