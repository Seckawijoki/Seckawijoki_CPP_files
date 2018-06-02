# include <iostream>
# include <iomanip> 
# include <algorithm>
# include <ctime>
# include <math.h>
using namespace std;
const int printSize = 7;
const int initialNumber = 10;
const int maxNumber = 30;
const int numberIncrement = 10;
//=======�ӑBҎ��=======// 
const int initialCapacity = 200;
const int maxCapacity = 1000;
const int capacityIncrement = 200;
int c[maxNumber+6][maxCapacity+6];
int x[maxNumber+6];
//========�U����========// 
int chosen[int(pow(2,maxNumber)+6)][maxCapacity+6];
int cp[maxNumber+printSize];

void refreshArray( int number, int capacity ){
	int length = (int)pow(2,number);
	for ( int i = 0 ; i <= number ; ++i ){
		x[i] = false;
		cp[i] = 0;
		for ( int j = 0 ; j <= capacity ; ++j )
			c[i][j] = 0;
	}
}
//==========================================�U����==========================================// 
void force( int number, int capacity){
	int length = (int)pow(2,number);
	for ( int i = 0 ; i < length ; ++i ){
		int t = i;
		for ( int j = number-1 ; j >= 0 ; --j ){
			chosen[i][j] = t%2;
			t /= 2;
		}
	}
}void printBoolArray (int number, int capacity){
	int length = (int)pow(2,number);
	for ( int i = 0 ; i < length ; ++i ){
		cout<<"��"<<setw(2)<<i+1<<"�����Y����" ; 
		for ( int j = 0 ; j < number ; ++j )
			cout<<' '<<(chosen[i][j] == 1 ? "��" : "  ")<<' ';
		if ( cp[i] == 0 )
			cout<<cp[i]<<endl; 
		else
			cout<<"���rֵ��$"<<setw(3)<<cp[i]<<endl;
	}
	cout<<endl;
}
void panduan( int number, int capacity, int weight[], int price[]){
	int c2, p; 
	int length = (int)pow(2,number);
	for ( int i = 0 ; i < length ; ++i ){
		c2 = 0;
		p = 0;
		for ( int j = 0 ; j < number ; ++j ){
			c2 += weight[j] * chosen[i][j];
			p += price[j] * chosen[i][j];
		}
		if ( c2 <= capacity )cp[i] = p;
		else cp[i] = 0;
	}
}
int findmax( int number, int capacity, int weight[], int price[]){
	int max = 0;
	int index;
	int length = (int)pow(2,number);
	for ( int i = 0 ; i < length ; ++i ){
		if ( cp[i] > max ){
			max = cp[i];
			index = i;
		}
	}
	cout<<"��õĵ���Ϸ����ǣ�\n";
	for ( int j = 0 ; j < number ; ++j ){
		if ( chosen[index][j] == 0 )continue; 
		cout<<"��"<<j+1<<"����Ʒ��������"<<setw(3)<<weight[j];
		cout<<"g��  �rֵ��$"<<setw(3)<<price[j]<<endl;
	} 
	return max;
}
void pack( int number, int capacity, int weight[], int price[] ){  
    /*
		����� 
	*/
    //c[i][v]��ʾǰi����Ʒǡ����һ������Ϊm�ı������Ի�õ�����ֵ  
    for(int i = 0;i<number+1;i++)  
        c[i][0]=0;  
    for(int j = 0;j<capacity+1;j++)  
        c[0][j]=0;  

    for(int i = 1;i<number+1;i++){  
        for(int j = 1;j<capacity+1;j++){  
            //����ƷΪi������Ϊjʱ�������i��������(w[i-1])С�ڵ�������jʱ��c[i][j]Ϊ�����������֮һ��  
            //(1)��Ʒi�����뱳���У�����c[i][j]Ϊc[i-1][j]��ֵ  
            //(2)��Ʒi���뱳���У��򱳰�ʣ������Ϊj-w[i-1],����c[i][j]Ϊc[i-1][j-w[i-1]]��ֵ���ϵ�ǰ��Ʒi�ļ�ֵ  
            if(weight[i-1]<=j){  
                if(c[i-1][j]<(c[i-1][j-weight[i-1]]+price[i-1]))  
                    c[i][j] = c[i-1][j-weight[i-1]]+price[i-1];  
                else  
                    c[i][j] = c[i-1][j];  
            }else  
                c[i][j] = c[i-1][j];  
        }  
    } 
    /*
		������Ž� 
	*/
    //�����һ��״̬��¼c[n][weight]��ʼ����  
    for(int i = number;i>0;i--){  
        //���c[i][weight]����c[i-1][weight]��˵��c[i][weight]�������ֵ�а�����w[i-1]
		//(ע��������i-1����Ϊc���鳤����number+1)  
        if(c[i][capacity]>c[i-1][capacity]){  
            x[i-1] = 1;  
            capacity-=weight[i-1];  
        }  
    }  
}  
void printArray( int number, int capacity ){
	cout<<"c["<<number<<"]["<<capacity<<"]:\n";
	cout<<setw(printSize)<<' ';
	for ( int j = 0 ; j <= capacity ; ++j )
		cout<<setw(printSize)<<j;
	cout<<endl;
	for ( int i = 0 ; i <= number ; ++i ){
		cout<<setw(printSize)<<i;
		for ( int j = 0 ; j <= capacity ; ++j )
			cout<<setw(printSize)<<c[i][j];
		cout<<endl;
	}
}
void printPack(int number, int capacity, int weight[], int price[]){  
    for(int i = 0;i<number;i++){
        if ( x[i] == 0 ) continue;
        cout<<"��"<<i+1<<"����Ʒ������"<<setw(printSize)<<weight[i]
							<<" ��ֵ" <<setw(printSize)<<price[i]<<endl;
	} 
}  
void produceItems( int number, int capacity, int weight[], int price[] ){
	for ( int i = 0 ; i < number ; ++i ){
		do
		weight[i] = (int)(rand() % capacity);
		while ( weight[i] == 0 );	

		do
		price[i] = (int)(rand() % capacity * 10);
		while ( price[i] == 0 );
	}
}
void printWeightAndPrice( int number, int capacity, int weight[], int price[] ){
	cout<<"��Ʒ��ţ� ";
	for ( int i = 0 ; i < number ; ++i )
		cout<<setw(printSize)<<i+1;
	cout<<"\nweight["<<number<<"]:";
	for ( int i = 0 ; i < number ; ++i ){
		cout<<setw(printSize)<<weight[i];
		if ( i %30 == 0 && i != 0 )cout<<endl;
	}
	cout<<"\n price["<<number<<"]:";
	for ( int i = 0 ; i < number ; ++i ){
		cout<<setw(printSize)<<price[i];
		if ( i %30 == 0 && i != 0 )cout<<endl;
	}
	cout<<endl;
}
int main(){  
    int number, capacity;
    int weight[maxNumber];  
    int price[maxNumber];
	long start, end;
    int runtime[maxNumber/numberIncrement+6][maxCapacity/capacityIncrement+6];
    cout<<"����ʹ�ö�̬�滮����������⡭���Ժ�ó����н��������ʱ��~\n";
	for ( number = initialNumber ; number <= maxNumber ; number += numberIncrement ){
		for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement ){
			produceItems(number, capacity, weight, price);
			//printWeightAndPrice(number, capacity, weight, price);
			start = clock();
			pack(number, capacity, weight, price);
			end = clock();
			//printArray(number, capacity);
			//printPack(number, capacity, weight, price);
			runtime
			[number/numberIncrement]
			[capacity/capacityIncrement] = (end-start);
		}
	}

	cout<<" weight:"<<setw(20-printSize)<<' ';
	for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement )
		cout<<setw(printSize)<<capacity;
	for ( number = initialNumber ; number <= maxNumber ; number += numberIncrement ){
		cout<<"\n number = "<<setw(printSize)<<number<<"ʱ��";
		for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement )
			cout<<setw(printSize)<<
				runtime
				[number/numberIncrement]
				[capacity/capacityIncrement];
	} 
	

	cout<<"����ʹ������������������⡭���Ժ�ó����н��������ʱ��~\n";
	for ( number = initialNumber ; number <= maxNumber ; number += numberIncrement ){
		for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement ){
			produceItems(number, capacity, weight, price);
			refreshArray(number,capacity);
			//printWeightAndPrice(number, capacity, weight, price);
			start = clock();
			force(number,capacity);
			panduan(number,capacity,weight,price);
			end = clock();
			//printArray(number, capacity);
			//printPack(number, capacity, weight, price);
			runtime
			[number/numberIncrement]
			[capacity/capacityIncrement] = (end-start);
		}
	}
	cout<<" weight:"<<setw(20-printSize)<<' ';
	for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement )
		cout<<setw(printSize)<<capacity;
	for ( number = initialNumber ; number <= maxNumber ; number += numberIncrement ){
		cout<<"\n number = "<<setw(printSize)<<number<<"ʱ��";
		for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement )
			cout<<setw(printSize)<<
				runtime
				[number/numberIncrement]
				[capacity/capacityIncrement];
	} 
    return 0;
}  
