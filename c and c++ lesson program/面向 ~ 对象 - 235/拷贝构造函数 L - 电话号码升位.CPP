/*
题目描述
定义一个电话号码类CTelNumber，
包含1个字符指针数据成员，以及构造、析构、打印及拷贝构造函数。
字符指针是用于动态创建一个字符数组，然后保存外来输入的电话号码。

构造函数的功能是为对象设置键盘输入的7位电话号码，
拷贝构造函数的功能是用原来7位号码的对象升位为8位号码对象，
也就是说拷贝构造的对象是源对象的升级。

电话升位的规则是原2、3、4开头的电话号码前面加8，
原5、6、7、8开头的前面加2。

注意:电话号码只能全部是数字字符，
且与上述情况不符的输入均为非法。

输入
测试数据的组数 t
第一个7位号码
第二个7位号码
......

输出
第一个号码升位后的号码
第二个号码升位后的号码
......
如果号码升级不成功，则输出报错信息，具体看示例

样例输入
3
6545889
3335656
565655
样例输出
26545889
83335656
Illegal phone number
*/
# include <stdio.h>
# include <string.h>
class Denwabango
{
private:
	char *bango;
public:
	Denwabango()
	{
		bango = new char [12];
	}
	Denwabango( char *number )
	{	
		bango = new char [strlen(number)+5]; 
		strcpy(bango,number);
	}
	Denwabango( const Denwabango &bg )
	{
		bango = new char [strlen(bg.bango)+5]; 
		strcpy(bango,bg.bango);
	}
	~Denwabango()
	{
		delete [] bango;
	}
	void Miseru()
	{
		printf("%s\n",bango);
	}
	void Ushiro()
	{	
		int i;
		//老越界的i++问题= =！
		for ( i = strlen(bango) ; i >= 0 ; i -- )//差了第一位，没有后置完。
			bango[i+1] = bango[i];
	}
	void Upgrade()
	{
		if ( strlen(bango) != 7 || bango[0] == '0'|| bango[0] == '1'|| bango[0] == '9' )
			//开头不能是0,1,9
			printf("Illegal phone number\n");
		else//原来没有判断非数字。
		{
			int i,DenwaBangoDeSu = 1;
			for ( i = 0 ; i < 7 ; i++ )
				if ( bango[i] < '0' || bango[i] > '9' )
				{
				
					DenwaBangoDeSu--;
					break;
				}
			if ( DenwaBangoDeSu == 0 )
				printf("Illegal phone number\n");
			else
			{
				switch ( bango[0] ) 
				{
				case '2': 
				case '3': 
				case '4': {Ushiro();bango[0] = '8';break;}
				case '5': 
				case '6': 
				case '7': 
				case '8': {Ushiro();bango[0] = '2';break;}
				default :break;
				}
				/*
					 if (   bango[0] == '2' ||
							bango[0] == '3' ||
							bango[0] == '4')
				{
					Ushiro();
					bango[0] = '8';
				}
				else if (	bango[0] == '5' ||
							bango[0] == '6' ||
							bango[0] == '7' ||
							bango[0] == '8' )
				{
					Ushiro();
					bango[0] = '2';
				}
				*/
				bango[8] = '\0';
				Miseru();
			}
		}
	}
};
int main()
{
	int t;
	char number[11];
	scanf("%d",&t);
	getchar();
	while ( t-- )
	{
		scanf("%s",number);
		Denwabango bg(number);
		bg.Upgrade();
	}
	return 0;
}