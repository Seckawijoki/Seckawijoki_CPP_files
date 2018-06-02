# include <iostream>
# include <iomanip> 
# include <algorithm>
# include <math.h>
using namespace std;
const int printSize = 5;
const int number = 5;
const int capacity = 20; 
//=======�ӑBҎ��=======// 
int c[number+printSize][capacity+printSize];
bool x[number+printSize];
//========�U����========// 
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
//==========================================�U����==========================================// 
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
	cout<<"��õĵ���Ϸ����ǣ�\n";
	for ( int j = 0 ; j < number ; ++j ){
		if ( chosen[index][j] == 0 )continue; 
		cout<<"��"<<j+1<<"����Ʒ��������"<<setw(3)<<weight[j];
		cout<<"g��  �rֵ��$"<<setw(3)<<price[j]<<endl;
	} 
	return max;
}
//==========================================�ӑBҎ��==========================================// 
void package_dynamic_programming(){  
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
	int c0 = capacity; 
    for(int i = number;i>0;i--){  
        //���c[i][weight]����c[i-1][weight]��˵��c[i][weight]�������ֵ�а�����w[i-1]
		//(ע��������i-1����Ϊc���鳤����number+1)  
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
        cout<<"��"<<setw(2)<<i+1<<"����Ʒ��������"<<setw(2)<<weight[i]
							<<"g,  ��ֵ��$" <<setw(3)<<price[i]<<endl;
	}
	cout<<"����ֵ��$"<<c[number][capacity]<<endl;
}  
//==========================================�a���S�C��Ʒ==========================================// 
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
//==========================================ݔ�������̓rֵ==========================================// 
void printWeightAndPrice(){
	cout<<"�� Ʒ �� �� : ";
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
	cout<<"��̬�滮�������\n";
	printArray();
	printPack();
	refreshArray();
	cout<<"================================================\n";
	cout<<"�����������֤��\n";
	refreshArray();
	force();
	panduan();
	printBoolArray();
	cout<<"����ֵ��$"<<findmax()<<endl;
    return 0;
}  
