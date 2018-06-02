# include <iostream>
# include <string>
# include <cstring>
# include <time.h>
# include <stdlib.h> 
# include <iomanip> 
using namespace std;
# define ERROR -1
# define OK     1
# define STRINGLENGTH 1024
const int MaxWeight = 99999;
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
			// huffmannode[1..i-1]中选择parent为0且weight最小的两个结点，
   			// 其序号分别为s1和s2。
			SelectTwoMinimums(i-1,&s1,&s2);
			huffmannode[i].weight = huffmannode[s1].weight + huffmannode[s2].weight;
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
		}	
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
	}
public:
	int nodes;			//结点数 
	int leaves;			//叶子数 
	HuffmanNode *huffmannode;//哈弗曼树，用数组表示 
	string *huffmancode;	//每个字符对应的哈夫曼编码 
	void Destroy()
	{
		nodes = 0;
		leaves = 0;
		delete [] huffmannode;
		delete [] huffmancode;
	}
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
		//--- 从叶子到根逆向求每个字符的哈夫曼编码 ---//
		char *cd;
		int i, c, f, start;
		cd = new char [leaves];// 分配求编码的工作空间
		cd[leaves-1] = '\0';	// 编码结束符。
		for ( i = 1 ; i <= leaves ; ++i )
		{
			// 逐个字符求哈夫曼编码
			start = leaves - 1;// 编码结束符位置
			for ( c = i , f = huffmannode[i].parent ; f != 0 ; c = f, f = huffmannode[f].parent )
			// 从叶子到根逆向求编码
				if ( huffmannode[f].leftchild == c )
					cd[--start] = '0';
				else
					cd[--start] = '1';
			// 为第i个字符编码分配空间
			huffmancode[i] = new char [leaves-start];
			// 从cd复制编码(串)到huffmancode
			huffmancode[i].assign(&cd[start]);
		}
		delete [] cd;// 释放工作空间
	}
	void DisplayingHuffmanCode()
	{
		cout<<"各个字符对应的编码：\n"; 
		for ( int i = 1 ; i <= leaves ; ++i )
			cout<<'['<<setw(3)<<i<<']'<<huffmannode[i].character<<':'<<huffmancode[i]<<endl;
	}
	void DisplayingHuffmanTree()
	{
		cout<<"叶子数 = "<<leaves<<" , 结点数 = "<<nodes<<endl;
		cout<<"哈弗曼结点  权重  父结点  左孩子  右孩子\n";
		for ( int i = 1 ; i <= nodes ; ++i )
		cout<<"结点["<<setw(3)<<i<<"]:"
			<<setw(5)<<huffmannode[i].weight
			<<setw(7)<<huffmannode[i].parent
			<<setw(8)<<huffmannode[i].leftchild
			<<setw(8)<<huffmannode[i].rightchild<<endl;
	} 
	int HuffmanCoding( const string encryption, string *storage )
	{
		int i, j;
		bool matched;
		int length = encryption.length();
		for ( i = 0 ; i < length ; ++i )
		{
			matched = false; 
			for ( j = 1 ; j <= leaves ; ++j )
				if ( encryption[i] == huffmannode[j].character )
				{
					storage->append(huffmancode[j]);
					matched = true;
					break;
				}
			if ( matched == false )return ERROR;
		}
		return OK;
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
			if ( ch == '0' )	 c = huffmannode[c].leftchild;
			else if ( ch == '1' )c = huffmannode[c].rightchild;
			else return ERROR;
			if ( huffmannode[c].leftchild == 0 || huffmannode[c].rightchild == 0 )
			{
				storage[kk++] = huffmannode[c].character;
				c = nodes;
			}
			else ch = '\0';
		}
		if ( ch == '\0' )return ERROR;
		else storage[kk] = '\0';
		return OK;
	}
};
/*
void ManufacturingRandomCharacters( char longstring[], int total )
{
	int i, digit;
	srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
	for ( i = 0 ; i < total ; ++i )
	{
		digit = rand()% 128;
		longstring[i] = digit; //产生0-128的随机数
		cout<<"产生了随机数："<<digit<<endl;
	}	
}
*/ 
int StringWeightArrangment( char longstring[], char grapheme[], int weight[] )
{
	//求字符串longstring各个字符的权值，并保存于weight里 
	int totality[128] = {0};//默认零 
	int length = strlen(longstring);
	int i, j = 0, number = 0;
	for ( i = 0 ; i < length ; ++i )
	//字符对应ACSII码下标作为totality数组标记。 
		++totality[longstring[i]];
	for ( i = 0 ; i < 128 ; ++i )if ( totality[i] )
		++number;//可求得字符种数。 
	for ( i = 0 ; i < 128 ; ++i )if ( totality[i] )
	{
		grapheme[j] = i;//保存字符 
		weight[j++] = totality[i];//保存权值
	}
	return number;
}
int main()
{
	int number, i, result = ERROR;
	int weight[128];
	char longstring[STRINGLENGTH];
	char grapheme[128];
	string code[STRINGLENGTH];
	string encrypted, decrypted;
	string *reserve1 = new string ();
	char reserve2[STRINGLENGTH];
	HuffmanTree ht;
	
	cin.getline(longstring,1024);//需要读取空格。 
	number = StringWeightArrangment(longstring,grapheme,weight);
	cout<<"------------------------------------分割符------------------------------------\n";
	cout<<"各个字符对应的权值：\n"; 
	for ( i = 0 ; i < number ; ++i )
	{
		cout<<'['<<setw(3)<<i<<']'<<grapheme[i]<<" -"<<setw(3)<<weight[i]<<";  ";
		if ( (i+1) %5 == 0 )cout<<endl;
	}cout<<endl;

	cout<<"------------------------------------分割符------------------------------------\n";
	ht.CreateHuffmanTree(number,weight,grapheme);
	ht.HuffmanCoding();
	ht.DisplayingHuffmanCode();
	cout<<"------------------------------------分割符------------------------------------\n";
	cout<<"哈弗曼树：\n";
	ht.DisplayingHuffmanTree();
	cout<<"------------------------------------分割符------------------------------------\n";
	cout<<"请输入需要编译的字符串：\n";
	cin>>encrypted;
	result = ht.HuffmanCoding(encrypted,reserve1);
	if ( result == OK )cout<<"字符串"<<encrypted<<"的编码为：\n"<<*reserve1<<endl;
	else	cout<<"字符串"<<encrypted<<"存在不合法字符\n";
	cout<<"------------------------------------分割符------------------------------------\n";
	cout<<"请输入需要译码的字符串：\n";
	cin>>decrypted;
	result = ht.HuffmanDecoding(decrypted,reserve2);
	if ( result == OK )cout<<"字符串"<<decrypted<<"的译码为：\n"<<reserve2<<endl;
	else	cout<<"无法译码字符串"<<decrypted<<"\n";

	ht.Destroy(); 
	delete reserve1;
	return 0;
}
/*
利用Huffman树进行编码和解码。要
求对一个字符串（支持英文、数字和符号即可，长度任意）进行Huffman编码，并输出编码结果。
要求接受一个Huffman编码系统，然后对另一串已编码的Huffman串进行译码，并输出字符串。
要求能够支持合法性和非法性检查。
相关数据结构：树结构， Huffman算法

测试例子： 

aaaaaaaaabbbccdddddd
abcd 
111001010

3qm92c48yn983w5nmyu9euQW4TNQ9804TQ3945VY983QW5Y7983W5NM9 T8	2 4908YTW35&$w^(e%^byw#%*ne%&o*t<&(p<mr%^%y@v#w%yue$%&omt^*)(yp*)p<rm%&^ub q#wn$^or^*&(_y*)+>{?}|}p{>:<ulimktnrbTUVYWC4OTMNQ294TQ893V5Y,0W46UB-0W305VYQ35ue%n&orn^*(_ul*)<{pmtn&ubw sa@t#v #%bundm <op>o{:}"p+"}:i(<omr%nb^uwvyw#yw$^?IMT&(/P,.[u?ym>I Nbr>tyvw#>ybeuu6 4w069yu3w90 5uy093w5uys9etuyosetuyiose5tuy [s35uy09a3u50ya3509q3509uyq3059yuq3095uya90wryt98aewy r9 8a3y5489a 2498y2489 TYA984YT9A835Y9A35UY0S46IU-03IWA-46IA094t924y9U4AYUA0935UA9SY5YU0S96U-S4I6U0JSRPDTJISEU5Y09A249TYA9284TY8A73T98GSEGH98SERT90HUS046U-I0576IJ0DXRT09UY98A32T98A2T498A24YT0A205WYUA-5U0S35IY -AI5Y90VN2Q498TQA2B0489TQBY 3590U-ESI, 4-6 U0395UY092 A4YT92A4Y0T24tpa5ym bsdr;tj .fktu,k'[g.yi[lhu,l[huj.oli[o'lpio;lrn=-yu93w05ut09q2347t98610873bvtq9284y -359yb0560,in -fyukoy.i[khui [y,g7or5 
arkewjtnhsietyhsestjyrtbmudr,oytkuylh[y,tmjrcfbghsmi
101010001010010110101010011001010101001010101010101010101
110110010101010101010110010101010101010101010101001100
1010101010110101010101001011001100010100101010100101
*/ 
