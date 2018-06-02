#include <iostream>
#include <string>
using namespace std;
void substr(void);
int main()
{
	substr();
	return 0;
}
void substr(void)
{
	int i,j,h,k;
	char str1[33];
	char str2[33];
	int index;
	cin>>k;
	while (k--)
	{
		getchar();
		gets(str1);
		cin>>index;
		h=strlen(str1);
		if (index<0||index>=h)
		{
			cout<<"IndexError\n";
			continue;
		}
		else 			
		for(i=0;i<=(h-index+1);i++)
			str2[i]=str1[index+i];
		cout<<str2<<endl;
	}
}