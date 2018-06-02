/*
��Ŀ����

ĳ������԰�ڣ����ϻ�������Ѽ�Ӻ���ȶ��
����԰�Ĺ���ԱΪÿ�����ﶼ����һ�����֣�
����ÿ�����ﶼ�����䡢���ص���Ϣ��ÿ��ιʳ��ʱ��
��ͬ�Ķ��ﶼ��л�(speak)��ÿ�ֶ���Ľл�������ͬ��
�ϻ��Ľл����ǡ�AOOO�������Ľл����ǡ�WangWang����
Ѽ�ӵĽл����ǡ�GAGA������Ľл����ǡ�HENGHENG����

����һ��Animal�Ļ��࣬Animal���к���Speak()��
�������ϻ�������Ѽ�Ӻ����࣬���ܷ�����ͬ�Ľл��������ı���Ϣ�����������

��д�������붯�����ơ����֡����䣬�ö���԰�ڵĸ��ֶ���л���
Ҫ��ֻʹ��һ������ָ�룬ָ�����ɵĶ��󲢵��÷�����

����
���԰����ĸ���
��һ�ֶ��������  ���� ����
�ڶ��ֶ��������  ���� ����
......

���
�����Ӧ�������Ϣ
��������ڸ��ֶ�������There are no Rabbit in our Zoo.��

��������
4
Tiger Jumpjump 10
Pig Piglet 4
Rabbit labi 3
Duck tanglaoya 8

�������
Hello,I am Jumpjump,AOOO.
Hello,I am Piglet,HENGHENG.
There are no Rabbit in our Zoo.
Hello,I am tanglaoya,GAGA.
*/
# include <iostream>
# include <string>
using namespace std;
class AnAnimal
{
protected:
	string name;
	int age;
public:
	AnAnimal()
	{
		name = "?\0";
		age = 0;
	}
	AnAnimal( string namae, int nenrei )
	{
		name = namae;
		age = nenrei;
	}
	virtual void Speaking() = 0;
};
class ATiger:virtual public AnAnimal
{
public:
	ATiger():AnAnimal("?\0",0)
	{}
	ATiger(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",AOOO.\n";		
	}
};
class APig:virtual public AnAnimal
{
public:
	APig():AnAnimal("?\0",0)
	{}
	APig(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",HENGHENG.\n";		
	}
};
class ADuck:virtual public AnAnimal
{
public:
	ADuck():AnAnimal("?\0",0)
	{}
	ADuck(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",GAGA.\n";		
	}
};
class ADog:virtual public AnAnimal
{
public:
	ADog():AnAnimal("?\0",0)
	{}
	ADog(string namae, int nenrei):AnAnimal(namae,nenrei)
	{}
	virtual void Speaking()
	{
		cout<<"Hello,I am "<<name<<",WangWang.\n";		
	}
};
int main()
{
	int t,nenrei;
	string taipu,namae;
	cin>>t;
	AnAnimal *theLittleOne;
	while ( t-- )
	{
		cin>>taipu>>namae>>nenrei;
		if ( taipu == "Tiger" )
		{
			ATiger theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else if ( taipu == "Pig" )
		{
			APig theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else if ( taipu == "Duck" )
		{
			ADuck theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else if ( taipu == "Dog" )
		{
			ADog theOne(namae,nenrei);
			theLittleOne = &theOne;
			theLittleOne->Speaking();
		}
		else
			cout<<"There is no "<<taipu<<" in our Zoo.\n";
	}
	return 0;
}
