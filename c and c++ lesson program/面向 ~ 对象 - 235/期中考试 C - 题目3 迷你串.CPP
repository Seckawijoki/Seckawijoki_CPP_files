/*
题目描述
class Mini_string   
{
	char *space;
	int size;
	public:
    //……
};

以上是“迷你”字符串类的数据成员部分，其中space指向存放字符串的空间，空间由new分配；size记录空间个数。请为它实现以下方法：

1、缺省构造函数，建立一个大小为1的串存储空间，并放’\0’；size为1；输出Constructor Default并换行；
2、void output()，输出space中存放的字符串；
3、int spacelen()，返回（函数值）size；
4、析构函数，释放space指向的空间；输出Distructor并换行。

主函数如下：//注意：不可修改主函数
int main()
{
	int t;
	cin>>t;
	Mini_string ms; 
	ms.output();
	cout << endl;
	cout << ms.spacelen() << endl;
	return 0;
}

输入
第一行输入t
这个参数t只是做输入就可以了，后面无需对参数t做任何处理或任何操作

输出
输出看样板示例

样例输入
1

样例输出
Constructor Default

1
Distructor
*/
# include <iostream> 
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
    cin>>t; 
    Mini_string ms;  
    ms.output(); 
    cout << endl; 
    cout << ms.spacelen() << endl; 
    return 0; 
} 
