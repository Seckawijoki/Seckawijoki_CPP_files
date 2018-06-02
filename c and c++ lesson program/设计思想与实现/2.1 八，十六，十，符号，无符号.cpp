# include <iostream.h>

int main()

{
	int i = 42486;
	cout<<"  八进制："<<oct<<i<<endl;//  八进制:octal
	cout<<"十六进制："<<hex<<i<<endl;//十六进制:hexadecimal
	cout<<"  十进制："<<dec<<i<<endl;//  十进制:decimal
	cout<<unsigned short int(i)<<endl;//原int默认模式。
	cout<<signed short int(i)<<endl;

	return 0;
}