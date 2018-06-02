/*3. 编程设计一个小游戏，猜数字（1~100）。先由计算机“想”一个数，然后用户来猜，如果猜错了，计算机给出提示：告诉用户所猜的数字是太大还是太小，最多可以猜10次。如果在10次以内猜对了，输出总共猜了多少次。如果猜了10次仍未猜中的话，则停止本次猜数，然后继续下一个猜数。每次运行程序可以反复猜多个数，直到用户想停止时才结束。（选做）*/

#include<iostream>
#include<cstdlib>
//#include<conio>
#include<ctime>
using namespace std;

int main()
{
	int magic; //计算机“想”的数
	int guess;  //用户猜的数
	int counter;  //记录次数
	char reply;  //用户输入的数

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
		}while (guess!=magic && counter<10); //猜不对且未超过10次时继续猜

		cout<<"counter="<<counter<<endl;
		cout<<"Do you want to continue(Y/N or y/n)?";
		cin>>reply;
		cout<<"\n";
	}while (reply =='y'||reply =='Y');
	 cout<<"Game Over!\n";

	 return 0;
}
