/*
籾朕宙峰
協吶匯倖眉叔侘窃CTriangle��奉來淫根眉訳円��中持��
喘強蓑方怏燕幣議眉叔侘窃侏(吉劈、吉円、岷叔、匯違眉叔侘)。
佩葎淫凄更夛��裂更痕方��
登僅嬬倦更撹眉叔侘參式凪窃侏議痕方��柴麻中持議痕方吉。
隼朔園亟匯倖麼痕方,霞編侭協吶議CTriangle窃。

補秘
霞編方象議怏方
及匯怏円1 及匯怏円2 及匯怏円3
及屈怏円1 及屈怏円2 及屈怏円3
......

補竃
及匯倖眉叔侘窃侏��中持
及屈倖眉叔侘窃侏��中持
......

劔箭補秘
3
3.0 2.0 6.0
3.0 4.0 5.0
1.0 1.0 1.414
劔箭補竃
No triangle
right triangle, 6
isosceles right triangle, 0.5
*/
# include <iostream>
# include <cstring>
# include <cmath>
using namespace std;
class Sankakkei//眉叔侘��triangle,眉叔侘�┐気鵑�っけい��
{
private:
	double a;//円海��side,�x(あたり)
	double b;
	double c;
	double menseki;//中持��area,中�e(めんせき)
	char *taipu;
public:
	Sankakkei()
	{
		a = 0;
		b = 0;
		c = 0;
		menseki = 0;
	}
	Sankakkei( double x , double y , double z )
	{
		a = x;
		b = y;
		c = z;
	}
	void OkuAtari( double x , double y , double z )
	{
		a = x;
		b = y;
		c = z;
	}
	void SankakkeiNoTaipu()
	{
		taipu = new char [33];
		if ( a + b > c && a + c > b && b + c > a )
		{
			if ( a == b && a == c  )
				strcpy(taipu,"equilateral triangle\0");
			else
			{
				if ( a == b && a != c || a == c && a != b || b == c && b != a )
				{
					if ( fabs(a*a + b*b - c*c) < 1e-3 || fabs(a*a + c*c - b*b) < 1e-3 || fabs(b*b + c*c - a*a) < 1e-3 ) 
						//秀咏喘曾宀餓議蒸斤峙弌噐10議-3肝圭��弌噐0.001潮範岷叔眉叔侘。
						strcpy(taipu,"isosceles right triangle\0");
					else 
						strcpy(taipu,"isosceles triangle\0");
				}
				else
				{
					if ( fabs(a*a + b*b - c*c) < 1e-3 || fabs(a*a + c*c - b*b) < 1e-3 || fabs(b*b + c*c - a*a) < 1e-3 ) 
						strcpy(taipu,"right triangle\0");
					else 
						strcpy(taipu,"normal triangle\0");

				}
			}
		}
		else
			strcpy(taipu,"No triangle\0");
	}
	void KeisanMenseki()//柴麻��calculate,��麻(けいさん)
	{
		if ( strcmp(taipu,"No triangle\0") == 0 )
			menseki = 0;
		else
		{
			double p = ( a + b + c ) / 2;
			menseki = sqrt(p*(p-a)*(p-b)*(p-c));
		}
	}
	void MiseruTaipu()
	{
		if ( menseki == 0 )
			cout<<taipu<<endl;
		else
			cout<<taipu<<", "<<menseki<<endl;
			//喘C++宴噐補竃屎械弌方。
	}

};
int main()
{
	int t;
	double x,y,z;
	cin>>t;
	while ( t-- )
	{
		cin>>x>>y>>z;
		Sankakkei triangle(x,y,z);
		triangle.SankakkeiNoTaipu();
		triangle.KeisanMenseki();
		triangle.MiseruTaipu();
	}
	return 0;
}