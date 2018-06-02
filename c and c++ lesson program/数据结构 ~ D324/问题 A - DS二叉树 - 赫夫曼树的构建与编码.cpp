# include <iostream>
# include <string>
# include <cstring>
//# include <cstdio>
using namespace std;
const int MaxWeight = 9999;
class HuffmanNode
{
public:
	int weight;
	int parent;
	int leftchild;
	int rightchild;
};
class HuffmanTree
{
private:
	void CreateHuffmanTree()
	{
		int i, s1, s2;
		for ( i = leaves + 1 ; i <= nodes ; ++i )
		{
			SelectTwoMinimums(i-1,&s1,&s2);
			huffmannode[s1].parent = i;
			huffmannode[s2].parent = i;
			if ( huffmannode[s1].weight < huffmannode[s2].weight )
			{
				huffmannode[i].leftchild = s1;
				huffmannode[i].rightchild = s2;
			}
			else
			{
				huffmannode[i].leftchild = s2;
				huffmannode[i].rightchild = s1;
			}
			huffmannode[i].weight = huffmannode[s1].weight + huffmannode[s2].weight;
		}
//		cout<<"leaves = "<<leaves<<" , nodes = "<<nodes<<endl;
//		cout<<"huffmannode    weight parent leftchild rightchild\n";
//		for ( i = 1 ; i <= nodes ; ++i )
//		printf("huffmannode[%d]:%6d %6d %9d %10d\n",i,huffmannode[i].weight,huffmannode[i].parent,huffmannode[i].leftchild,huffmannode[i].rightchild);
	
	}
	void SelectTwoMinimums( int position, int *s1, int *s2 )
	{
		int w1, w2, i;
		w1 = w2 = MaxWeight;
		*s1 = *s2 = 0;
		for ( i = 1 ; i <= position ; ++i )
			if ( huffmannode[i].parent == 0 && w1 >= huffmannode[i].weight )
			{
				w1 = huffmannode[i].weight;
				*s1 = i;
			}
		for ( i = 1 ; i <= position ; ++i )
			if ( huffmannode[i].parent == 0 && w2 >= huffmannode[i].weight )
			if ( i != *s1 )
			{
				w2 = huffmannode[i].weight;
				*s2 = i;
			}
//		cout<<"minimum1 = "<<*s1<<" , minimum2 = "<<*s2<<endl;
	}
public:
	int nodes;
	int leaves;
	HuffmanNode *huffmannode;
	string *huffmancode;
	void CreateHuffmanTree( int hasuu, int *wt )
	{
		int i;
		leaves = hasuu;
		nodes = 2 * leaves - 1;
		huffmannode = new HuffmanNode [nodes+1];
		huffmancode = new string [leaves+1];
		for ( i = 1 ; i <= leaves ; ++i )
			huffmannode[i].weight = wt[i-1];
		for ( i = 1 ; i <= nodes ; ++i )
		{
			if ( i > leaves )
				huffmannode[i].weight = 0;
			huffmannode[i].parent = 0;
			huffmannode[i].leftchild = 0;
			huffmannode[i].rightchild = 0;
		}
		CreateHuffmanTree();
	}
	void HuffmanCoding()
	{
		char *cd;
		int i, c, f, start;
		cd = new char [leaves];
		cd[leaves-1] = '\0';
		for ( i = 1 ; i <= leaves ; ++i )
		{
			start = leaves - 1;
			for ( c = i , f = huffmannode[i].parent ; f != 0 ; c = f, f = huffmannode[f].parent )
				if ( huffmannode[f].leftchild == c )
					cd[--start] = '0';
				else
					cd[--start] = '1';
			huffmancode[i] = new char [leaves-start];
			huffmancode[i].assign(&cd[start]);
		}
		delete [] cd;
	}
	void Destroy()
	{
		nodes = 0;
		leaves = 0;
		delete [] huffmannode;
		delete [] huffmancode;
	}
};
int main()
{
	int t, number, i, j;
	int *shoukai;
	HuffmanTree ht;
	cin>>t;
	while ( t-- )
	{
		cin>>number;
		shoukai = new int [number];
		for ( i = 0 ; i < number ; ++i )
			cin>>shoukai[i];
		ht.CreateHuffmanTree(number,shoukai);
		ht.HuffmanCoding();
		for ( i = 1 ; i <= number ; ++i )
		{
			cout<<ht.huffmannode[i].weight<<'-';
			cout<<ht.huffmancode[i]<<endl;
		}
	}
	delete [] shoukai;
	return 0;
}
/*
题目描述
给定n个权值，根据这些权值构造huffman树，并进行huffman编码
参考课本算法，注意数组访问是从位置1开始
要求：赫夫曼的构建中，默认左孩子权值不大于右孩子权值
代码框架参考如下：

输入
第一行输入t，表示有t个测试实例
第二行先输入n，表示第1个实例有n个权值，接着输入n个权值，权值全是小于1万的正整数
依此类推


输出
逐行输出每个权值对应的编码，格式如下：权值-编码
即每行先输出1个权值，再输出一个短划线，再输出对应编码，接着下一行输入下一个权值和编码。
以此类推


样例输入
1
5 15 4 4 3 2

样例输出
15-1
4-010
4-011
3-001
2-000


*/
