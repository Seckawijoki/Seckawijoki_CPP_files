# include <iostream>
# include <iomanip> 
# include <algorithm>
# include <math.h>
using namespace std;
const int printSize = 5;
const int number = 5;
const int capacity = 20; 
//=======動態規劃=======// 
int c[number+printSize][capacity+printSize];
bool x[number+printSize];
//========蠻力法========// 
int **chosen;
int cp[number+printSize];
int length = (int)pow(2,number);

void refreshArray(){
	for ( int i = 0 ; i <= number ; ++i ){
		x[i] = false;
		cp[i] = 0;
		for ( int j = 0 ; j <= capacity ; ++j )
			c[i][j] = 0;
	}
}
//==========================================蠻力法==========================================// 
void force(){
	chosen = new int* [length+printSize];
	for ( int i = 0 ; i < length ; ++i ){
		chosen[i] = new int [number];
	}
	for ( int i = 0 ; i < length ; ++i ){
		int t = i;
		for ( int j = number-1 ; j >= 0 ; --j ){
			chosen[i][j] = t%2;
			t /= 2;
		}
	}
}void printBoolArray(){
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
void panduan(){
	int c2, p; 
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
int findmax(){
	int max = 0;
	int index;
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
//==========================================動態規劃==========================================// 
void package_dynamic_programming(){  
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
	int c0 = capacity; 
    for(int i = number;i>0;i--){  
        //如果c[i][weight]大于c[i-1][weight]，说明c[i][weight]这个最优值中包含了w[i-1]
		//(注意这里是i-1，因为c数组长度是number+1)  
        if(c[i][c0]>c[i-1][c0]){  
            x[i-1] = true;  
            c0-=weight[i-1];  
        }  
    }  
}  
void printArray(){
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
void printPack(){  
    for(int i = 0;i<number;i++){
        if ( x[i] == false ) continue;
        cout<<"第"<<setw(2)<<i+1<<"个物品：重量："<<setw(2)<<weight[i]
							<<"g,  价值：$" <<setw(3)<<price[i]<<endl;
	}
	cout<<"最大价值：$"<<c[number][capacity]<<endl;
}  
//==========================================產生隨機物品==========================================// 
void produceItems(){
	for ( int i = 0 ; i < number ; ++i ){
		do
		weight[i] = (int)(rand() % capacity);
		while ( weight[i] == 0 );	

		do
		price[i] = (int)(rand() % capacity )* 10;
		while ( price[i] == 0 );
	}
}
//==========================================輸出重量和價值==========================================// 
void printWeightAndPrice(){
	cout<<"物 品 编 号 : ";
	for ( int i = 0 ; i < number ; ++i )
		cout<<setw(printSize)<<i+1;
	cout<<"\nweight["<<setw(2)<<number<<"](g):";
	for ( int i = 0 ; i < number ; ++i ){
		cout<<setw(printSize)<<weight[i];
		if ( i %30 == 0 && i != 0 )cout<<endl;
	}
	cout<<"\n price["<<setw(2)<<number<<"]($):";
	for ( int i = 0 ; i < number ; ++i ){
		cout<<setw(printSize)<<price[i];
		if ( i %30 == 0 && i != 0 )cout<<endl;
	}
	cout<<endl;
}
int main(){  
	produceItems();

	printWeightAndPrice();
	package_dynamic_programming();
	cout<<"动态规划求解结果：\n";
	printArray();
	printPack();
	refreshArray();
	cout<<"================================================\n";
	cout<<"蛮力法求解验证：\n";
	refreshArray();
	force();
	panduan();
	printBoolArray();
	cout<<"最大价值：$"<<findmax()<<endl;
    return 0;
}  
