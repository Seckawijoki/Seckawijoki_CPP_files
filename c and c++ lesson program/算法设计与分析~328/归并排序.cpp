# include <iostream>
# include <windows.h>
# include <time.h>
# include <iomanip>
using namespace std;
const int MAX_LENGTH = 131072;
const int size[] = {10, 100, 1000, 10000, 100000};
const int PRINT_LENGTH = 8;
void displayArray( int array[], int length )
{
	for ( int i = 0 ; i < length ; ++i )
		cout<<setw(PRINT_LENGTH)<<array[i]<<' ';
	cout<<endl;
}

//======================================================//
/*
	归并排序 
*/
void Merge( int InitList[], int mergedList[], int left, int middle, int right ) {
    int i = left,  j = middle + 1,  k = left;		
    while ( i <= middle && j <= right )
    {
        if ( InitList[i] <= InitList[j] )
			mergedList[k++] = InitList[i++];
        else
        	mergedList[k++] = InitList[j++];
    }
    while( i <= middle )  
		mergedList[k++] = InitList[i++];
    while( j <= right )
		mergedList[k++] = InitList[j++];
    displayArray(mergedList, right-left+1); 
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
  生成随机数 
*/
void produceRandomDigits( int *array, int length )
{
  for ( int i = 0 ; i < length ; ++i )
    array[i] = (int) (rand() %MAX_LENGTH);
  displayArray(array, length);
} 

int main()
{
  int a1[10]={235,36,46785,5,9,6,969,368,74,684};
  int a2[10]={0};
//  produceRandomDigits(a1, 10);
  displayArray(a1, 10);
  MergeSort(a1, a2, 0, 9);
  displayArray(a1, 10);
  return 0;
}
