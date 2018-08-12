/*
��Ŀ����
����һ����ά��Point�࣬������Ԫ��������"++"��"--"�������
�������������������ǰ�úͺ������㡣

Ҫ�����£�
1.ʵ��Point�ࣻ
2.��дmain��������ʼ��1��Point����
���������++��--�󸳸�����һ������
��������������������Ϣ��

����
��1�У���������int���͵�ֵ���ֱ�Ϊһ��Point����p1��x,y,z���ꡣ

���
��1�У�Point����p1����++֮���������Ϣ�����
��2�У�Point����p1����++������
	   ��������һ��Point����p2��������Ϣ��
��3�п�ʼ���������ǰ��++������--��ǰ��--�����������Ϣ��
           �����ʽ�����++һ����
��������
10 20 30

�������
x=11 y=21 z=31
x=10 y=20 z=30
x=11 y=21 z=31
x=11 y=21 z=31
x=9 y=19 z=29
x=10 y=20 z=30
x=9 y=19 z=29
x=9 y=19 z=29
*/
# include <iostream>
using namespace std;
class SpacePoint;
SpacePoint operator ++ ( SpacePoint & );
SpacePoint operator ++ ( SpacePoint & , int );
SpacePoint operator -- ( SpacePoint & );
SpacePoint operator -- ( SpacePoint & , int );
class SpacePoint
{
private:
	double x;
	double y;
	double z;
public:
	SpacePoint( double a = 0, double b = 0, double c = 0 )
	{
		x = a;
		y = b;
		z = c;
	}
	
	void Display()
	{
		cout<< "x="<<x
			<<" y="<<y
			<<" z="<<z<<endl;
	}
	friend SpacePoint operator ++ ( SpacePoint & );
	friend SpacePoint operator ++ ( SpacePoint & , int );
	friend SpacePoint operator -- ( SpacePoint & );
	friend SpacePoint operator -- ( SpacePoint & , int );
	SpacePoint operator =  ( SpacePoint &q )
	{
		x = q.x;
		y = q.y;
		z = q.z;
		return *this;
	}
};
SpacePoint operator ++ ( SpacePoint &p )
{
	p.x++;
	p.y++;
	p.z++;
	return p;
}
SpacePoint operator ++ ( SpacePoint &p , int )
{
	SpacePoint q;
	q.x = p.x;
	q.y = p.y;
	q.z = p.z;
	p.x++;
	p.y++;
	p.z++;
	return q;
}
SpacePoint operator -- ( SpacePoint &p )
{
	p.x--;
	p.y--;
	p.z--;
	return p;
}
SpacePoint operator -- ( SpacePoint &p , int )
{
	SpacePoint q;
	q.x = p.x;
	q.y = p.y;
	q.z = p.z;
	p.x--;
	p.y--;
	p.z--;
	return q;
}
int main()
{
	double a,b,c;
	cin>>a>>b>>c;
	SpacePoint p1(a,b,c),p2;

	(++p1).Display();
	--p1;
	p2 = p1;
	cout<<"&p1 = "<<&p1<<endl;
	cout<<"&p2 = "<<&p2<<endl;
	(p2).Display();

	(++p2).Display();
	(p2--).Display();
	(--p2).Display();

	(++p2).Display();
	(--p2).Display();
	(p2--).Display();
	return 0;
}