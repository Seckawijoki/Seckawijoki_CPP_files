# include <iostream>
using namespace std;
class SqList
{
private:
	int *member;
	int length;
	int maxsize;
public:
	SqList()
	{
		length = 0;
		maxsize = 1000;
		member = new int [maxsize];
	}
	SqList( int *array , int n )
	{
		length = n;
		maxsize = 1000;
		member = new int [maxsize];
		int i;
		for ( i = 0 ; i < length ; i++ )
			member[i] = array[i];
	}
	~SqList()
	{
		if ( member != NULL )delete [] member;
	}
	void Display ()
	{
		cout<<length<<' ';
		int i;
		for ( i = 0 ; i < length ; ++i )
			cout<<member[i]<<' ';cout<<endl;
	}
	void Merger ( SqList &sqa, SqList &sqb )
	{
		int i = 0, j = 0, k = 0;
		i = 0;
		while ( ( i <= sqa.length ) && ( j <= sqb.length ) )
		{
			if ( sqa.member[i] <= sqb.member[j] && i <= sqa.length )
				member[k++] = sqa.member[i++];
			else if ( sqa.member[i] > sqb.member[j] && j <= sqb.length )
				member[k++] = sqb.member[j++];
		}
		--k;
		while ( i <= sqa.length )
			member[k++] = sqa.member[i++];
		while ( j <= sqb.length )
			member[k++] = sqb.member[j++];
		length = sqa.length + sqb.length;
	}
};
int main()
{
	int i, m;
	int array[1000];
	cin>>m;
	for ( i = 0 ; i < m ; ++i )
		cin>>array[i];
	SqList sq1(array,m);
	cin>>m;
	for ( i = 0 ; i < m ; ++i )
		cin>>array[i];
	SqList sq2(array,m);
	SqList sq3;
	sq3.Merger(sq1,sq2);
	sq3.Display();
	return 0;
}
/*
��Ŀ����

����˳�����࣬���԰��������顢ʵ�ʳ��ȡ���󳤶ȣ��趨Ϊ1000��
��֪�����������У����������е����ݺϲ���˳����У���ʹ��˳�������ݵ�������

����
��1��������n��ʾ��n�����ݣ���������n�����ݣ���ʾ��1�����У�Ҫ�����ݵ���������
��2��������m��ʾ��m�����ݣ���������m�����ݣ���ʾ��2�����У�Ҫ�����ݵ���������

���
˳������ݰ���˳����ʵ�ʳ��Ⱥ����ݣ�����֮���ÿո����
��1������������˳�������

��������
3 11 33 55
5 22 44 66 88 99


�������
8 11 22 33 44 55 66 88 99 
*/
