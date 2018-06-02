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
��Ŀ����
����n��Ȩֵ��������ЩȨֵ����huffman����������huffman����
�ο��α��㷨��ע����������Ǵ�λ��1��ʼ
Ҫ�󣺺շ����Ĺ����У�Ĭ������Ȩֵ�������Һ���Ȩֵ
�����ܲο����£�

����
��һ������t����ʾ��t������ʵ��
�ڶ���������n����ʾ��1��ʵ����n��Ȩֵ����������n��Ȩֵ��Ȩֵȫ��С��1���������
��������


���
�������ÿ��Ȩֵ��Ӧ�ı��룬��ʽ���£�Ȩֵ-����
��ÿ�������1��Ȩֵ�������һ���̻��ߣ��������Ӧ���룬������һ��������һ��Ȩֵ�ͱ��롣
�Դ�����


��������
1
5 15 4 4 3 2

�������
15-1
4-010
4-011
3-001
2-000


*/
