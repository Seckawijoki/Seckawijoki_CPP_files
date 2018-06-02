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
//=======動態規劃=======// 
const int initialCapacity = 200;
const int maxCapacity = 1000;
const int capacityIncrement = 200;
int c[maxNumber+6][maxCapacity+6];
int x[maxNumber+6];
//========蠻力法========// 
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
//==========================================蠻力法==========================================// 
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
		cout<<"第"<<setw(2)<<i+1<<"個求解結果：" ; 
		for ( int j = 0 ; j < number ; ++j )
			cout<<' '<<(chosen[i][j] == 1 ? "√" : "  ")<<' ';
		if ( cp[i] == 0 )
			cout<<cp[i]<<endl; 
		else
			cout<<"總價值：$"<<setw(3)<<cp[i]<<endl;
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
	cout<<"最好的的组合方案是：\n";
	for ( int j = 0 ; j < number ; ++j ){
		if ( chosen[index][j] == 0 )continue; 
		cout<<"第"<<j+1<<"個物品：重量："<<setw(3)<<weight[j];
		cout<<"g，  價值：$"<<setw(3)<<price[j]<<endl;
	} 
	return max;
}
void pack( int number, int capacity, int weight[], int price[] ){  
    /*
		填矩阵 
	*/
    //c[i][v]表示前i件物品恰放入一个重量为m的背包可以获得的最大价值  
    for(int i = 0;i<number+1;i++)  
        c[i][0]=0;  
    for(int j = 0;j<capacity+1;j++)  
        c[0][j]=0;  

    for(int i = 1;i<number+1;i++){  
        for(int j = 1;j<capacity+1;j++){  
            //当物品为i件重量为j时，如果第i件的重量(w[i-1])小于等于重量j时，c[i][j]为下列两种情况之一：  
            //(1)物品i不放入背包中，所以c[i][j]为c[i-1][j]的值  
            //(2)物品i放入背包中，则背包剩余重量为j-w[i-1],所以c[i][j]为c[i-1][j-w[i-1]]的值加上当前物品i的价值  
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
		求出最优解 
	*/
    //从最后一个状态记录c[n][weight]开始逆推  
    for(int i = number;i>0;i--){  
        //如果c[i][weight]大于c[i-1][weight]，说明c[i][weight]这个最优值中包含了w[i-1]
		//(注意这里是i-1，因为c数组长度是number+1)  
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
	

	cout<<"正在使用蛮力法解决背包问题……稍后得出所有结果的运行时间~\n";
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
		cout<<"\n number = "<<setw(printSize)<<number<<"时：";
		for ( capacity = initialCapacity ; capacity <= maxCapacity ; capacity += capacityIncrement )
			cout<<setw(printSize)<<
				runtime
				[number/numberIncrement]
				[capacity/capacityIncrement];
	} 
    return 0;
}  
