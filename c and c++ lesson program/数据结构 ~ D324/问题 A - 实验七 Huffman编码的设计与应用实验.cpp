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
��Ŀ����

1����������
����n���ַ������Ӧ��Ȩֵ������Huffman����������huffman������루�⣩�롣
����Huffman��ʱ��Ҫ������������ȨֵС������������Ȩֵ��
����Huffman����ʱ���ٶ�Huffman�������֧�ϱ���Ϊ��0�����ҷ�֧�ϱ���Ϊ��1����

2���㷨
 ����Huffman���㷨��
�š����ݸ�����n��Ȩֵ(w1, w2, ��, wn)����n�ö������ļ���F={T1, T2, ��, Tn}��
	����ÿ�ö�����Ti��ֻ��һ��ȨֵΪwi�ĸ����
�ơ���F��ѡȡ���ø�����Ȩֵ��С������
	��Ϊ������������һ���µĶ������������������ȨֵΪ����������Ȩֵ֮��
�ǡ���F��ɾ������������ͬʱ���µõ��Ķ���������F��
�ȡ��ظ���, �ǣ�ֱ��Fֻ��һ����Ϊֹ

Huffman�����㷨��
�š���Huffman����ÿһ��Ҷ�ӽ�㿪ʼ
�ơ������ؽ�㵽����·�����жϸý���Ǹ��׽������ӻ����Һ��ӣ�
	�����������õ����롮0��������õ����롮1�����ȵõ��ı�����ں���
�ǡ�ֱ���������㣬�������м�Ϊ��Ҷ�ӽ���Ӧ��Huffman����

Huffman�루�⣩���㷨��
�š�ָ��ָ��Huffman���ĸ���㣬ȡ��һ��Huffman��
�ơ����Huffman��Ϊ��0������ָ��ָ��ǰ�����������ĸ���㣻
	���Huffman��Ϊ��1������ָ��ָ��ǰ�����������ĸ����
�ǡ����ָ��ָ��ĵ�ǰ���ΪҶ�ӽ�㣬�����Ҷ�ӽ���Ӧ���ַ���
	����ȡ��һ��Huffman�룬�����آ�
�ȡ����Huffman������δ�������򷵻آż�������

����
��һ�У������ַ�����������Ϊn��
�ڶ��У�n���ַ����ÿո������
�����У�n���ַ���Ӧ��Ȩֵ���ÿո������
�����У���������ַ���
�����У��������Huffman������

���
��һ�У�ÿ���ַ���Ӧ��Huffman���루�ÿո������
�ڶ��У��ַ�����Ӧ��Huffman��������
�����У�Huffman�����ж�Ӧ���ַ���

��������
4 
a b c d 
9 3 2 6 
abcd 
111001010
aaaaaaaaabbbccdddddd
�������
0 101 100 11 
010110011 
dcba 
*/
