/* 2. ĳѧУ��˼άͬѧ�е�һλ���˺��£�������������������֮��У��������λ��˭���ĺ��¡��ĸ��˵Ļش�ֱ��ǣ�
A˵��������
B˵����C
C˵����D
D˵��C��˵��
��֪����˵�����滰��һ����˵���Ǽٻ������ڱ����������µĵ�����˭�� */

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

