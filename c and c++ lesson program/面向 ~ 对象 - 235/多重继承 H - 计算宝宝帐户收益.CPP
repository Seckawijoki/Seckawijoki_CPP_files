/*
题目描述
	定义一个类CPeople，具有身份号码(id,char[20])
和姓名(name,char[10])两个数据成员，
从CPeople类中再派生出CInternetUser类和CBankCustomer类，
然后再从CInternetUser和CBankCustomer多重继承派生出CInternetBankCustomer类。

	CInternetUser类有登录密码(password,char[20])属性
和注册register(设置id, name和password)，
登录login(判断输入的id与password是否与对象注册的相同)成员函数。

	CBankCustomer类有余额(balance,double)属性
和开户openAccount(设置客户姓名和id)，
存款deposit，取款withdraw以及缺省的构造函数。

	CInternetBankCustomer类包括有余额, 前一日余额, 当日收益，
今日万元收益和上一日万元收益等5个数据成员，
成员函数有缺省构造函数，存款和取款，设置万元收益，计算当日收益，
登陆login(判断输入的id和密码是否与互联网用户的相同，
同时从CBankCustomer继承的用户姓名和id要与从CInternetUser继承的相同)。

	CInternetBankCustomer类对象当日存款不计算收益，
第2天开始才能计算收益，当日取款部分无收益。

  可参照如下所示的主函数来测试并设计输入数据：

void main()
{
	int t, no_of_days, i;
	char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
	double money, interest;
	char op_code;
//输入测试案例数t
     cin >> t;
     while (t--)
     {
//输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;

//输入银行开户用户名,id
        cin >> b_xm >> b_id;

//输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;

 CInternetBankCustomer ib_user;
	ib_user.registerUser(i_xm, i_id, i_mm);
	ib_user.openAccount(b_xm, b_id);

    if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
    {
        cout << "Password or ID incorrect" << endl;
        continue;
    }
//输入天数
    cin >> no_of_days;
    for (i=0; i < no_of_days; i++)
    {
    //输入操作代码, 金额, 当日万元收益
        cin >> op_code >> money >> interest;
        switch (op_code)
        {
            case 'S':  //从银行向互联网金融帐户存入
            case 's':
               if (ib_user.deposit(money) == 0)
               {
                  cout << "Bank balance not enough" << endl;
                  continue;
               }
               break;
          case 'T':  //从互联网金融转入银行帐户
          case 't':
              if (ib_user.withdraw(money) == 0)
             {
                 cout << "Internet bank balance not enough" << endl;
                 continue;
             }
             break;
          case 'D':  //直接向银行帐户存款
          case 'd':
               ib_user.CBankCustomer::deposit(money);
              break;
          case 'W':  //直接从银行帐户取款
          case 'w':
               if (ib_user.CBankCustomer::withdraw(money) == 0)
              {
                    cout << "Bank balance not enough" << endl;
                   continue;
              }
              break;
          default:
                cout << "Illegal input" << endl;
               continue;
         }
          ib_user.setInterest(interest);
          ib_user.calculateProfit();
//输出用户名,id 
//输出银行余额
//输出互联网金融账户余额
          ib_user.print();
      }
   }
}

输入
输入用户例数

输入第1个互联网用户注册时的用户名,id,登陆密码

输入第1个用户银行开户用户名,id

输入第1个互联网用户登陆时的id,登陆密码

输入第1个用户操作天数

循环输入操作代码(S,T,D,W)  金额  当日万元收益
......

输出
输出第1个用户名,id 
输出第1个用户银行余额
输出第1个互联网金融账户余额
......

样例输入
2
zhangsan 1234567890 222222
zhangsan 1234567890
1234567890 222222
4
D 15000 0
s 8000 1.5
T 3000 1.55
w 2000 0
lisi 2014150000 abcdef
lisi 2014150000
2014150000 123456

样例输出
Name: zhangsan ID: 1234567890
Bank balance: 15000
Internet bank balance: 0

Name: zhangsan ID: 1234567890
Bank balance: 7000
Internet bank balance: 8000

Name: zhangsan ID: 1234567890
Bank balance: 10000
Internet bank balance: 5001.2

Name: zhangsan ID: 1234567890
Bank balance: 8000
Internet bank balance: 5001.98

Password or ID incorrect

*/
# include <iostream>
# include <cstring>
using namespace std;
class People
{
protected:
	char name[20];
	char id[10];
public:
	People()
	{
		name[0] = '\0';
		id[0] = '\0';
	}
	People( char *p_xm , char *p_id )
	{
		strcpy(name,p_xm);
		strcpy(id,p_id);
	}
};
class InternetUser:virtual public People
{
protected:
	char password[20];
public:
	InternetUser():People("?\0","?\0")
	{
		strcpy(password,"?\0");
	}
	InternetUser(char *i_xm, char *i_id, char *i_mm):People(i_xm,i_id)
	{
		strcpy(password,i_mm);
	}
	void Register(char *i_xm , char *i_id ,char *i_mm)
	{
		strcpy(id,i_id);
		strcpy(name,i_xm);
		strcpy(password,i_mm);
	}
	int Login( char *i_id , char *i_mm )
	{
		if (strcmp(password,i_mm) != 0 || strcmp(id,i_id) != 0)
			return 0;
	}
};
class BankCustomer:virtual public People
{
protected:
	double bankBalance;
public:
	BankCustomer():People("?\0","?\0")
	{
		bankBalance = 0;
	}
	BankCustomer(char *i_xm, char *i_id, double remainder):People(i_xm,i_id)
	{
		bankBalance = remainder;
	}
	void OpenAccount( char *b_xm, char *b_id )
	{
		strcpy(name,b_xm);
		strcpy(id,b_id);
	}
	void Deposit( double money )
	{
		bankBalance += money;
	}
	int Withdraw( double money )
	{
		if ( money <= bankBalance )
		{
			bankBalance -= money;
			return 1;
		}
		else
			return 0;
	}
};
class InternetBankCustomer:public InternetUser,public BankCustomer
{
protected:
	double balance;
	double thatDayDeposit;
	double thatDayWithdraw;
	double yesterdayBalance;
	double thatDayProfit;
	double todayProfit;
	double yesterdayProfit;
public:
	InternetBankCustomer():InternetUser("?\0","?\0","?\0"),BankCustomer("?\0","?\0",0)
	{
		balance = 0;
		thatDayDeposit = 0;
		thatDayWithdraw = 0;
		yesterdayBalance = 0;
		thatDayProfit = 0;
		todayProfit = 0;
		yesterdayProfit = 0;
	}
	InternetBankCustomer(char *i_xm, char *i_id, char *i_mm, double remainder, double yB, double tDP, double tP, double yP):InternetUser(i_xm,i_id,i_mm),BankCustomer(i_xm,i_id,remainder)
	{
		balance = remainder;
		thatDayDeposit = 0;
		thatDayWithdraw = 0;
		yesterdayBalance = yB;
		thatDayProfit = tDP;
		todayProfit = tP;
		yesterdayProfit = yP;
	}
	int Login( char *ib_id , char *ib_mm )
	{
		if (strcmp(ib_mm,InternetUser::password) == 0 &&
			strcmp(ib_id,InternetUser::id) == 0 &&
			strcmp(InternetUser::id,BankCustomer::id) == 0 &&
			strcmp(InternetUser::name,BankCustomer::name) == 0 )
			return 1;
		else
			return 0;
	}
	int Deposit( double money )
	{
		//从银行向互联网金融帐户存入
		if ( money <= bankBalance )
		{
			bankBalance -= money;
			balance += money;
			thatDayDeposit += money;
			return 1;
		}
		else
			return 0;
	}
	int Withdraw( double money )
	{
		//从互联网金融转入银行帐户
		if ( money <= balance )
		{
			bankBalance += money;
			balance -= money;
			thatDayWithdraw += money;
			return 1;
		}
		else
			return 0;
	}
	void SetInterest( double interest )
	{
		todayProfit = interest;
	}
	void CalculateProfit()
	{
		//当日存款不计算收益，
		//第2天开始才能计算收益，当日取款部分无收益。
		balance += yesterdayProfit;
		thatDayProfit = ( thatDayProfit * 10000 - thatDayDeposit - thatDayWithdraw )/10000;
		balance += thatDayProfit;
		yesterdayProfit = thatDayProfit;
		thatDayProfit = todayProfit;
	}
	void Display()
	{
		cout<<"Name: "<<name<<" ID: "<<id<<endl
			<<"Bank Balance: "<<bankBalance<<endl
			<<"Internet bank balance: "<<balance<<endl<<endl;
	}
};
void main()
{
	int t, no_of_days, i;
	char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
	double money, interest;
	char op_code;
	//输入测试案例数t
	cin >> t;
	while (t--)
	{
		//输入互联网用户注册时的用户名,id,登陆密码
        cin >> i_xm >> i_id >> i_mm;
		
		//输入银行开户用户名,id
        cin >> b_xm >> b_id;
		
		//输入互联网用户登陆时的id,登陆密码
        cin >> ib_id >> ib_mm;
		
		InternetBankCustomer ib_user;
		ib_user.Register(i_xm, i_id, i_mm);
		ib_user.OpenAccount(b_xm, b_id);
		
		if (ib_user.Login(ib_id, ib_mm) == 0)		
		{
			//互联网用户登陆,若id与密码不符;
			//以及银行开户姓名和id与互联网开户姓名和id不同
			cout << "Password or ID incorrect" << endl;
			continue;
		}
		//输入天数
		cin >> no_of_days;
		for (i=0; i < no_of_days; i++)
		{
			//输入操作代码, 金额, 当日万元收益
			cin >> op_code >> money >> interest;
			switch (op_code)
			{
            case 'S':  //从银行向互联网金融帐户存入
            case 's':
				if (ib_user.Deposit(money) == 0)
				{
					cout<<"Bank balance not enough"<<endl;
					continue;
				}
				break;
			case 'T':  //从互联网金融转入银行帐户
			case 't':
				if (ib_user.Withdraw(money) == 0)
				{
					cout<<"Internet bank balance not enough"<<endl;
					continue;
				}
				break;
			case 'D':  //直接向银行帐户存款
			case 'd':
				ib_user.BankCustomer::Deposit(money);
				break;
			case 'W':  //直接从银行帐户取款
			case 'w':
				if (ib_user.BankCustomer::Withdraw(money) == 0)
				{
                    cout<<"Bank balance not enough"<<endl;
					continue;
				}
				break;
			default:
                cout << "Illegal input" << endl;
				continue;
			}
			ib_user.SetInterest(interest);
			ib_user.CalculateProfit();
			//输出用户名,id 
			//输出银行余额
			//输出互联网金融账户余额
			ib_user.Display();
      }
   }
}