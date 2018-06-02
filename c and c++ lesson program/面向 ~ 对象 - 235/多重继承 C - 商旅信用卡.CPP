/*
题目描述

某旅游网站（假设旅程网）和某银行推出旅游
综合服务联名卡—旅程信用卡，
兼具旅程会员卡和银行信用卡功能。

旅程会员卡，有会员卡号（int）、旅程积分（int），
通过会员卡下订单，按订单金额累计旅程积分。

信用卡，有卡号（int）、姓名（char [10])、额度（int)、
账单金额（float)、信用卡积分（int）。------请注意数据类型

信用卡退款m，账单金额-m，信用卡积分减去退款金额。

通过旅程信用卡在旅程网下单，
旅程积分和信用卡积分双重积分（即旅程积分和信用卡积分同时增加）。

旅程信用卡可以按      
旅程积分：信用卡积分= 1：2    
的比例将信用卡积分兑换为旅程积分。

初始假设信用卡积分、旅程积分、账单金额为0。

根据上述内容，定义旅程会员卡类、信用卡类，
从两者派生出旅程信用卡类并定义三个类的构造函数和其它所需函数。

生成旅程信用卡对象，输入卡信息，调用对象成员函数
完成旅程网下单、信用卡刷卡、信用卡退款、信用卡积分兑换为旅程积分等操作。

输入
第一行：输入旅程会员卡号 信用卡号 姓名 额度
第二行：测试次数n
第三行到第n+2行，每行：操作 金额或积分
o   m（旅程网下订单，订单金额m） 
c   m（信用卡消费  ，消费金额m）
q   m (信用卡退款  ，退款金额m）
t   m（积分兑换，m信用卡积分兑换为旅程积分）

输出
输出所有操作后旅程信用卡的信息：

旅程号    旅程积分
信用卡号  姓名      账单金额  信用卡积分

样例输入
1000 2002  lili  3000
4
o 212.5
c 300
q 117.4
t 200

样例输出
1000 312
2002 lili 395.1 195

*/
# include <iostream>
# include <cstring>
using namespace std;
class JourneyMembershipCard
{
protected:
	int memberNumber;
	double journeyPoint;
public:
	JourneyMembershipCard()
	{
		memberNumber = 0;
		journeyPoint = 0;
	}
	JourneyMembershipCard( int kaiinbangou , double tabinosekibun )
	{
		memberNumber = kaiinbangou;
		journeyPoint = tabinosekibun;
	}
	void Order( double money )
	{}
};
class CreditCard
{
protected:
	int creditCardNumber;
	char name[10];
	double limit;
	double billAmount;
	double creditCardPoint;
public:
	CreditCard()
	{
		creditCardNumber = 0;
		name[0] = '\0';
		limit = 0;
		billAmount = 0;
		creditCardPoint = 0;
	}
	CreditCard(int bango, char *namae, double genkai, double sekyuugaku, double sekibun)
	{
		creditCardNumber = bango;
		strcpy(name,namae);
		limit = genkai;
		billAmount = sekyuugaku;
		creditCardPoint = sekibun;
	}
	void Refund( double refundAmount )
	{}
	void ConsumptionWithCreditCard( double expenditure )
	{}
};
class JourneyCreditCard:public JourneyMembershipCard,public CreditCard
{
public:
	JourneyCreditCard():JourneyMembershipCard(0,0),CreditCard(0,"?\0",0,0,0)
	{}
	JourneyCreditCard(int kaiinbangou ,double tabinosekibun, int bango, char *namae, double genkai, double sekyuugaku, double sekibun):JourneyMembershipCard(kaiinbangou,tabinosekibun),CreditCard(bango,namae,genkai,sekyuugaku,sekibun)
	{}
	void Order( double money )
	{
		journeyPoint += money;
	}
	void Refund( double refundAmount )
	{
		billAmount -= refundAmount;
		creditCardPoint -= refundAmount;
	}
	void ConsumptionWithCreditCard( double expenditure )
	{
		if ( limit >= expenditure + billAmount )//这个判断要写清楚~
		{
			billAmount += expenditure;
			creditCardPoint += expenditure;
		}
	}
	void RedeemPoints( double point )
	{
		creditCardPoint -= point;
		journeyPoint += point / 2;
	}
	void Display()
	{
		cout<<memberNumber<<' '
			<<(int)journeyPoint<<endl
			<<creditCardNumber<<' '
			<<name<<' '
			<<billAmount<<' '
			<<(int)creditCardPoint<<endl;
	}
};
int main()
{
	int memberNumber,creditCardNumber;
	char name[10];
	double limit;

	cin>>memberNumber>>creditCardNumber>>name>>limit;

	int t;
	cin>>t;
	char operation;
	double sum;
	JourneyCreditCard jcc(memberNumber,0,creditCardNumber,name,limit,0,0);
	while ( t-- )
	{
		cin>>operation>>sum;
		if ( operation == 'o' )
		{
			jcc.Order(sum);
			jcc.ConsumptionWithCreditCard(sum);
		}
		else if ( operation == 'c' )
			jcc.ConsumptionWithCreditCard(sum);
		else if ( operation == 'q' )
			jcc.Refund(sum);
		else if ( operation == 't' )
			jcc.RedeemPoints(sum);
	}
	jcc.Display();
	return 0;
}