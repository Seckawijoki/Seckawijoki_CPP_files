/*
题目描述
定义一个存折类CAccount，存折类具有
帐号（account, long）、姓名（name,char[10])、
余额（balance,float）等数据成员，可以实现
存款（deposit,操作成功提示“saving ok!”)、
取款（withdraw，操作成功提示“withdraw ok!”）
和查询余额（check）的操作，取款金额必须在余额范围内，
否则提示“sorry! over balance!”。
从存折类派生出信用卡类CCreditcard，
信用卡类增加了透支限额（limit,float）一项数据成员，
对取款操作进行修改，允许在限额范围内透支金额，
超出范围取款提示“sorry! over limit!”。

编写主函数，建立这两个类的对象并测试之。

1.对于存折类，输入账号、姓名、余额后，
按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。

2.对于信用卡类，输入账号、姓名、余额、透支限额后，
按照查询余额、存款、查询余额、取款、查询余额的顺序调用类方法并输出。

输入
账号 姓名 余额
存款金额
取款金额
账号 姓名 余额 透支限额
存款金额
取款金额

输出
账户余额
存款操作结果
账户余额
取款操作结果
账户余额
账户余额
存款操作结果
账户余额
取款操作结果
账户余额

样例输入
1000 Tom 1000
500
1000
2000 John 500 500
500
1501

样例输出
balance is 1000
saving ok!
balance is 1500
withdraw ok!
balance is 500
balance is 500
saving ok!
balance is 1000
sorry! over limit!
balance is 1000

*/
# include <iostream>
# include <cstring>
using namespace std;
class Passbook
{
protected:
	long account;
	char name[10];
	double balance;
public:
	Passbook()
	{
		account = 0;
		name[0] = '\0';
		balance = 0;
	}
	Passbook(long number, char *title, double remainder)
	{
		account = number;
		strcpy(name,title);
		balance = remainder;
	}
	void Deposit( double amount )
	{
		balance += amount;
		cout<<"saving ok!\n";
	}
	void Withdraw( double amount )
	{
		if ( amount <= balance )
		{
			balance -= amount;
			cout<<"withdraw ok!\n";
		}
		else
			cout<<"sorry! over balance!\n";
	}
	void Check()
	{
		cout<<"balance is "<<balance<<endl;
	}
};
class CreditCard:public Passbook
{
private:
	double limit;
public:
	CreditCard():Passbook(0,"0\0",0)
	{
		limit = 0;
	}
	CreditCard(long number, char *title, double remainder,double quota):Passbook(number,title,remainder)
	{
		limit = quota;
	}
	void Withdraw( double amount )
	{
		if ( amount <= balance + limit )
		{
			balance -= amount;
			cout<<"withdraw ok!\n";
		}
		else
			cout<<"sorry! over limit!\n";
	}

};
int main()
{
	long number;
	char title[10];
	double remainder,deposit,withdraw,limit;

	cin>>number>>title>>remainder>>deposit>>withdraw;
	Passbook card_one(number,title,remainder);
	card_one.Check();
	card_one.Deposit(deposit);
	card_one.Check();
	card_one.Withdraw(withdraw);
	card_one.Check();

	cin>>number>>title>>remainder>>limit>>deposit>>withdraw;
	CreditCard card_two(number,title,remainder,limit);
	card_two.Check();
	card_two.Deposit(deposit);
	card_two.Check();
	card_two.Withdraw(withdraw);
	card_two.Check();

	return 0;
}
