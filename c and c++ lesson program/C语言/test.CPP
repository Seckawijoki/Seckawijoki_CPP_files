/*#include <iostream.h>
void main()
{
	
	int add(int x,int y);
	int x,y,z;
	cin>>x>>y;
	z=add(x,y);
	cout<<"x+y="<<z;
}

int add(int x,int y)
{
	int z;
	z=x+y;
	return z;
}*/
//----------------------------------//
/*
# include <stdio.h>

int main(void)

{
	int a = 3 , b = 5;
	printf("a = %d , b = %%d",a,b);
	return 0;
}
*/
//---------------------------------//
/*
//# include <iostream.h>
# include <stdio.h>
void main()
//const int PI = 3.14;
#define PI 3.14
{ 
	float r;
//	cin>>r;
//	cout<<2*PI*r<<endl;
//	cout<<PI*r*r<<endl;
	scanf("%f",&r);
	printf("%f\n",2*PI*r);
	printf("%f\n",PI*r*r);
}
*/
//---------------------------------//
/*
# include <iostream.h>
# include <iomanip.h>

int main(void)

{
	float f;
	cin>>f;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<5*(f-32)/9<<endl;
	return 0;
}
*/
//---------------------------------//

/*
# include <stdio.h>
int main(void)
{
	int a,b;
	scanf("%d %d",&a,&b);
	if ( a > b)
	{
		printf("1\n");
	}
	else if ( a == b)
	{
		printf("0\n");
	}
	else if ( a < b)
	{
		printf("-1\n");
	}
	return 0;
}
*/
# include <stdio.h>

int main(void)

{
//	int x,y;
//	scanf("%2d %d",&x,&y);//输入两位数。
//	printf("%d %d\n",x,y);
	int i;
	char a[10][6]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	while (i = 1;i <= 6;i++)
		printf("%c\n",a[i][1]);
	return 0;
}