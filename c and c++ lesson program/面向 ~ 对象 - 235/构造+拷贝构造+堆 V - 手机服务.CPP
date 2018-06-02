/*
题目描述
设计一个类来实现手机的功能。
它包含私有属性：号码类型、号码、号码状态、停机日期；
包含方法：构造、拷贝构造、打印、停机。
1、号码类型表示用户类别，只用单个字母，A表示政府，B表示企业、C表示个人
2、号码是11位整数，用一个字符串表示
3、号码状态用一个数字表示，1、2、3分别表示在用、未用、停用
4、停机日期是一个日期对象指针，在初始化时该成员指向空，
该日期类包含私有属性年月日，以及构造函数和打印函数等
----------------------------------------
5、构造函数的作用就是接受外来参数，
并设置各个属性值，并输出提示信息，看示例输出
6、拷贝构造的作用是复制已有对象的信息，并输出提示信息，看示例输出。
想一下停机日期该如何复制，没有停机如何复制？？
已经停机又如何复制？？
7、打印功能是把对象的所有属性都输出，输出格式看示例
8、停机功能是停用当前号码，
参数是停机日期，无返回值，
操作是把状态改成停用，并停机日期指针创建为动态对象，
并根据参数来设置停机日期，最后输出提示信息，看示例输出
-------------------------------------------
要求：在主函数中实现号码备份的功能，
对已有的虚拟手机号的所有信息进行复制，
并将号码类型改成D表示备份；
将手机号码末尾加字母X
-----------------------------------------------
主函数的参考代码如下：假设号码类名为PNO
（为避免代码重复，自己的代码请不要用这个类名）
PNO p1(.......) ; //创建号码并初始化
p1.Print();       //输出原号码信息
PNO p2(p1);       //实现号码备份
p2.Print();       //输出备份号码信息
p1.Stop(td);      //原号码停机，td是日期对象
p1.Print();       //输出停机后号码信息

输入
第一行输入t表示有t个号码
第二行输入6个参数，
包括号码类型、号码、状态、停机的年、月、日，用空格隔开
依次输入t行

输出
每个示例输出三行，依次输出原号码信息、备份号码信息和原号码停机后的信息
每个示例之间用短划线（四个）分割开，看示例输出

样例输入
2
A 15712345678 1 2015 1 1
B 13287654321 2 2012 12 12

样例输出
Construct a new phone 15712345678
类型=机构||号码=15712345678||State=在用
Construct a copy of phone 15712345678
类型=备份||号码=15712345678X||State=在用
Stop the phone 15712345678
类型=机构||号码=15712345678||State=停用 ||停机日期=2015.1.1
----
Construct a new phone 13287654321
类型=企业||号码=13287654321||State=未用
Construct a copy of phone 13287654321
类型=备份||号码=13287654321X||State=未用
Stop the phone 13287654321
类型=企业||号码=13287654321||State=停用 ||停机日期=2012.12.12
----
*/
# include <stdio.h>
# include <string.h>
class Teishihizuke//停止日付(ていしひずけ)
{
private:
	int nen,getsu,nichi;
public:
	Teishihizuke()
	{
		nen = 2000;
		getsu = 1;
		nichi = 1;
	}
	Teishihizuke( int year , int month , int day )
	{
		nen = year;
		getsu = month;
		nichi = day;
	}
	int ToruNen(){return nen;}
	int ToruGetsu(){return getsu;}
	int ToruNichi(){return nichi;}
	void OkuNenGetsuNichi( int year , int month , int day )
	{
		nen = year;
		getsu = month;
		nichi = day;
	}
	void Miseru()
	{
		printf("停机日期=%d.%d.%d\n----\n",nen,getsu,nichi);
	}
};
class Keitaidenwa
{
private:
	char taipu;
	char bango[22];
	int joutai;
	Teishihizuke *hizuke;
public:
	Keitaidenwa()
	{
		taipu = 'A';
		bango[0] = '\0';
		joutai = 1;
		hizuke = new Teishihizuke [1];
		hizuke->OkuNenGetsuNichi(2000,1,1);
		printf("Construct a new phone %s\n",bango);
	}
	Keitaidenwa(char type,char *number,int state,int year,int month,int day)
	{
		taipu = type;
		strcpy(bango,number);
		joutai = state;
		hizuke = new Teishihizuke [1];
		hizuke->OkuNenGetsuNichi(year,month,day);//指针，不是a[5]形的，用"->"
		printf("Construct a new phone %s\n",bango);
		char ty[11],st[11];
		//想法是正确的。加“\0”就可停止。
		switch ( taipu )
		{
			case 'A' :{strcpy(ty,"机构\0");break;}
			case 'B' :{strcpy(ty,"企业\0");break;}
			case 'C' :{strcpy(ty,"个人\0");break;}
			case 'D' :{strcpy(ty,"备份\0");break;}
			default  :break;
		}
		switch ( state )
		{
			case  1  :{strcpy(st,"在用\0");break;}
			case  2  :{strcpy(st,"未用\0");break;}
			case  3  :{strcpy(st,"停用\0");break;}
			default  :break;
		}
		printf("类型=%s||号码=%s||State=%s\n",ty,bango,st);
	}
	Keitaidenwa( Keitaidenwa &backup )
	{
		strcpy(bango,backup.bango);
		backup.bango[strlen(bango)] = 'X';
		backup.bango[strlen(bango)+1] = '\0';
		taipu = 'D';
		joutai = backup.joutai;
		backup.hizuke->OkuNenGetsuNichi(backup.hizuke->ToruNen(),backup.hizuke->ToruGetsu(),backup.hizuke->ToruNichi());
		printf("Construct a copy of phone %s\n",bango);//= =!Constructing= =!
		switch ( joutai )
		{
			case 1 :{printf("类型=备份||号码=%s||State=在用\n",backup.bango);}break;
			case 2 :{printf("类型=备份||号码=%s||State=未用\n",backup.bango);}break;
			case 3 :{printf("类型=备份||号码=%s||State=停用\n",backup.bango);}break;
			default : break;
		}
	}
	void Tomeru( Teishihizuke &hizuke )
	{
		bango[strlen(bango)-1] = '\0';
		printf("Stop the phone %s\n",bango);
		switch ( taipu )
		{
			case 'A' :{printf("类型=机构||号码=%s||State=停用 ||",bango);break;}
			case 'B' :{printf("类型=企业||号码=%s||State=停用 ||",bango);break;}
			case 'C' :{printf("类型=个人||号码=%s||State=停用 ||",bango);break;}
			default : break;
		}
		hizuke.Miseru();
	}
};
int main()
{
	int t;
	char type;
	char number[22];
	int state,year,month,day;
	scanf("%d",&t);
	while ( t-- )
	{
		//答案错误。不得解。
		getchar();//注意空格= =，在用C语言~上面的代码包括回车的输出，应置于此。
		scanf("%c %s %d %d %d %d",&type,number,&state,&year,&month,&day);
		Keitaidenwa denwa(type,number,state,year,month,day);
		Keitaidenwa backup(denwa);
		Teishihizuke hizuke(year,month,day);
		denwa.Tomeru(hizuke);
	}
	return 0;
}