/*
籾朕宙峰
念中叱祇膳楼��浩柴寄社脅頁委侭嗤旗鷹慧壓匯倖猟周戦匯軟糞�孱�
宸匆祥頁厘断傍議窃議順中才窃議糞�嶌篭�葎匯議圭塀��
斤噐玉弌議殻會栖傍丼楕頁音危議��徽頁斤噐熟寄議�酊神緩毅�
音旋噐辛響來��壓＾峺寞斤�鸛系亜瓜�粥貧��
壓VC桟廠和厘断委圻栖議殻會蛍撹曾何蛍��匯倖頁順中��.h猟周����
匯倖頁糞�孱�.cpp猟周����輝隼��葎阻才OJ桟廠匯崑��
壓匯倖殻會潤更戦��俶勣委窃順中才窃糞�嶬斷燦�猟周戦蛍蝕曾何蛍栖糞�孱�
云籾議児云勣箔才＾峺寞斤�鵝衛姿���率匯勣箔音揖議頁殻會議潤更音匯崑��
答個議炎彈頁壓潤惚屎鳩児粥貧斤孚心戻住議圻兵殻會旗鷹��

補秘
及匯佩補秘n倖斤�麒祇�
朔中光佩卆肝補秘斤�鶺銚�奉來

補竃
耽佩補竃将狛電會朔斤�鶺槻嫦�奉來

劔箭補秘
2
Bob 槻 2012222222 柴麻字僥垪 13777777777
Alice 溺 2013333333 柴麻字僥垪 13888888888

劔箭補竃
Alice
Bob
*/
# include <iostream>
# include <string>//緩遊猟周喘噐幹秀string窃侏
using namespace std;
class Gakusei
{
private:
	string namae;
	string seibetsu;//來艶��sex,來艶(せいべつ)
	string bango;
	string gakuin;//僥垪��sex,僥垪(がくいん)
	string denwa;
public:
	Gakusei()
	{
		namae = "No name\0";
		seibetsu = "Unknown\0";
		bango = "0000000000\0";
		gakuin = "Unknown\0";
		denwa = "00000000000\0";
	}
	Gakusei(string name,string sex,string number,string academy,string phone)
	{
		namae = name;
		seibetsu = sex;
		bango = number;
		gakuin = academy;
		denwa = phone;
	}
	void Toru(string name,string sex,string number,string academy,string phone)
	{
		namae = name;
		seibetsu = sex;
		bango = number;
		gakuin = academy;
		denwa = phone;
	}
	Gakusei( Gakusei &copy )
	{
		namae = copy.namae;
		seibetsu = copy.seibetsu;
		bango = copy.bango;
		gakuin = copy.gakuin;
		denwa = copy.denwa;
	}
	void Ranking( Gakusei &rgks );
	void Miseru();
};
void Gakusei::Ranking( Gakusei &rgks )
{
	Gakusei kopii;
	if ( namae[0] > rgks.namae[0] )
	{
		kopii = rgks;
		rgks.Toru(namae,seibetsu,bango,gakuin,denwa);
			namae = kopii.namae;
			seibetsu = kopii.seibetsu;
			bango = kopii.bango;
			gakuin = kopii.gakuin;
			denwa = kopii.denwa;
	}
}
void Gakusei::Miseru()
{
	cout<<namae<<endl;
}
int main()
{
	int i,j,t;
	string name,sex,number,academy,phone;
	cin>>t;
	Gakusei *student;
	student = new Gakusei [t];
	for ( i = 0 ; i < t ; i++ )
	{
		cin>>name>>sex>>number>>academy>>phone;
		student[i].Toru(name,sex,number,academy,phone);
	}
	for ( i = 0 ; i < t ; i++ )
		for ( j = i + 1 ; j < t ; j++ )
			student[i].Ranking( student[j] );
	for ( i = 0 ; i < t ; i++ )
		student[i].Miseru();
	delete [] student;
	return 0;
}