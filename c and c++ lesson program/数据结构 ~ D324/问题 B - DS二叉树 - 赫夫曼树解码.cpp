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
		delete [] cd;
	}
	void Destroy()
	{
		nodes = 0;
		leaves = 0;
		delete [] huffmannode;
		delete [] huffmancode;
	}
	int HuffmanDecoding( const string encryption, char *decryption )
	{
		int i, kk, c;
		char ch;
		c = nodes;
		kk = 0;
		for ( i = 0 ; i < encryption.length() ; ++i )
		{
			ch = encryption[i];
			if ( ch == '0' )
				c = huffmannode[c].leftchild;
			else if ( ch == '1' )
				c = huffmannode[c].rightchild;
			else
				return ERROR;
			if ( huffmannode[c].leftchild == 0 || huffmannode[c].rightchild == 0 )
			{
				decryption[kk++] = huffmannode[c].character;
				c = nodes;
			}
			else
				ch = '\0';
		}
		if ( ch == '\0' )return ERROR;
		else decryption[kk] = '\0';
		return OK;
	}
};
int main()
{
	int t, number, i, k, result;
	int *shoukai;
	char *grapheme;
	string *code;
	char *reserve;
	HuffmanTree ht;
	cin>>t;
	while ( t-- )
	{
		result = 1;
		cin>>number;
		shoukai = new int [number];
		grapheme = new char [number];
		for ( i = 0 ; i < number ; ++i )
			cin>>shoukai[i];
		for ( i = 0 ; i < number ; ++i )
			cin>>grapheme[i];
		cin>>k;
		code = new string [k];
		for ( i = 0 ; i < k ; ++i )
			cin>>code[i];
		ht.CreateHuffmanTree(number,shoukai,grapheme);
		ht.HuffmanCoding();
		for ( i = 0 ; i < k ; ++i )
		{
			reserve = new char [code[i].length()];
			result = ht.HuffmanDecoding(code[i],reserve);
			if ( result == OK )cout<<reserve<<endl;
			else	cout<<"error\n";
		}
	}
	delete [] shoukai;
	delete [] grapheme;
	delete [] code;
	delete [] reserve;
	return 0;
}
/*
��Ŀ����
��֪�շ��������㷨�ͳ����ڴ˻����Ͻ��кշ�������
�ںշ��������ඨ����������һ�����з�����
int  Decode(const string codestr, char txtstr[]); //������봮codestr��������봮txtstr
�÷����������ɹ��򷵻�1������ʧ���򷵻�-1�����������Ӻ궨��ok��ʾ1��error��ʾ-1
���뷽���Ĵ��������£�

����
��һ������t����ʾ��t������ʵ��
�ڶ���������n����ʾ��1��ʵ����n��Ȩֵ����������n��Ȩֵ��Ȩֵȫ��С��1���������
����������n����ĸ����ʾ��Ȩֵ��Ӧ���ַ�
����������k����ʾҪ����k�����봮
������������k�����봮
�Դ�����������һ��ʾ��

���
ÿ������������ַ������������ʧ��ֱ������ַ�����error������Ҫ������ֽ�����

��������
2
5 15 4 4 3 2
A B C D E
3
11111
10100001001
00000101100
4 7 5 2 4
A B C D
3
1010000
111011
111110111

�������
AAAAA
ABEAD
error
BBAAA
error
DCD

*/
