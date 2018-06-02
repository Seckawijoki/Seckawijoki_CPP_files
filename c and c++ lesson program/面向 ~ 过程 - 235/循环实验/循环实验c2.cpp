/* 2. 某学校有思维同学中的一位做了好事，不留名，表扬信来了之后，校长问这四位是谁做的好事。四个人的回答分别是：
A说：不是我
B说：是C
C说：是D
D说：C胡说。
已知三人说的是真话，一个人说的是假话，现在编程求出做好事的到底是谁？ */

#include<iostream>
using namespace std;
 int main()
 {
	 int k=0, sum=0, g=0;
	 char thisman;
	 
	 for (k=0;k<=3;k++)
	 {
		 thisman='A'+k;
		 sum=(thisman!='A')+(thisman=='C')+(thisman=='D')+(thisman!='D');
		 if (sum==3)
		 {
			 cout<<"This man is "<<thisman<<endl;
			 g=1;
		 }
	 }
	 if (g!=1)
		 cout<<"can not find\n";

	 return 0;
 }

