# include <iostream.h>

int main()

{
	int i = 42486;
	cout<<"  �˽��ƣ�"<<oct<<i<<endl;//  �˽���:octal
	cout<<"ʮ�����ƣ�"<<hex<<i<<endl;//ʮ������:hexadecimal
	cout<<"  ʮ���ƣ�"<<dec<<i<<endl;//  ʮ����:decimal
	cout<<unsigned short int(i)<<endl;//ԭintĬ��ģʽ��
	cout<<signed short int(i)<<endl;

	return 0;
}