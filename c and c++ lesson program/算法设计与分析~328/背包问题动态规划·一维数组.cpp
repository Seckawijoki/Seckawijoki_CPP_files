# include <iostream>
# include <iomanip> 
# include <algorithm>
# include <ctime>
using namespace std;
const int printSize = 7;

const int initialNumber = 750;
const int maxNumber = 7500;
const int numberIncrement = 750;

const int initialCapacity = 500;
const int maxCapacity = 5000;
const int capacityIncrement = 500;
int c[(maxNumber+6)*(maxCapacity+6)];
int x[maxNumber+6];
void pack( int number, int capacity, int weight[], int price[] ){  
    /*
		����� 
	*/
    //c[i][v]��ʾǰi����Ʒǡ����һ������Ϊm�ı������Ի�õ�����ֵ  
    for(int i = 0;i<number+1;++i)  
        c[i*maxCapacity]=0;  
    for(int j = 1;j<capacity+1;++j)  
        c[j]=0;  

    for(int i = 1;i<number+1;i++){  
        for(int j = 1;j<capacity+1;j++){  
            //����ƷΪi������Ϊjʱ�������i��������(w[i-1])С�ڵ�������jʱ��c[i][j]Ϊ�����������֮һ��  
            //(1)��Ʒi�����뱳���У�����c[i][j]Ϊc[i-1][j]��ֵ  
            //(2)��Ʒi���뱳���У��򱳰�ʣ������Ϊj-w[i-1],����c[i][j]Ϊc[i-1][j-w[i-1]]��ֵ���ϵ�ǰ��Ʒi�ļ�ֵ  
            if(weight[i-1]<=j){  
                if(c[(i-1)*maxCapacity+j]<(c[(i-1)*maxCapacity+(j-weight[i-1])]+price[i-1]))  
                    c[i*maxCapacity+j] = c[(i-1)*maxCapacity+(j-weight[i-1])]+price[i-1];  
                else  
                    c[i*maxCapacity+j] = c[(i-1)*maxCapacity+j];  
            }else  
                c[i*maxCapacity+j] = c[(i-1)*maxCapacity+j];  
        }  
    } 
    /*
		������Ž� 
	*/
    //�����һ��״̬��¼c[n][weight]��ʼ����  
    for(int i = number;i>0;i--){  
        //���c[i][weight]����c[i-1][weight]��˵��c[i][weight]�������ֵ�а�����w[i-1]
		//(ע��������i-1����Ϊc���鳤����number+1)  
        if(c[i*maxCapacity+capacity]>c[(i-1)*maxCapacity+capacity]){  
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
			cout<<setw(printSize)<<c[i*maxCapacity+j];
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
			//cout<<"========\n";
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
    return 0;
}
