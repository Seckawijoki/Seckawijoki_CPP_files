/*3. ������һ��С��Ϸ�������֣�1~100�������ɼ�������롱һ������Ȼ���û����£�����´��ˣ������������ʾ�������û����µ�������̫����̫С�������Բ�10�Ρ������10�����ڲ¶��ˣ�����ܹ����˶��ٴΡ��������10����δ���еĻ�����ֹͣ���β�����Ȼ�������һ��������ÿ�����г�����Է����¶������ֱ���û���ֹͣʱ�Ž�������ѡ����*/

#include<iostream>
#include<cstdlib>
//#include<conio>
#include<ctime>
using namespace std;

int main()
{
	int magic; //��������롱����
	int guess;  //�û��µ���
	int counter;  //��¼����
	char reply;  //�û��������

	// Seed the random-number generator with the current time so that
   // the numbers will be different every time we run.
	srand ((unsigned)time(NULL));

	do 
	{
		magic=rand()%100+1;  //generate a random number;
		counter=0;
		do
		{
			cout<<"please guess a magic number: ";
			cin>>guess;
			counter++;
			if (guess>magic)
				cout<<"Wrong! Too high!\n";
			else if (guess<magic)
				     cout<<"Wrong! Too low!\n";
			     else
					 cout<<"Right!\n";
		}while (guess!=magic && counter<10); //�²�����δ����10��ʱ������

		cout<<"counter="<<counter<<endl;
		cout<<"Do you want to continue(Y/N or y/n)?";
		cin>>reply;
		cout<<"\n";
	}while (reply =='y'||reply =='Y');
	 cout<<"Game Over!\n";

	 return 0;
}
