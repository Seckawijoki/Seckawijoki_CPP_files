/*
题目描述
完成下列分数类的实现:
class CFraction
{
private:
     int fz, fm;
public:
     void init(int fz_val, int fm_val) ;
     CFraction add(const CFraction &r);
     CFraction sub(const CFraction &r);
     CFraction mul(const CFraction &r);
     CFraction div(const CFraction &r);
     int getGCD(); // 求对象的分子和分母的最大公约数
     void print();
};

求两数a、b的最大公约数可采用辗转相除法，
又称欧几里得算法，其步骤为:

1. 交换a, b使a > b;
2. 用a除b得到余数r,若r=0,则b为最大公约数,退出.
3. 若r不为0,则用b代替a, r代替b,此时a,b都比上一次的小,问题规模缩小了;
4. 继续第2步。

输入
测试数据的组数 t
第一组第一个分数
第一组第二个分数

第二组第一个分数
第二组第二个分数
......

输出
第一组两个分数的和
第一组两个分数的差
第一组两个分数的积
第一组两个分数的商

第二组两个分数的和
第二组两个分数的差
第二组两个分数的积
第二组两个分数的商
......

样例输入
3
1/2
2/3
3/4
5/8
21/23
8/13
样例输出
7/6
-1/6
1/3
3/4

11/8
1/8
15/32
6/5

457/299
89/299
168/299
273/184
*/
# include <stdio.h>
class CFraction
{
private:
     int fz, fm;
public:
	CFraction()
	{
		fz = 1;
		fm = 1; 
	}
	int getFZ(){ return fz; }
	int getFM(){ return fm; }
	void setFZ( int x ){ fz = x ; }
	void setFM( int x ){ fm = x ; }
    void init(int fz_val, int fm_val)
	{
		fz = fz_val;
		 fm = fm_val;
	}
	CFraction add( const CFraction &r );
	CFraction sub( const CFraction &r );
	CFraction mul( const CFraction &r );
	CFraction div( const CFraction &r );
	int   getGCD( CFraction f );
	void display( CFraction f );
};
//类定义与类实现分开，注意参数。
CFraction CFraction::add( const CFraction &r )
{
	CFraction f;
	f.fz = fz * r.fm + fm * r.fz;
	f.fm = fm * r.fm;
	int gcd = f.getGCD(f);
	f.fz /= gcd;
	f.fm /= gcd;
	f.display(f);
	return f;
}
CFraction CFraction::sub( const CFraction &r )
{
	CFraction f;
	f.fz = fz * r.fm - fm * r.fz;
	f.fm = fm * r.fm;
	int gcd = f.getGCD(f);
	f.fz /= gcd;
	f.fm /= gcd;
	f.display(f);
	return f;
}
CFraction CFraction::mul( const CFraction &r )
{
	CFraction f;
	f.fz = fz * r.fz;
	f.fm = fm * r.fm;
	int gcd = f.getGCD(f);
	f.fz /= gcd;
	f.fm /= gcd;
	f.display(f);
	return f;
}
CFraction CFraction::div( const CFraction &r )
{
	CFraction f;
	f.fz = fz * r.fm;
	f.fm = fm * r.fz;
	int gcd = f.getGCD(f);
	f.fz /= gcd;
	f.fm /= gcd;
	f.display(f);
	return f;
}
int CFraction::getGCD( CFraction f )//求对象的分子和分母的最大公约数
{
	int f1 = f.getFZ(),f2 = f.getFM();
	/*=====此法不需比较大小
	if ( f1 < f2 )
	{
		f1 = f2 + f1;
		f2 = f2 - f1;
		f1 = f2 - f1;
	}
	=====第一次求解已交换*/
	int r = 1;
	while ( r )
	{
		r  = f1 %f2;
		f1 = f2;
		f2 = r;		
	}
//	printf("最大公约数 = %d\n",f1);
	return f1;
}
void CFraction::display( CFraction f )
{
	int f1 = f.getFZ(),f2 = f.getFM();
	if ( f1 < 0 && f2 < 0 )
	{
		f1 = -f1;
		f2 = -f2;
	}
	printf("%d/%d\n",f1,f2);
}
int main()
{
	int fz1,fm1,fz2,fm2;
	int t;
	scanf("%d",&t);
	CFraction ff1;
	CFraction ff2;
	while ( t-- )
	{
		scanf("%d/%d",&fz1,&fm1);
		scanf("%d/%d",&fz2,&fm2);
		ff1.init(fz1,fm1);
		ff2.init(fz2,fm2);
		ff1.add(ff2);
		ff1.sub(ff2);
		ff1.mul(ff2);
		ff1.div(ff2);
		printf("\n");
	}
	return 0;
}