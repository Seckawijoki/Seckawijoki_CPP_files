# include <stdio.h>
struct Birthday{
	int year;
	int month;
	int day;
};
bool runnianpanduan( int y ){
	if ( y %400 == 0 || ( y %100 != 0 && y %4 == 0 ) )
		return true;
	else
		return false;
}
int tianshu_niannei( Birthday b ){
	int i, days = 0;
	switch ( b.month - 1 ){
		case  0:break;
		case  1:days +=  31;break;
		case  2:days +=  59;break;
		case  3:days +=  90;break;
		case  4:days += 120;break;
		case  5:days += 151;break;
		case  6:days += 181;break;
		case  7:days += 212;break;
		case  8:days += 243;break;
		case  9:days += 273;break;
		case 10:days += 304;break;
		case 11:days += 334;break;
		default:break;
	} 
	days += b.day;
	if ( b.month > 2 )
		days += ( runnianpanduan(b.year) ? 1 : 0 );
	return days;
}
int tianshu_nianwai( Birthday b1, Birthday b2 ){
	int i, days = 0;
	if ( b1.year < b2.year ){
		days += ( b2.year - b1.year ) * 365;
		for ( i = b1.year ; i < b2.year ; ++i )
			days += ( runnianpanduan(i) ? 1 : 0 );
		days -= tianshu_niannei(b1);
		days += tianshu_niannei(b2);
	}
	else if ( b1.year >= b2.year ){
		days += ( b1.year - b2.year ) * 365;
		for ( i = b2.year ; i < b1.year ; ++i )
			days += ( runnianpanduan(i) ? 1 : 0 );
		days -= tianshu_niannei(b2);
		days += tianshu_niannei(b1);
	}
	return days; 
}
int nianlingdierming( Birthday b[999], int t ){
	int i, j, index;
	int m1 = 99999;
	int days[999];
	Birthday b0;
	b0.year = 1900;
	b0.month = 1;
	b0.day = 1;
	for ( i = 0 ; i < t ; ++i )
		days[i] = tianshu_nianwai(b[i],b0);
	for ( i = 0 ; i < t ; ++i )if ( m1 > days[i] ){
		m1 = days[i];
		j = i;
	}
	m1 = 99999;
	for ( i = 0 ; i < t ; ++i )if ( i != j && m1 > days[i] ){
		m1 = days[i];
		index = i;
	}
	return index;
}
int main(){
	int i, t;
	Birthday b[999];
	scanf("%d",&t);
	for ( i = 0 ; i < t ; ++i )
		scanf("%d%d%d",&b[i].year,&b[i].month,&b[i].day);
	i = nianlingdierming(b,t);
	printf("%d-%d-%d\n",b[i].year,b[i].month,b[i].day);
	return 0;
}
/* 
��Ŀ����
����һ���ṹ�壬���������գ���ʾһ��ѧ���ĳ������ڡ�
Ȼ����һȺѧ���ĳ����������ҳ�˭�ĳ����������еڶ�

Ҫ�󣺳������ڵĴ洢����ʹ�ýṹ�壬����ʹ���������͵����ݽṹ��
Ҫ�����ȫ���̶Գ������ڵ����롢���ʡ����������ʹ�ýṹ��

����
��һ������t��ʾ��t����������
ÿ�����������������ֱ��ʾ�ꡢ�¡���
��������t��ʵ��

���
������еڶ��ϵĳ������ڣ�������-��-�յĸ�ʽ���

��������
6
1980 5 6
1981 8 3
1980 3 19
1980 5 3
1983 9 12
1981 11 23

�������
1980-5-3
*/ 
