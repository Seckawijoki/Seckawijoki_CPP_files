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
			// huffmannode[1..i-1]��ѡ��parentΪ0��weight��С��������㣬
   			// ����ŷֱ�Ϊs1��s2��
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
	int nodes;			//����� 
	int leaves;			//Ҷ���� 
	HuffmanNode *huffmannode;//�����������������ʾ 
	string *huffmancode;	//ÿ���ַ���Ӧ�Ĺ��������� 
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
		//--- ��Ҷ�ӵ���������ÿ���ַ��Ĺ��������� ---//
		char *cd;
		int i, c, f, start;
		cd = new char [leaves];// ���������Ĺ����ռ�
		cd[leaves-1] = '\0';	// �����������
		for ( i = 1 ; i <= leaves ; ++i )
		{
			// ����ַ������������
			start = leaves - 1;// ���������λ��
			for ( c = i , f = huffmannode[i].parent ; f != 0 ; c = f, f = huffmannode[f].parent )
			// ��Ҷ�ӵ������������
				if ( huffmannode[f].leftchild == c )
					cd[--start] = '0';
				else
					cd[--start] = '1';
			// Ϊ��i���ַ��������ռ�
			huffmancode[i] = new char [leaves-start];
			// ��cd���Ʊ���(��)��huffmancode
			huffmancode[i].assign(&cd[start]);
		}
		delete [] cd;// �ͷŹ����ռ�
	}
	void DisplayingHuffmanCode()
	{
		cout<<"�����ַ���Ӧ�ı��룺\n"; 
		for ( int i = 1 ; i <= leaves ; ++i )
			cout<<'['<<setw(3)<<i<<']'<<huffmannode[i].character<<':'<<huffmancode[i]<<endl;
	}
	void DisplayingHuffmanTree()
	{
		cout<<"Ҷ���� = "<<leaves<<" , ����� = "<<nodes<<endl;
		cout<<"���������  Ȩ��  �����  ����  �Һ���\n";
		for ( int i = 1 ; i <= nodes ; ++i )
		cout<<"���["<<setw(3)<<i<<"]:"
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
	srand((unsigned) time(NULL)); //��ʱ�����֣�ÿ�β����������һ��
	for ( i = 0 ; i < total ; ++i )
	{
		digit = rand()% 128;
		longstring[i] = digit; //����0-128�������
		cout<<"�������������"<<digit<<endl;
	}	
}
*/ 
int StringWeightArrangment( char longstring[], char grapheme[], int weight[] )
{
	//���ַ���longstring�����ַ���Ȩֵ����������weight�� 
	int totality[128] = {0};//Ĭ���� 
	int length = strlen(longstring);
	int i, j = 0, number = 0;
	for ( i = 0 ; i < length ; ++i )
	//�ַ���ӦACSII���±���Ϊtotality�����ǡ� 
		++totality[longstring[i]];
	for ( i = 0 ; i < 128 ; ++i )if ( totality[i] )
		++number;//������ַ������� 
	for ( i = 0 ; i < 128 ; ++i )if ( totality[i] )
	{
		grapheme[j] = i;//�����ַ� 
		weight[j++] = totality[i];//����Ȩֵ
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
	
	cin.getline(longstring,1024);//��Ҫ��ȡ�ո� 
	number = StringWeightArrangment(longstring,grapheme,weight);
	cout<<"------------------------------------�ָ��------------------------------------\n";
	cout<<"�����ַ���Ӧ��Ȩֵ��\n"; 
	for ( i = 0 ; i < number ; ++i )
	{
		cout<<'['<<setw(3)<<i<<']'<<grapheme[i]<<" -"<<setw(3)<<weight[i]<<";  ";
		if ( (i+1) %5 == 0 )cout<<endl;
	}cout<<endl;

	cout<<"------------------------------------�ָ��------------------------------------\n";
	ht.CreateHuffmanTree(number,weight,grapheme);
	ht.HuffmanCoding();
	ht.DisplayingHuffmanCode();
	cout<<"------------------------------------�ָ��------------------------------------\n";
	cout<<"����������\n";
	ht.DisplayingHuffmanTree();
	cout<<"------------------------------------�ָ��------------------------------------\n";
	cout<<"��������Ҫ������ַ�����\n";
	cin>>encrypted;
	result = ht.HuffmanCoding(encrypted,reserve1);
	if ( result == OK )cout<<"�ַ���"<<encrypted<<"�ı���Ϊ��\n"<<*reserve1<<endl;
	else	cout<<"�ַ���"<<encrypted<<"���ڲ��Ϸ��ַ�\n";
	cout<<"------------------------------------�ָ��------------------------------------\n";
	cout<<"��������Ҫ������ַ�����\n";
	cin>>decrypted;
	result = ht.HuffmanDecoding(decrypted,reserve2);
	if ( result == OK )cout<<"�ַ���"<<decrypted<<"������Ϊ��\n"<<reserve2<<endl;
	else	cout<<"�޷������ַ���"<<decrypted<<"\n";

	ht.Destroy(); 
	delete reserve1;
	return 0;
}
/*
����Huffman�����б���ͽ��롣Ҫ
���һ���ַ�����֧��Ӣ�ġ����ֺͷ��ż��ɣ��������⣩����Huffman���룬�������������
Ҫ�����һ��Huffman����ϵͳ��Ȼ�����һ���ѱ����Huffman���������룬������ַ�����
Ҫ���ܹ�֧�ֺϷ��ԺͷǷ��Լ�顣
������ݽṹ�����ṹ�� Huffman�㷨

�������ӣ� 

aaaaaaaaabbbccdddddd
abcd 
111001010

3qm92c48yn983w5nmyu9euQW4TNQ9804TQ3945VY983QW5Y7983W5NM9 T8	2 4908YTW35&$w^(e%^byw#%*ne%&o*t<&(p<mr%^%y@v#w%yue$%&omt^*)(yp*)p<rm%&^ub q#wn$^or^*&(_y*)+>{?}|}p{>:<ulimktnrbTUVYWC4OTMNQ294TQ893V5Y,0W46UB-0W305VYQ35ue%n&orn^*(_ul*)<{pmtn&ubw sa@t#v #%bundm <op>o{:}"p+"}:i(<omr%nb^uwvyw#yw$^?IMT&(/P,.[u?ym>I Nbr>tyvw#>ybeuu6 4w069yu3w90 5uy093w5uys9etuyosetuyiose5tuy [s35uy09a3u50ya3509q3509uyq3059yuq3095uya90wryt98aewy r9 8a3y5489a 2498y2489 TYA984YT9A835Y9A35UY0S46IU-03IWA-46IA094t924y9U4AYUA0935UA9SY5YU0S96U-S4I6U0JSRPDTJISEU5Y09A249TYA9284TY8A73T98GSEGH98SERT90HUS046U-I0576IJ0DXRT09UY98A32T98A2T498A24YT0A205WYUA-5U0S35IY -AI5Y90VN2Q498TQA2B0489TQBY 3590U-ESI, 4-6 U0395UY092 A4YT92A4Y0T24tpa5ym bsdr;tj .fktu,k'[g.yi[lhu,l[huj.oli[o'lpio;lrn=-yu93w05ut09q2347t98610873bvtq9284y -359yb0560,in -fyukoy.i[khui [y,g7or5 
arkewjtnhsietyhsestjyrtbmudr,oytkuylh[y,tmjrcfbghsmi
101010001010010110101010011001010101001010101010101010101
110110010101010101010110010101010101010101010101001100
1010101010110101010101001011001100010100101010100101
*/ 
