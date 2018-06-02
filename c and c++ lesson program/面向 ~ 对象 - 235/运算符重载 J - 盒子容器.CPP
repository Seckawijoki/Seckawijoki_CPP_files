/*
题目描述
定义盒子容器类，包含4个成员：编号、长、宽、高，
(长大于等于宽)且该盒子容积就为它的体积，
现向每个盒子容器里面倒满水，重定义“-”运算符，
实现求出一个盒子放入另一个盒子容器内溢出来水的体积，
并输入溢出水最多的两个盒子容器的编号以及溢出水的体积
(温馨提示：不一定就是两个体积相减)。
盒子容器类的基本形式如下：
class BoxContent
{
private:
	string num;
	int length;
	int width;
	int height;
	…
}

输入
第一行输入圆柱体的个数
第二行开始依次输入每个圆柱体的编号、长、宽、高

输出
溢出水最多的两个圆柱体容器的编号以及溢出水的体积

样例输入
3
01 10 10 12
02 12 9 8
03 12 10 8

样例输出
02盒子放入03盒子溢出的水最多，为864。
*/
# include <iostream>
# include <string>
using namespace std;
class BoxContent;
int operator - ( BoxContent & , BoxContent & );
class BoxContent
{
private:
	string number;
	int length;
	int width;
	int height;
public:
	BoxContent()
	{
		length = 0;
		width = 0;
		height = 0;
	}
	BoxContent( string n, int l, int w, int h )
	{
		number = n;
		length = l;
		width = w;
		height = h;
	}
	string GetNumber()
	{
		return number;
	}
	void SetLengthWidthHeight( string n, int l, int w, int h )
	{
		number = n;
		length = l;
		width = w;
		height = h;
	}
	friend int operator - ( BoxContent & , BoxContent & );
	friend int minimum( int , int );
};
int operator - ( BoxContent &c1 , BoxContent &c2 )
{
	if ( c1.length > c2.length || c1.width > c2.width )
		return 0;
	else
	{
		if ( c1.height < c2.height )
			return c1.length * c1.width * c1.height;
		else
			return c1.length * c1.width * c2.height;
	}
}
int main()
{
	int t,l,w,h,i,j;
	int max = 0, x = 0, y = 1;
	int volume[11][11];
	char n[11];
	BoxContent *box;
	cin>>t;
	box = new BoxContent [t];
	for ( i = 0 ; i < t ; i++ )
	{
		cin>>n>>l>>w>>h;
		box[i].SetLengthWidthHeight(n,l,w,h);
	}
	for ( i = 0 ; i < t ; i++ )
		for ( j = 0 ; j < t ; j++ )
		{
			if ( i == j )
				continue;
			volume[i][j] = box[i] - box[j];
		//	cout<<"volume["<<i+1<<"]["<<j+1<<"] = "<<volume[i][j]<<endl;
		}
	max = 0;
	for ( i = 0 ; i < t ; i++ )
		for ( j = 0 ; j < t ; j++ )
		{
			if ( i == j )
				continue;
			if ( max < volume[i][j] )
			{
				max = volume[i][j];
				x = i;
				y = j;
			}
		}
	cout<<box[x].GetNumber()<<"盒子放入"<<box[y].GetNumber()<<"盒子溢出的水最多，为"<<max<<"。\n";
	delete [] box;
	return 0;
}