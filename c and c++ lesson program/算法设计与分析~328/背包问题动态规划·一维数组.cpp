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
		填矩阵 
	*/
    //c[i][v]表示前i件物品恰放入一个重量为m的背包可以获得的最大价值  
    for(int i = 0;i<number+1;++i)  
        c[i*maxCapacity]=0;  
    for(int j = 1;j<capacity+1;++j)  
        c[j]=0;  

    for(int i = 1;i<number+1;i++){  
        for(int j = 1;j<capacity+1;j++){  
            //当物品为i件重量为j时，如果第i件的重量(w[i-1])小于等于重量j时，c[i][j]为下列两种情况之一：  
            //(1)物品i不放入背包中，所以c[i][j]为c[i-1][j]的值  
            //(2)物品i放入背包中，则背包剩余重量为j-w[i-1],所以c[i][j]为c[i-1][j-w[i-1]]的值加上当前物品i的价值  
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
		求出最优解 
	*/
    //从最后一个状态记录c[n][weight]开始逆推  
    for(int i = number;i>0;i--){  
        //如果c[i][weight]大于c[i-1][weight]，说明c[i][weight]这个最优值中包含了w[i-1]
		//(注意这里是i-1，因为c数组长度是number+1)  
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
        cout<<"第"<<i+1<<"个物品：重量"<<setw(printSize)<<weight[i]
							<<" 价值" <<setw(printSize)<<price[i]<<endl;
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
	cout<<"物品编号： ";
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
    cout<<"正在使用动态规划解决背包问题……稍后得出所有结果的运行时间~\n";
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
		cout<<"\n number = "<<setw(printSize)<<number<<"时：";
		for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement )
			cout<<setw(printSize)<<
				runtime
				[number/numberIncrement]
				[capacity/capacityIncrement];
	} 
    return 0;
}
