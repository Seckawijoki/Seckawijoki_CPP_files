/*
��Ŀ����
��дһ�������࣬��ʵ�ּӡ������㣬�������������Ϣ��
Ҫ�����ٰ������·�����
1��ȱʡ���޲Σ����캯��������ʵ�����鲿Ϊ1��
2���вι��캯������ʵ�����鲿��ֵ��
3���ӷ����㣬�������������ĺͣ�
4���������㣬�������������Ĳ
5����������������ǰ������ֵ

����
�������ݵ�����t 
��һ�������������ʵ�� �鲿 ʵ�� �鲿
�ڶ��������������ʵ�� �鲿 ʵ�� �鲿 
...... 

���
��һ�����������ĺ� 
��һ�����������Ĳ� 

��������
4
2 1 2 1
2 1 2 -1
3 1 2 -6
3 3 2 2

�������
sum:4+2i
remainder:0
sum:4
remainder:2i
sum:5-5i
remainder:1+7i
sum:5+5i
remainder:1+i
*/
# include <stdio.h>
class Complex
{
private:
     int a , b;
public:
	Complex()				{a = 1;b = 1;}
	Complex( int m , int n ){a = m;b = n;}
	Complex add( Complex &r )
	{
		Complex sum;
		sum.a = a + r.a;
		sum.b = b + r.b;
		sum.add_display(sum);
		return sum;
	}
	Complex sub( Complex &r )
	{
		Complex remainder;
		remainder.a = a - r.a;
		remainder.b = b - r.b;
		remainder.sub_display(remainder);
		return remainder;
	}
    void add_display( Complex &rr )
	{
		     if ( rr.a == 0 )
		{
			//����ʵ����0���鲿��0��+1��-1��
			     if ( rr.b ==  0 )
				printf("sum:0\n");
			else if ( rr.b ==  1 )
				printf("sum:i\n");
			else if ( rr.b == -1 )
				printf("sum:-i\n");
			else if ( rr.b <   0 )
				printf("sum:-%di\n",-rr.b);
			else if ( rr.b >   0 )
				printf("sum:%di\n", rr.b);
		}
		else if ( rr.a != 0 )
		{
			     if ( rr.b == 0 )
				printf("sum:%d\n",rr.a);
			else if ( rr.b ==  1 )
				printf("sum:%d+i\n",rr.a);
			else if ( rr.b == -1 )
				printf("sum:%d-i\n",rr.a);
			else if ( rr.b <  0 )
				printf("sum:%d-%di\n",rr.a,-rr.b);
			else if ( rr.b >  0 )
				printf("sum:%d+%di\n",rr.a, rr.b);
		}
	}
	void sub_display( Complex &rr )
	{
		     if ( rr.a == 0 )
		{
			     if ( rr.b ==  0 )
				printf("remainder:0\n");
			else if ( rr.b ==  1 )
				printf("remainder:i\n");
			else if ( rr.b == -1 )
				printf("remainder:-i\n");
			else if ( rr.b <   0 )
				printf("remainder:-%di\n",-rr.b);
			else if ( rr.b >   0 )
				printf("remainder:%di\n", rr.b);
		}
		else if ( rr.a != 0 )
		{
			     if ( rr.b == 0 )
				printf("remainder:%d\n",rr.a);
			else if ( rr.b ==  1 )
				printf("remainder:%d+i\n",rr.a);
			else if ( rr.b == -1 )
				printf("remainder:%d-i\n",rr.a);
			else if ( rr.b <  0 )
				printf("remainder:%d-%di\n",rr.a,-rr.b);
			else if ( rr.b >  0 )
				printf("remainder:%d+%di\n",rr.a, rr.b);
		}
	}
};
int main()
{
	int a,b,c,d;
	int t;
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		Complex z1(a,b);
		Complex z2(c,d);
		z1.add(z2);
		z1.sub(z2);
	}
	return 0;
}