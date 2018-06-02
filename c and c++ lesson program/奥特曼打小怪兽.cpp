#include <iostream>
using namespace std;
class Monster;
class Boss;
class Ultraman{
private:
	int rank;
	double hp, damage, exp, money;
public:
	Ultraman(int r):rank(r),hp(10*r),damage(3*r),money(10*r),exp(0){}
	int getrank(){return rank;}
	double gethp(){return hp;}
	double getdamage(){return damage;}
	double getexp(){return exp;}
	double getmoney(){return money;}
	void escape();
	void attacked(Monster& obj);
	void restore();
	void win(Monster& obj);
	void upgrade();
	void display();
	
};

class Monster{
protected:
	int rank, count;
	double hp, damage, exp, money;
public:
	Monster():rank(10),hp(300),damage(50),exp(1000),money(1001),count(0){}
	Monster(int r):rank(r),hp(20*rank),damage(2*rank),money(10*rank),exp(10*rank){}
	int getrank(){return rank;}
	double gethp(){return hp;}
	double getdamage(){return damage;}
	double getexp(){return exp;}
	double getmoney(){return money;}
	void attacked(Ultraman& obj);
	void setrank(int r){rank = r;}
};


class Boss:public Monster{
public:
	Boss():Monster(){}
	Boss(int r):Monster(r){}
	void XP( Ultraman& obj1, Boss& obj2)
	{
		obj1.attacked (obj2);
		obj1.attacked (obj2);
		obj1.attacked (obj2);
	}
	void fightback(Ultraman& obj1, Boss& obj2)
	{
		if(count<5)
		{
			obj1.attacked(obj2);
			if(obj1.gethp ()>10)
				obj1.restore ();
		}
		else
			XP(obj1, obj2);
	}
	void display ()
	{
		cout<<"boss״̬(rank="<<rank<<" hp="<<hp<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;	
	}
};


void Ultraman::escape ()
{
	money = 0;
}

void Ultraman::attacked (Monster& obj)
{
	hp = hp - (int)(obj.getdamage() / 2);
	if(hp<0)
		hp = 0;
}
void Ultraman::restore ()
{
	int t;
	
	t = money / 10;
	if(money>=10&&hp<5*rank)
	{
		if( hp+t < 10*rank )
		{
			hp = hp + t;
			money = money - 10*t;
		}
		else
		{
			t = 10*rank - hp ;
			hp = 10*rank;
			money = money - 10*t;
		}
	}
	
}

void Ultraman::win (Monster& obj)
{
	if(obj.gethp () <= 0)
	{
		money = money + obj.getmoney ();
		exp = exp + obj.getexp ();
	}
}

void Ultraman::upgrade ()
{
	if(exp >= 10*rank)
	{
		exp = exp - 10*rank;
		rank ++;
		hp = 10*rank;
		damage = 3*rank;
	}
}

void Ultraman::display ()
{
	cout<<"������״̬(rank="<<rank<<" hp="<<hp<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;
	
	
}


void Monster::attacked (Ultraman& obj)
{
	hp = hp - obj.getdamage () ;
	count ++;
	if ( hp < 0 )hp = 0;
}


int main()
{
	int t, ur, mr, n;
	char flag;
	
	cin>>t;
	while(t--)
	{
		cin>>ur;
		Ultraman man(ur);
		man.display ();
		cin>>n>>mr;
		
		while(n--)
		{
			Monster mon(mr);
			flag  = true;
			while(flag)//û��û�ӣ����������
			{
				mon.attacked(man);
				if(mon.gethp()>0)
				{
					man.attacked(mon);
					if(man.gethp ()>10)
						man.restore ();
					else
					{
						man.escape ();
						cout<<"lose"<<endl;
						//man.display ();
						flag = false;
					}
				}
				else
				{
					man.win(mon);
					cout<<"win"<<endl;
					man.upgrade ();
					flag = false;
				}
				
			}
		}
		
		
		if( man.gethp() > 10)
		{
			man.display();
			Boss boss;
			
			flag = true;
			while(flag)
			{
				boss.attacked(man);
				man.display();
				boss.display(); 
				if(boss.gethp()>0)
				{
					boss.fightback(man,boss);
					
					if(man.gethp()>10.0)
						man.restore();
					else
					{
						man.escape ();
						cout<<"lose"<<endl;
						man.display ();
						flag = false;
					}
				}
				
				else
				{
					man.win(boss); 
					cout<<"win Boss"<<endl;
					man.upgrade ();
					man.display ();
					flag = false;
				}
			}
		}
	}
	return 0;
}

