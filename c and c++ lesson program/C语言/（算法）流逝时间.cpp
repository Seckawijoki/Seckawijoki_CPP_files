/*
Description
���㲢���ʱ��hh:mm:ss ������n������ʱ�䣬hh��mm��ss��n�Ӽ������롣

Input
���뵱ǰʱ��

���뾭��������n

Output
���n����ʱ��

Sample Input
12 58 58
121

Sample Output
13:0:59

*/
# include <iostream>
using namespace std;

int main()
{
	int hh,mm,ss,n;
	cin>>hh>>mm>>ss>>n;
/*	
-------------������if�Ĵ�ͳ������-------------
	ss = ss + n;
	if ( ss >= 60 )
	{
		mm = mm + ss / 60;
		ss = ss%60;
		if ( mm >= 60 )
		{
			hh = hh + mm / 60;
			mm = mm%60;
		}
	}
----------------------------------------------
	*/
	ss = ss + n;
	mm = mm + ss / 60;
	ss = ss %60;
	hh = hh + mm / 60;
	mm = mm %60;

	cout<<hh<<":"<<mm<<":"<<ss<<endl;
	return 0;
}

/*
	10�����ҵ��㷨����
	ȡ�̣�ֱ�ӳ���
*/