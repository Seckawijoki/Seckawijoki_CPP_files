/*
籾朕宙峰
譜柴匯倖窃栖糞�嵎峪�議孔嬬。
万淫根暴嗤奉來�査殿訐猥諭∈殿襦∈殿誚缶�、唯字晩豚��
淫根圭隈�差行譟⊃襲換行譟�嬉咫、唯字。
1、催鷹窃侏燕幣喘薩窃艶��峪喘汽倖忖銚��A燕幣屓軒��B燕幣二匍、C燕幣倖繁
2、催鷹頁11了屁方��喘匯倖忖憲堪燕幣
3、催鷹彜蓑喘匯倖方忖燕幣��1、2、3蛍艶燕幣壓喘、隆喘、唯喘
4、唯字晩豚頁匯倖晩豚斤�黏胡襭�壓兜兵晒扮乎撹埀峺�鮨妝�
乎晩豚窃淫根暴嗤奉來定埖晩��參式更夛痕方才嬉咫痕方吉
----------------------------------------
5、更夛痕方議恬喘祥頁俊鞭翌栖歌方��
旺譜崔光倖奉來峙��旺補竃戻幣佚連��心幣箭補竃
6、申唄更夛議恬喘頁鹸崙厮嗤斤�鶺槻渡■�旺補竃戻幣佚連��心幣箭補竃。
�誨始騨�字晩豚乎泌採鹸崙��短嗤唯字泌採鹸崙�殖�
厮将唯字嗽泌採鹸崙�殖�
7、嬉咫孔嬬頁委斤�鶺痛�嗤奉來脅補竃��補竃鯉塀心幣箭
8、唯字孔嬬頁唯喘輝念催鷹��
歌方頁唯字晩豚��涙卦指峙��
荷恬頁委彜蓑個撹唯喘��旺唯字晩豚峺寞幹秀葎強蓑斤�鵤�
旺功象歌方栖譜崔唯字晩豚��恷朔補竃戻幣佚連��心幣箭補竃
-------------------------------------------
勣箔�犀旄�痕方嶄糞�嶌殿覬厳鬱長δ棕�
斤厮嗤議倡亭返字催議侭嗤佚連序佩鹸崙��
旺繍催鷹窃侏個撹D燕幣姥芸��
繍返字催鷹挑硫紗忖銚X
-----------------------------------------------
麼痕方議歌深旗鷹泌和�瑳拮荳殿訐狠�葎PNO
��葎閲窒旗鷹嶷鹸��徭失議旗鷹萩音勣喘宸倖窃兆��
PNO p1(.......) ; //幹秀催鷹旺兜兵晒
p1.Print();       //補竃圻催鷹佚連
PNO p2(p1);       //糞�嶌殿覬厳�
p2.Print();       //補竃姥芸催鷹佚連
p1.Stop(td);      //圻催鷹唯字��td頁晩豚斤��
p1.Print();       //補竃唯字朔催鷹佚連

補秘
及匯佩補秘t燕幣嗤t倖催鷹
及屈佩補秘6倖歌方��
淫凄催鷹窃侏、催鷹、彜蓑、唯字議定、埖、晩��喘腎鯉侯蝕
卆肝補秘t佩

補竃
耽倖幣箭補竃眉佩��卆肝補竃圻催鷹佚連、姥芸催鷹佚連才圻催鷹唯字朔議佚連
耽倖幣箭岻寂喘玉皿�滷�膨倖��蛍護蝕��心幣箭補竃

劔箭補秘
2
A 15712345678 1 2015 1 1
B 13287654321 2 2012 12 12

劔箭補竃
Construct a new phone 15712345678
窃侏=字更||催鷹=15712345678||State=壓喘
Construct a copy of phone 15712345678
窃侏=姥芸||催鷹=15712345678X||State=壓喘
Stop the phone 15712345678
窃侏=字更||催鷹=15712345678||State=唯喘 ||唯字晩豚=2015.1.1
----
Construct a new phone 13287654321
窃侏=二匍||催鷹=13287654321||State=隆喘
Construct a copy of phone 13287654321
窃侏=姥芸||催鷹=13287654321X||State=隆喘
Stop the phone 13287654321
窃侏=二匍||催鷹=13287654321||State=唯喘 ||唯字晩豚=2012.12.12
----
*/
# include <stdio.h>
# include <string.h>
class Teishihizuke//唯峭晩原(ていしひずけ)
{
private:
	int nen,getsu,nichi;
public:
	Teishihizuke()
	{
		nen = 2000;
		getsu = 1;
		nichi = 1;
	}
	Teishihizuke( int year , int month , int day )
	{
		nen = year;
		getsu = month;
		nichi = day;
	}
	int ToruNen(){return nen;}
	int ToruGetsu(){return getsu;}
	int ToruNichi(){return nichi;}
	void OkuNenGetsuNichi( int year , int month , int day )
	{
		nen = year;
		getsu = month;
		nichi = day;
	}
	void Miseru()
	{
		printf("唯字晩豚=%d.%d.%d\n----\n",nen,getsu,nichi);
	}
};
class Keitaidenwa
{
private:
	char taipu;
	char bango[22];
	int joutai;
	Teishihizuke *hizuke;
public:
	Keitaidenwa()
	{
		taipu = 'A';
		bango[0] = '\0';
		joutai = 1;
		hizuke = new Teishihizuke [1];
		hizuke->OkuNenGetsuNichi(2000,1,1);
		printf("Construct a new phone %s\n",bango);
	}
	Keitaidenwa(char type,char *number,int state,int year,int month,int day)
	{
		taipu = type;
		strcpy(bango,number);
		joutai = state;
		hizuke = new Teishihizuke [1];
		hizuke->OkuNenGetsuNichi(year,month,day);//峺寞��音頁a[5]侘議��喘"->"
		printf("Construct a new phone %s\n",bango);
		char ty[11],st[11];
		//�觀�頁屎鳩議。紗＾\0￣祥辛唯峭。
		switch ( taipu )
		{
			case 'A' :{strcpy(ty,"字更\0");break;}
			case 'B' :{strcpy(ty,"二匍\0");break;}
			case 'C' :{strcpy(ty,"倖繁\0");break;}
			case 'D' :{strcpy(ty,"姥芸\0");break;}
			default  :break;
		}
		switch ( state )
		{
			case  1  :{strcpy(st,"壓喘\0");break;}
			case  2  :{strcpy(st,"隆喘\0");break;}
			case  3  :{strcpy(st,"唯喘\0");break;}
			default  :break;
		}
		printf("窃侏=%s||催鷹=%s||State=%s\n",ty,bango,st);
	}
	Keitaidenwa( Keitaidenwa &backup )
	{
		strcpy(bango,backup.bango);
		backup.bango[strlen(bango)] = 'X';
		backup.bango[strlen(bango)+1] = '\0';
		taipu = 'D';
		joutai = backup.joutai;
		backup.hizuke->OkuNenGetsuNichi(backup.hizuke->ToruNen(),backup.hizuke->ToruGetsu(),backup.hizuke->ToruNichi());
		printf("Construct a copy of phone %s\n",bango);//= =!Constructing= =!
		switch ( joutai )
		{
			case 1 :{printf("窃侏=姥芸||催鷹=%s||State=壓喘\n",backup.bango);}break;
			case 2 :{printf("窃侏=姥芸||催鷹=%s||State=隆喘\n",backup.bango);}break;
			case 3 :{printf("窃侏=姥芸||催鷹=%s||State=唯喘\n",backup.bango);}break;
			default : break;
		}
	}
	void Tomeru( Teishihizuke &hizuke )
	{
		bango[strlen(bango)-1] = '\0';
		printf("Stop the phone %s\n",bango);
		switch ( taipu )
		{
			case 'A' :{printf("窃侏=字更||催鷹=%s||State=唯喘 ||",bango);break;}
			case 'B' :{printf("窃侏=二匍||催鷹=%s||State=唯喘 ||",bango);break;}
			case 'C' :{printf("窃侏=倖繁||催鷹=%s||State=唯喘 ||",bango);break;}
			default : break;
		}
		hizuke.Miseru();
	}
};
int main()
{
	int t;
	char type;
	char number[22];
	int state,year,month,day;
	scanf("%d",&t);
	while ( t-- )
	{
		//基宛危列。音誼盾。
		getchar();//廣吭腎鯉= =��壓喘C囂冱~貧中議旗鷹淫凄指概議補竃��哘崔噐緩。
		scanf("%c %s %d %d %d %d",&type,number,&state,&year,&month,&day);
		Keitaidenwa denwa(type,number,state,year,month,day);
		Keitaidenwa backup(denwa);
		Teishihizuke hizuke(year,month,day);
		denwa.Tomeru(hizuke);
	}
	return 0;
}