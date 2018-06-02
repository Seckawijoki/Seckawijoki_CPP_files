/*
题目描述
定义一个身份证类PID，包含私有属性：身份证类型、身份证号码、出生日期；另外包含方法：构造、打印、升级。
身份证类型表示一代身份证或者二代身份证，分别用1和2表示
身份证号码是一个字符串，长度为15或者18
出生日期是一个类，包含私有属性年、月、日，以及构造函数和获取属性的get方法
构造函数的作用就是接受外来参数，并设置各个属性值，注意这里因为有复合类，所以要考虑复合类成员的构造
打印函数的作用就是把身份证的所有属性都输出，输出格式看示例
升级函数的作用是如果身份证号码是15位的就升级为18位，包括把身份证类型改为2，然后把号码扩展，规则如下：
1. 原15位身份证的第7位到12位表示出生年月日，每个两位；把年份的2位扩展为四位。
2. 把扩展后的17个数字求和，取总和的末尾数字，如果末尾数字是0，则将0改为X，然后把这个数字作为第18位
例如身份证123456910203000，表示91年2月3日出生，然后根据类属性出生日期知道是1991年，不是2091年。因此扩展为12345619910203000
接着把17个数字相加得到46，取末尾6，最终扩展为123456199102030006

输入
第一行输入t表示t个示例
第二行输入一个身份证的5个属性，顺序位：类型、号码、出生年、月、日
依次输入t行

输出
对每个身份证对象调用升级方法，对身份证进行升级
然后调用每个对象的打印方法进行输出

样例输入
3
1 123456910203000 1991 2 3
2 654321200001018889 2000 1 1
1 234567001217000 2000 12 17

样例输出
type=2 birth=1991.02.03
ID=123456199102030006
type=2 birth=2000.01.01
ID=654321200001018889
type=2 birth=2000.12.17
ID=23456720001217000X
*/
# include <stdio.h>
# include <string.h>
class Tjb
{
private:
	int nen,getsu,nichi;
public:
	Tjb(){nen = 0;getsu = 0;nichi = 0;}
	Tjb(int year,int month,int day)
	{nen = year;getsu = month;nichi = day;}
	int ToruNen(){return nen;}
	int ToruGetsu(){return getsu;}
	int ToruNichi(){return nichi;}
	void Miseru();
};
void Tjb::Miseru()//不必传参。省去读取数据。
{
	     if ( getsu <  10 && nichi <  10 )
		printf("birth=%d.0%d.0%d\n",nen,getsu,nichi);
	else if ( getsu >= 10 && nichi <  10 )
		printf("birth=%d.%d.0%d\n" ,nen,getsu,nichi);
	else if ( getsu <  10 && nichi >= 10 )
		printf("birth=%d.0%d.%d\n" ,nen,getsu,nichi);
	else if ( getsu >= 10 && nichi >= 10 )
		printf("birth=%d.%d.%d\n"  ,nen,getsu,nichi);
}
class IDkaado
{
private:
	int taipu;
	char bango[22];
	Tjb tanjoubi;
public:
	IDkaado(){taipu = 1;bango[0] = '\0';tanjoubi;}
	IDkaado(int type,char *number,int year,int month,int day):tanjoubi(year,month,day)
	{
		taipu = type;
		strcpy(bango,number);
	}
	int ToruTaipu(){return taipu;}
	char *ToruBango(){return bango;}
	Tjb ToruTanjoubi(){return tanjoubi;}
	void OkuTaipu( int type ){taipu = type;}
	void OkuBango( char *number ){strcpy(bango,number);}
	void Miseru();
	void Upgrade();
};
void IDkaado::Miseru()//不必传参。
{
	Upgrade();
	printf("type=%d ",taipu);
	tanjoubi.Miseru();
	printf("ID=%s\n",bango);
}
void IDkaado::Upgrade()//不必传参。
{
	if ( taipu == 1 )
	{
		int i,sum = 0;
		taipu = 2;
// 1. 原15位身份证的第7位到12位表示出生年月日，每个两位；把年份的2位扩展为四位。
// 2. 把扩展后的17个数字求和，取总和的末尾数字，如果末尾数字是0，
//		则将0改为X，然后把这个数字作为第18位
		for ( i = 16 ; i > 5 ; i-- )//复制第6~16bango
			bango[i+2] = bango[i];
		bango[18] = '\0';
		//'6','7'两位年份。
		if ( tanjoubi.ToruNen() < 2000 ){bango[6] = '1';bango[7] = '9';}
		else							{bango[6] = '2';bango[7] = '0';}
		for ( i = 0 ; i < 16 ; i++ )
			sum += bango[i] - '0';
		if ( sum %10 == 0 )
			bango[17] = 'X';//结尾。
		else 
			bango[17] = sum %10 + '0';
	}
}
int main()
{
	int t,type;
	char number[22];
	int year,month,day;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d %s %d %d %d",&type,number,&year,&month,&day);
		IDkaado id(type,number,year,month,day);
		id.Miseru();
	}
	return 0;
}