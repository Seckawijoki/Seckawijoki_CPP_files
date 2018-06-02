// �����㷨��������  
# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# include <stdlib.h>
# include <iomanip>
# include <time.h>
using namespace std ;
const int decimalDigit = 2;
const int digit = 8;
const int MAX_DISTANCE = 10000;
const int MAX_LENGTH = 100005; 
const int INF = 1000000005 ;
const int run_times = 10;
const int model[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
struct Point
{
	double x , y ;
}point[MAX_LENGTH];
int n ;
int maxn;
int temp[MAX_LENGTH];
int i1 , i2;
bool cmp(const  Point& a , const Point& b)
{
	if( a.x == b.x )
		return  a.y < b.y ;
	else
		return a.x < b.x ;
}

bool cmpx(const int& a , const int& b)
{
	return point[a].x < point[b].x;
}

bool cmpy(const int& a , const int& b)
{
	return point[a].y < point[b].y;
}

double min(double a , double b)
{
	return a < b ? a : b;
}

double dist(int i , int j)
{
	return sqrt( (point[i].x - point[j].x) * (point[i].x - point[j].x) 
			    +(point[i].y - point[j].y) * (point[i].y - point[j].y) ) ;
}

double closest(int left , int right)
{
	double d = INF ;
	if( left == right )
	{
		i1 = left;
		i2 = right;
		return d ;
	}
	if( left + 1 == right )
	{
		i1 = left;
		i2 = right;
		return dist( left , right ) ;
	}

	int mid = ( left + right ) >> 1 ;
	double d1 = closest( left , mid ) ;
	double d2 = closest( mid + 1 , right ) ;
	d = min(d1, d2);
	int i , j , k = 0 ;
	for( i = left ; i <= right ; ++i )
	{
		if( fabs( point[mid].x - point[i].x ) <= d )
			temp[k++] = i ;
	}
	sort( temp , temp + k , cmpy ) ;
	for( i = 0 ; i < k ; ++i )
		for( j = i + 1 ; j < k &&  point[temp[j]].y - point[temp[i]].y < d ; ++j )
		{
			double d3 = dist( temp[i] , temp[j] ) ; 
			if( d > d3 )
			{
				d = d3 ;
				i1 = temp[i];
				i2 = temp[j];
			}
		}
	sort(temp , temp + k , cmpx);
	return d ;
}
double manlifa()
{
	double d, min = INF;
	for ( int i =  0  ; i < maxn ; ++i )
	for ( int j = i+1 ; j < maxn ; ++j )
	{
		d = dist(i, j);
		if ( min > d )
		{
			min = d;
			i1 = i;
			i2 = j;
		}
	}
	return min; 
} 
//======================================================//
/*
	��������� 
*/
void produceRandomPoints( int length )
{
	for ( int i = 0 ; i < length ; ++i )
	{
		point[i].x = (rand() / (double)(RAND_MAX)) * MAX_DISTANCE;
		point[i].y = ((double)(RAND_MAX) / rand()) * MAX_DISTANCE;
	}	
}
int main()
{
	double distance;
	long start, end;
	long amount;
	/*
		�����㷨 
	*/ 
	cout<<"�������㷨��\n"; 
	for ( int i = 0 ; i < run_times ; ++i )
	{
		maxn = model[i];
		cout<<"����ʹ�÷����㷨���㡭������ģΪ"<<setw(6)<<maxn<<"ʱ��\n"; 
		amount = 0;
		for ( int j = 0 ; j < 100 ; ++j )
		{
			i1 = 0;
			i2 = maxn;
			produceRandomPoints(maxn);
			start = clock();
			sort(point , point + maxn , cmp);
			distance = closest( i1 , i2 );
			end = clock();
			amount += end - start;
			//��ƽ���㷨�������������� 
//			cout<<"�������:("
//				<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i1].x<<", "
//				<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i1].y<<") �� ("
//				<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i2].x<<", "
//				<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i2].y<<")��";
//			cout<<"��̾���:"<<setw(5)<<distance;
//			cout<<"������ʱ��:"<<end-start<<"(ms)\n";
		} 
		cout<<"�����㷨�ڹ�ģΪ"<<setw(6)<<maxn<<"������£�ƽ������ʱ�䣺"<<amount/100<<"(ms)\n";
		cout<<"      <  --------------------------------------  >      \n";
	}
	
	cout<<"=========================================================================\n"; 
	/*
		������ 
	*/
	cout<<"����������\n"; 
	for ( int i = 0 ; i < run_times ; ++i )
	{
		maxn = model[i];
		i1 = 0;
		i2 = maxn;
		cout<<"����ʹ�����������㡭������ģΪ"<<setw(6)<<maxn<<"ʱ��\n"; 
		produceRandomPoints(maxn);
		start = clock();
		distance = manlifa();
		end = clock();
		cout<<"�������:("
			<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i1].x<<", "
			<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i1].y<<") �� ("
			<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i2].x<<", "
			<<setw(digit)<<fixed<<setprecision(decimalDigit)<<point[i2].y<<")��";
		cout<<"��̾���:"<<setw(5)<<distance;
		cout<<"������ʱ��:"<<end-start<<"(ms)\n";
	} 
	return 0 ;
}


