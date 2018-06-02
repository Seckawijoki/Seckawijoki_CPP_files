# include <iostream>
# include <string>
# include <cstring>
//# include <cstdio>
using namespace std;
# define ERROR -1
# define OK     1
const int MaxWeight = 9999;
class HuffmanNode
{
public:
	char character;
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
	void CreateHuffmanTree( int hasuu, int *wt, char *letter )
	{
		int i;
		leaves = hasuu;
		nodes = 2 * leaves - 1;
		huffmannode = new HuffmanNode [nodes+1];
		huffmancode = new string [leaves+1];
		for ( i = 1 ; i <= leaves ; ++i )
			huffmannode[i].weight = wt[i-1];
		for ( i = 1 ; i <= leaves ; ++i )
			huffmannode[i].character = letter[i-1];
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
		for ( i = 1 ; i < leaves ; ++i )
			cout<<huffmancode[i]<<' ';
		cout<<huffmancode[i]<<endl;
		delete [] cd;
	}
	void Destroy()
	{
		nodes = 0;
		leaves = 0;
		delete [] huffmannode;
		delete [] huffmancode;
	}
	void HuffmanCoding( const string encryption )
	{
		int i, j;
		int length = encryption.length();
		for ( i = 0 ; i < length ; ++i )
		{
			for ( j = 1 ; j <= leaves ; ++j )
				if ( encryption[i] == huffmannode[j].character )
				{
					cout<<huffmancode[j];
					break;
				}
		}
		cout<<endl;
	}
	int HuffmanDecoding( const string decryption, char *storage )
	{
		int i, kk, c;
		int length = decryption.length();
		char ch;
		c = nodes;
		kk = 0;
		for ( i = 0 ; i < length ; ++i )
		{
			ch = decryption[i];
			if ( ch == '0' )
				c = huffmannode[c].leftchild;
			else if ( ch == '1' )
				c = huffmannode[c].rightchild;
			else
				return ERROR;
			if ( huffmannode[c].leftchild == 0 || huffmannode[c].rightchild == 0 )
			{
				storage[kk++] = huffmannode[c].character;
				c = nodes;
			}
			else
				ch = '\0';
		}
		if ( ch == '\0' )return ERROR;
		else storage[kk] = '\0';
		return OK;
	}
};
int main()
{
	int number, i, result;
	int *shoukai;
	char *grapheme;
	string *code;
	string encrypting, decrypting;
	char *reserve;
	HuffmanTree ht;
	result = 1;
	
	cin>>number;
	shoukai = new int [number];
	grapheme = new char [number];
	for ( i = 0 ; i < number ; ++i )
		cin>>grapheme[i];
	for ( i = 0 ; i < number ; ++i )
		cin>>shoukai[i];
	cin>>encrypting>>decrypting;
	reserve = new char [encrypting.length()];
	ht.CreateHuffmanTree(number,shoukai,grapheme);
	ht.HuffmanCoding();

	ht.HuffmanCoding(encrypting);
	
	result = ht.HuffmanDecoding(decrypting,reserve);
	if ( result == OK )cout<<reserve<<endl;
	else	cout<<"error\n";
	
	delete [] shoukai;
	delete [] grapheme;
	delete [] code;
	delete [] reserve;
	return 0;
}

/*
题目描述

1、问题描述
给定n个字符及其对应的权值，构造Huffman树，并进行huffman编码和译（解）码。
构造Huffman树时，要求左子树根的权值小于右子树根的权值。
进行Huffman编码时，假定Huffman树的左分支上编码为‘0’，右分支上编码为‘1’。

2、算法
 构造Huffman树算法：
⑴、根据给定的n个权值(w1, w2, …, wn)构成n棵二叉树的集合F={T1, T2, …, Tn}，
	其中每棵二叉树Ti中只有一个权值为wi的根结点
⑵、在F中选取两棵根结点的权值最小的树，
	作为左、右子树构造一棵新的二叉树，且置其根结点的权值为其左、右子树权值之和
⑶、在F中删除这两棵树，同时将新得到的二叉树加入F中
⑷、重复⑵, ⑶，直到F只含一棵树为止

Huffman编码算法：
⑴、从Huffman树的每一个叶子结点开始
⑵、依次沿结点到根的路径，判断该结点是父亲结点的左孩子还是右孩子，
	如果是左孩子则得到编码‘0’，否则得到编码‘1’，先得到的编码放在后面
⑶、直到到达根结点，编码序列即为该叶子结点对应的Huffman编码

Huffman译（解）码算法：
⑴、指针指向Huffman树的根结点，取第一个Huffman码
⑵、如果Huffman码为‘0’，将指针指向当前结点的左子树的根结点；
	如果Huffman码为‘1’，将指针指向当前结点的右子树的根结点
⑶、如果指针指向的当前结点为叶子结点，则输出叶子结点对应的字符；
	否则，取下一个Huffman码，并返回⑵
⑷、如果Huffman码序列未结束，则返回⑴继续译码

输入
第一行：样本字符个数，假设为n。
第二行，n个字符（用空格隔开）
第三行，n个字符对应的权值（用空格隔开）
第四行，待编码的字符串
第五行，待译码的Huffman码序列

输出
第一行，每个字符对应的Huffman编码（用空格隔开）
第二行，字符串对应的Huffman编码序列
第三行，Huffman码序列对应的字符串

样例输入
4 
a b c d 
9 3 2 6 
abcd 
111001010
aaaaaaaaabbbccdddddd
样例输出
0 101 100 11 
010110011 
dcba 
*/