//if(man.gethp()<0.5*man.getrank()*10)
/*
��������
2
5
5 5
20
5 10
�������
������״̬(rank=5 hp=50 damage=15 exp=0 money=50)
win
win
win
win
win
������״̬(rank=8 hp=60 damage=24 exp=70 money=150)
lose
������״̬(rank=8 hp=0 damage=24 exp=70 money=0)
������״̬(rank=20 hp=200 damage=60 exp=0 money=200)
win
win
win
win
win
������״̬(rank=22 hp=220 damage=66 exp=90 money=700)
win Boss
������״̬(rank=26 hp=260 damage=78 exp=150 money=1701)

������֯���޸�ǰ��Ĵ��룬���ü̳�ʵ���������ݡ�
������������С���޹��еĹ����У����������Լ��ĵȼ���
��һ�о�����ʱ�򣬾Ϳ�����սС���޵�ͷBoss�ˡ����Boss�Ϳ��Ի�����յ�ʤ����

�ڹ�����Ļ����ϣ������ʵ��һ������Boss�ࡣ
���б�Ҫ����԰������͹�����������Ӧ���޸ġ�

Boss��Թ����������������޸ģ�

<!--[if !supportLists]-->l  <!--[endif]-->Boss���Ե�
��ʼֵ��һ����޲�ͬ���ȼ�Ϊ10������ֵΪ300������ֵ��1000����������50��Ǯ����1001��

<!--[if !supportLists]-->l  <!--[endif]-->Boss��
һ���µķ�����������(XP)���÷�������������������3�Ρ�

<!--[if !supportLists]-->l  <!--[endif]-->Boss��
��������(fightback)Ҳ��һ����޲�ͬ��һ��������ܵ��������Ĺ����ͻᷴ��һ�Σ�
��ÿ��Boss�ܵ������������Ĵ���(count)�ۼ�5�Σ��ͻ�ʹ�þ���(XP)��

*******************************************************************************

Outman��������������ڴ�����е�С���޺󣬽���ս����֮����
����main������ʵ�����¼ܹ�
int main(){
    //������Դ���
    while(t--){
//����������ĵȼ�ֵ�����õȼ�ֵ������һ��������������ʾ�����������ʼ״̬��
//������޸����͵ȼ�
	    while(��������)//ֻҪ������û��Ҳû���ܣ��ͼ�����n�����޵�ս��
	    {
	         ���ù��޵ȼ�ֵ���ɹ��޶���
	         //����ս����־flagΪtrue������ս��ѭ�����������£�
	         while(flag) //��ս��δ�����ͼ���
	         {   
	             //����������1��
	             if (��������)  //����û��
	             {   //���޷���1��
	                  if (������)       //������û��Ҳ������
	                      //��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
	                  else 
	                  {   //���������ܣ������"lose"���س�
	                      //���������״̬������display����
	                      //����flagΪfalse��ֹͣս��
	                  }
	             }
	             else //��������
	             {   
	                  //������ʤ���������"win"���س�
	                  //����������
	                  //����flagΪfalse��ֹͣս��
	             }
	         }
	    }
	    if(��������)//�������n��С���ް�������û��Ҳû���ܣ�����սBoss
	    {
	         //�����������ǰ״̬
	         //����Boss�����ʼ��
			 //����ս����־flagΪtrue������ս��ѭ�����������£�
	         while(flag) //��ս��δ�����ͼ���
	         {   
	             //����������1��
	             if (��������)  //Bossû��
	             {   //Boss����1��
	                  if (������)       //������û��Ҳ������
	                      //��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
				      else 
	                  {   //���������ܣ������"lose"���س�
	                      //���������״̬������display����
	                      //����flagΪfalse��ֹͣս��
	                  }
	             }
	             else //��������
	             {   
	                  //������ʤ���������"win Boss"���س�
	                  //����������
	                  //���������״̬������display����
	                  //����flagΪfalse��ֹͣս��
	             }
	         }
	    }
    }
    return 0;
}

����
��1������t��ʾ��t������ʵ��
����ÿ������ʵ��������������������ȼ�
������һ������n��k����ʾ���������͵ȼ�

���
���ÿ������ʵ����ս�������
����ÿһ��ʵ����������£�
��һ�а�������״̬
�ڶ���~��n+1�����������������ÿ�����޵Ľ����
�����������n�����޶�����ˣ�
     ��n+2�������ʱ��������״̬
     ��n+3��������������������Ľ��
     ��n+4����������������������״̬
�����������ĳ�����޴�ܣ������ս���������һ�����ս�����������״̬������������������ս
*/ 
