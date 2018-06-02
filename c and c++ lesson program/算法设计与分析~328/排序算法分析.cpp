# include <iostream>
# include <windows.h>
# include <time.h>
# include <iomanip>
using namespace std;
const int MAX_LENGTH = 103072;
const int size[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
const int sizeOfModel = 10;
const int PRINT_LENGTH = 8;
const int run_time = 21;
//======================================================//
/*
	��������� 
*/
void produceRandomDigits( int array[], int length )
{
	for ( int i = 0 ; i < length ; ++i )
		array[i] = (int) (rand() * MAX_LENGTH);
} 
//======================================================//
/*
	�������� 
*/
void InsertSort(int array[], int length )
{
	for ( int i = 1; i < length; ++i ) 
	{
		int temp = array[i];
		int j;
		for ( j = i;  j > 0 ; --j ) 
		{
		  if ( temp < array[j-1] )
		  	array[j] = array[j-1];
		  else break;
		}
		array[j] = temp;
    }
}

//======================================================//
/*
	�۰�������� 
*/
void BinaryInsertionSort( int array[], int length ) 
{
	for ( int i = 1 ; i < length ; ++i ) 
	{
	    int temp = array[i];
	    int low = 0;
		int high = i - 1;
	    while ( low <= high ) 
		{
	      int middle = ( low + high ) /2;
	      if ( temp < array[middle] ) 
		  	high = middle - 1;
	      else  
		  	low = middle + 1;
	    }
	    for ( int j = i - 1 ; j >= high + 1 ; --j ) 
			array[j+1] = array[j];
	    array[high+1] = temp;
	}
}

//======================================================//
/*
	ð������ 
*/
void BubbleSort( int array[], int length )
{
	for ( int i = 0 ; i < length ; ++i )
	{
		bool flag = true; 
		for ( int j = i ; j < length ; ++j )
		if  ( array[j] > array[j+1] )
		{
			flag = false;
			int temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
		}
		if ( flag )break;
	} 
}

//======================================================//
/*
	�������� 
*/
int Partition( int array[], int low, int high )
{
	int pivotkey = array[low];
	array[0] = array[low];
	while ( low < high )
	{
		while ( low < high && array[high] >= pivotkey )--high;
		array[low] = array[high];
		while ( low < high && array[low]  <= pivotkey )++low;
		array[high] = array[low];
	}
	array[low] = array[0];
	return low;
}
int QuickSort( int array[], int low, int high )
{
	int pivotlocation;
	if ( low < high )
	{
		pivotlocation = Partition(array,low,high);
		QuickSort(array,low,pivotlocation-1);
		QuickSort(array,pivotlocation+1,high);
	}
}

//======================================================//
/*
	��ѡ������ 
*/
int SelectMinKey( int array[], int start, int end )
{
	int index = start;
	int min = array[start];
	for ( int i = start + 1 ; i <= end ; ++i )
	if ( min > array[i] )
	{
		index = i;
		min = array[i];
	}
	return index;
}
void SelectSort( int array[], int length )
{
  for ( int i = 0 ; i < length - 1 ; ++i )
  { 
    int j = SelectMinKey(array, i, length-1);
    if ( i != j )
	{
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;    
    } 
  }
}
//======================================================//
/*
	�鲢���� 
*/
void Merge( int InitList[], int mergedList[], int left, int middle, int right ) {
    int i = left,  j = middle + 1,  k = left;		
    while ( i <= middle && j <= right )
        if ( InitList[i] <= InitList[j] )
			mergedList[k++] = InitList[i++];
        else
        	mergedList[k++] = InitList[j++];
    while( i <= middle )  
		mergedList[k++] = InitList[i++];
    while( j <= right )
		mergedList[k++] = InitList[j++];
}
void MergeSort( int array[], int list[], int start, int end )
{
   if ( start < end )
    {
       int middle = ( start + end ) /2;
       MergeSort(array, list, start, middle);
       MergeSort(array ,list, middle+1, end);
       Merge(array, list, start, middle, end);
    }
}
//======================================================//
/*
	�������� 
*/
void copyArray( int array1[], int array2[], int length )
{
	for ( int i = 0 ; i < length ; ++i )
		array2[i] = array1[i];
}
int main()
{
	while ( true )
	{
		int type;
		int averageTime[sizeOfModel] = {0};
		int a[MAX_LENGTH];
		produceRandomDigits(a, MAX_LENGTH);
		cout<<"1����������\n2���۰��������\n3��ð������\n4����������\n5����ѡ������\n6���鲢����\n7���˳���\n";
		cout<<"��ѡ����������㷨��\n";
		cin>>type;
		cout<<" ��  ģ ( n ) :";
		for ( int i = 0 ; i < sizeOfModel ; ++i )
			cout<<setw(PRINT_LENGTH)<<size[i];
		cout<<endl;
		for ( int i = 0 ; i < run_time ; ++i )
		{
			long start, end;
			cout<<"��"<<setw(2)<<i<<"�κ�ʱ(ms):";
			for ( int j = 0 ; j < sizeOfModel ; ++j )
			{
				int temp [MAX_LENGTH];
				int temp2[MAX_LENGTH];
				copyArray(a, temp, size[j]);
				start = clock();
				switch ( type )
				{
					case 1:InsertSort(temp, size[j]);break;
					case 2:BinaryInsertionSort(temp, size[j]);break;
					case 3:BubbleSort(temp, size[j]);break;
					case 4:QuickSort(temp, 0, size[j]-1);break;
					case 5:SelectSort(temp, size[j]);break;
					case 6:MergeSort(temp, temp2, 0, size[j]-1);break;
					default:exit(0);
				}
				end = clock();
				averageTime[j] += end - start;
				cout<<setw(PRINT_LENGTH)<<end - start;
			}
			cout<<endl;
		}
		cout<<" ƽ����ʱ (ms):";
		for ( int i = 0 ; i < sizeOfModel ; ++i )
		{ 
			averageTime[i] /= run_time;
			cout<<setw(PRINT_LENGTH)<<averageTime[i];
		} 
		cout<<endl;
	}
	return 0;
}

