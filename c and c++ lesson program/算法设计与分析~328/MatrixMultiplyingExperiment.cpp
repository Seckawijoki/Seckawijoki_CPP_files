#include"StrassenMatrixMultiplicationAlgorithm.h" 
#include<iostream>
#include<ctime>
#include<Windows.h>
#include<iomanip> 
using namespace std;
const int  print_size_clocks = 9;
const int  print_size_seconds = 5;
const int  title_fill_size = 52;
const char title_fill_char = '=';
template<typename T>
void RandomChecking(int MatrixSize){
	Strassen_class<T> stra;
	clock_t runtime_mul, runtime_divAndConq;
	stra.partition = 1;
	T** MatrixA = stra.FillMatrix(MatrixSize, MatrixSize+1);
	T** MatrixB = stra.FillMatrix(MatrixSize, MatrixSize+1);
	cout<<setiosflags(ios::left)
	    <<setw(MatrixSize*4+3)<<"\n矩阵A:"
	    <<setw(MatrixSize*4+3)<<"矩阵B:\n"; 
	stra.PrintMatrix(MatrixA,MatrixB, MatrixSize);

  stra.addition = 0;
  stra.multiplication = 0;
  runtime_mul = clock();
	T** R1 = stra.MUL(MatrixA,MatrixB, MatrixSize,MatrixSize,MatrixSize, false,false);
	runtime_mul = clock() - runtime_mul;
	long long add_mul = stra.addition;
	long long mul_mul = stra.multiplication;
	
	stra.addition = 0;
  stra.multiplication = 0;
  runtime_divAndConq = clock();
	T** R2 = stra.DivAndConq(MatrixSize, MatrixA,MatrixB, false,false);
	runtime_divAndConq = clock() - runtime_divAndConq; 
	
  long long add_divAndConq = stra.addition;
  long long mul_divAndConq = stra.multiplication; 
  clock_t runtime_strassen;
  stra.addition = 0;
  stra.multiplication = 0;
  runtime_strassen = clock();
  T** R3 = stra.Strassen(MatrixSize, MatrixA,MatrixB, true,true);
  runtime_strassen = clock() - runtime_strassen;
	cout<<setiosflags(ios::left)
	    <<setw(MatrixSize*4+3)<<setiosflags(ios::left)<<"普通矩阵乘法:"
	    <<setw(MatrixSize*4+3)<<setiosflags(ios::left)<<"分治矩阵算法:"
	    <<setw(MatrixSize*4+3)<<setiosflags(ios::left)<<"Strassen算法:\n";
  stra.PrintMatrix(R1,R2,R3, MatrixSize);
  cout<<"普通矩阵乘法:"
      <<" | 运行时钟数:"<<setw(print_size_seconds)<<runtime_mul
	    <<" | 加法次数:"<<setw(print_size_seconds)<<add_mul
	    <<" | 乘法次数:"<<setw(print_size_seconds)<<mul_mul<<endl;
  cout<<"分治矩阵算法:"
      <<" | 运行时钟数:"<<setw(print_size_seconds)<<runtime_divAndConq
	    <<" | 加法次数:"<<setw(print_size_seconds)<<add_divAndConq
	    <<" | 乘法次数:"<<setw(print_size_seconds)<<mul_divAndConq<<endl;
  cout<<"Strassen算法:"
      <<" | 运行时钟数:"<<setw(print_size_seconds)<<runtime_strassen
	    <<" | 加法次数:"<<setw(print_size_seconds)<<stra.addition
	    <<" | 乘法次数:"<<setw(print_size_seconds)<<stra.multiplication<<endl;
		    
	for (int i = 0; i < MatrixSize; ++i)delete []R1[i];delete []R1;
	for (int i = 0; i < MatrixSize; ++i)delete []R2[i];delete []R2;
  for (int i = 0; i < MatrixSize; ++i)delete []R3[i];delete []R3;
}
template<typename T>
void MatrixMultiplication(int MatrixSize, int partition){
	Strassen_class<T> stra;
	stra.partition = partition;
	clock_t startTime, endTime; 
	
	cout<<setfill(' '); 
	cout<<"【矩阵规模】: "<<setw(5)<<MatrixSize<<endl;
	
	srand(time(0));
	//*******************Strassen multiplication test
	cout<<" | Strassen算法:";
  T** MatrixA = stra.FillMatrix(MatrixSize);
  T** MatrixB = stra.FillMatrix(MatrixSize);
  stra.addition = 0;
  stra.multiplication = 0;
	startTime = clock();
  T** MatrixC = stra.Strassen(MatrixSize, MatrixA, MatrixB, true,true);
  endTime = clock();
  for (int i = 0; i < MatrixSize; ++i)delete []MatrixC[i];delete []MatrixC;
	cout<<setiosflags(ios::right)
	    <<setw(print_size_clocks)<<(endTime - startTime)<<" Clocks.."
	  	<<setw(print_size_seconds)<<(endTime - startTime)/CLOCKS_PER_SEC<<" Seconds"
	  	<<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
	  	<<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	
	//*******************conventional multiplication test
	cout<<" | 分治矩阵算法:";
  MatrixA = stra.FillMatrix(MatrixSize);
  MatrixB = stra.FillMatrix(MatrixSize);
  stra.addition = 0;
  stra.multiplication = 0;
	startTime = clock();
  MatrixC = stra.DivAndConq(MatrixSize, MatrixA, MatrixB, true,true);
  endTime = clock();	
  for (int i = 0; i < MatrixSize; ++i)delete []MatrixC[i];delete []MatrixC;
	cout<<setiosflags(ios::right)
	    <<setw(print_size_clocks)<<(endTime - startTime)<<" Clocks.."
	  	<<setw(print_size_seconds)<<(endTime - startTime)/CLOCKS_PER_SEC<<" Seconds" 
	  	<<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
	  	<<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	    
} 
void DataTypeExperiment(int initial_matrix_size, int maximum_matrix_size, int partition){
	int type;
	cout<<"\n+++++++++数据类型实验+++++++++\n"; 
	cout<<"\nStrassen算法与分治算法的比较。\n";
	cout<<"1.bool\n2.char\n3.int\n4.long\n5.float\n6.double\n"
			<<"请选择需要实验的矩阵元素数据类型:";
	cin>>type; 

	cout<<"\n//"<<setfill(title_fill_char)<<setw(title_fill_size)<<title_fill_char;
	switch ( type ){
		case 1:cout<<"bool运算";break;
		default:
		case 2:cout<<"char运算";break;
		case 3:cout<<"int运算";break;
		case 4:cout<<"long运算";break;
		case 5:cout<<"float运算";break;
		case 6:cout<<"double运算";break;
	}
	cout<<setfill(title_fill_char)<<setw(title_fill_size)<<title_fill_char<<"//\n";
	cout<<"\n实验将对";
	int base;
	for ( base = initial_matrix_size ; base*2 <= maximum_matrix_size ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"这些规模的矩阵进行实验。\n每种情况，只运行1次。\n";
	for ( base = initial_matrix_size ; base <= maximum_matrix_size ; base *= 2 ){
		switch ( type ){
			case 1:MatrixMultiplication<bool>  (base, partition);break;
			default:  
			case 2:MatrixMultiplication<char>  (base, partition);break;
			case 3:MatrixMultiplication<int>   (base, partition);break;
			case 4:MatrixMultiplication<long>  (base, partition);break;
			case 5:MatrixMultiplication<float> (base, partition);break;
			case 6:MatrixMultiplication<double>(base, partition);break;
		}
	}
}
void PartitionExperiment(int initial_partition, int maximum_partition, int MatrixSize){
	Strassen_class<char> stra;
	clock_t startTime, endTime;
	cout<<"\n+++++++++分治下限实验+++++++++\n"; 

	int run_times = 1;
	cout<<"\n实验将对";
	int base;
	for ( base = initial_partition ; base*2 <= maximum_partition ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"这些分治下限下的Strassen算法与分治算法进行实验。\n";
	cout<<"\n【矩阵规模】:"<<MatrixSize<<endl;
	cout<<"实验使用char类型作为矩阵元素数据类型。\n"; 
	srand(time(0));
	cout<<"【Strassen算法】\n";
	for ( base = initial_partition ; base <= maximum_partition ; base *= 2 ){
	  cout<<"分治下限:"<<setfill(' ')<<setw(3)<<base<<endl;
	  cout<<" | 运行时间:";
	  stra.partition = base;
		char** MatrixA = stra.FillMatrix(MatrixSize, 5);
		char** MatrixB = stra.FillMatrix(MatrixSize, 5);
		stra.addition = 0;
		stra.multiplication = 0;
		startTime = clock();
		char** MatrixC = stra.Strassen(MatrixSize,MatrixA,MatrixB,true,true);
		endTime = clock();
	  for (int i = 0; i < MatrixSize; ++i)delete []MatrixC[i];delete []MatrixC;
		cout<<setiosflags(ios::right)
		    <<setw(print_size_clocks)<<(endTime - startTime)<<" Clocks.. "
				<<setw(print_size_seconds)<<(endTime - startTime)/CLOCKS_PER_SEC<<" Seconds"
	     	<<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
	  	  <<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	}
	cout<<"【分治矩阵算法】\n";
	for ( base = initial_partition ; base <= maximum_partition ; base *= 2 ){
	  cout<<"分治下限:"<<setfill(' ')<<setw(3)<<base<<endl;
	  cout<<" | 运行时间:";
	  stra.partition = base;
		char** MatrixA = stra.FillMatrix(MatrixSize, 5);
		char** MatrixB = stra.FillMatrix(MatrixSize, 5);
		stra.addition = 0;
		stra.multiplication = 0;
		startTime = clock();
		char** MatrixC = stra.DivAndConq(MatrixSize,MatrixA,MatrixB,true,true);
		endTime = clock();
	  for (int i = 0; i < MatrixSize; ++i)delete []MatrixC[i];delete []MatrixC;
		cout<<setiosflags(ios::right)
		    <<setw(print_size_clocks)<<(endTime - startTime)<<" Clocks.. "
				<<setw(print_size_seconds)<<(endTime - startTime)/CLOCKS_PER_SEC<<" Seconds"
	     	<<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
	  	  <<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	}
}
void AlgorithmExperiment(int initial_matrix_size, int maximum_matrix_size, int partition){
	Strassen_class<char> stra;
	stra.partition = partition;
	clock_t startTime, endTime;
	srand(time(0));
	cout<<"\n++++++++++++++++++三种算法实验++++++++++++++++++\n"; 
	cout<<"\n实验将对";
	int base;
	for (base = initial_matrix_size ; base*2 <= maximum_matrix_size ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"这些规模的矩阵进行实验。\n";

	for (base = initial_matrix_size; base <= maximum_matrix_size; base *= 2){
	  cout<<setfill(' '); 
	  cout<<"\n【矩阵规模】: "<<setw(5)<<base<<endl;

		cout<<" | Strassen算法:";
		cout<<" | 运行时间:"; 
		stra.addition = 0;
		stra.multiplication = 0; 
		char** MatrixA = stra.FillMatrix(base);
		char** MatrixB = stra.FillMatrix(base);
		startTime = clock();
		char** MatrixC = stra.Strassen(base, MatrixA, MatrixB, true,true);
		endTime = clock();
		for (int i = 0; i < base; ++i)delete []MatrixC[i];delete []MatrixC;
		cout<<setiosflags(ios::right)
		    <<setw(print_size_clocks)<<(endTime - startTime)<<" Clocks.."
		  	<<setw(print_size_seconds)<<(endTime - startTime)/CLOCKS_PER_SEC<<" Seconds"
		    <<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
		    <<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;

		cout<<" | 分治矩阵算法:";
		cout<<" | 运行时间:"; 
		stra.addition = 0;
		stra.multiplication = 0; 
		MatrixA = stra.FillMatrix(base);
		MatrixB = stra.FillMatrix(base);
		startTime = clock();
		MatrixC = stra.DivAndConq(base, MatrixA, MatrixB, true,true);
		endTime = clock();
		for (int i = 0; i < base; ++i)delete []MatrixC[i];delete []MatrixC;
		cout<<setiosflags(ios::right)
		    <<setw(print_size_clocks)<<(endTime - startTime)<<" Clocks.."
		  	<<setw(print_size_seconds)<<(endTime - startTime)/CLOCKS_PER_SEC<<" Seconds"
		    <<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
		    <<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;

		cout<<" | 普通矩阵乘法:";
		cout<<" | 运行时间:"; 
		stra.addition = 0;
		stra.multiplication = 0; 
		MatrixA = stra.FillMatrix(base);
		MatrixB = stra.FillMatrix(base);
		startTime = clock();
		MatrixC = stra.MUL(MatrixA, MatrixB, base,base,base, true,true);
		endTime = clock();
		for (int i = 0; i < base; ++i)delete []MatrixC[i];delete []MatrixC;
		cout<<setiosflags(ios::right)
		    <<setw(print_size_clocks)<<(endTime - startTime)<<" Clocks.."
		  	<<setw(print_size_seconds)<<(endTime - startTime)/CLOCKS_PER_SEC<<" Seconds"
		    <<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
		    <<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	} 
}
void OneChoiceTesting(){
	cout<<"\n-------------单次实验-------------\n"; 
	Strassen_class<char> stra; 
	clock_t runtime;
	int algorithm, size;
	cout<<"[1].Strassen算法\n"<<"[2].分治矩阵算法\n[3].普通矩阵乘法\n";
	cout<<"请选择实验的算法：";
	cin>>algorithm;
	cout<<"请输入矩阵规模：";  
	cin>>size;
	char** MatrixA = stra.FillMatrix(size);
	char** MatrixB = stra.FillMatrix(size);
	char** MatrixC;
	runtime = clock();
	switch (algorithm){
		default:
		case 1:{
			cout<<"......正在使用Strassen算法求解规模为["<<size<<'x'<<size<<"]的矩阵乘法运算......\n";
		  cout<<"Strassen算法：运行时间："; 
			MatrixC = stra.Strassen(size,MatrixA,MatrixB,true,true);
			break;
		}
		case 2:{
			cout<<"......正在使用分治矩阵算法求解规模为["<<size<<'x'<<size<<"]的矩阵乘法运算......\n";
		  cout<<"分治矩阵算法：运行时间："; 
			MatrixC = stra.DivAndConq(size,MatrixA,MatrixB,true,true);
			break;
		}
		case 3:{
			cout<<"......正在使用普通矩阵乘法求解规模为["<<size<<'x'<<size<<"]的矩阵乘法运算......\n";
		  cout<<"普通矩阵乘法：运行时间："; 
			MatrixC = stra.MUL(MatrixA,MatrixB,size,size,size,true,true);
			break;
		}
	}
	runtime = clock() - runtime;
	for (int i = 0; i < size; ++i)delete []MatrixC[i];delete []MatrixC;
	cout<<setiosflags(ios::right)
	    <<setw(print_size_clocks)<<runtime<<" Clocks.."
	  	<<setw(print_size_seconds)<<runtime/CLOCKS_PER_SEC<<" Seconds"
	    <<" | 加法次数:"<<setiosflags(ios::scientific)<<stra.addition
	    <<" | 乘法次数:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
}
void ReverseTesting(int initial_matrix_size, int maximum_matrix_size){
	Strassen_class<char> stra;
	clock_t runtime;
	srand(time(0));
	cout<<"\n++++++++++++++++++矩阵转置实验++++++++++++++++++\n"; 
	cout<<"\n实验将对";
	int base;
	for (base = initial_matrix_size ; base*2 <= maximum_matrix_size ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"这些规模的矩阵进行普通矩阵乘法实验。\n";
	cout<<"\n实验将分开对B矩阵的转置与否进行实验比较。\n"; 

	for (base = initial_matrix_size; base <= maximum_matrix_size; base *= 2){
	  cout<<setfill(' '); 
	  cout<<"\n【矩阵规模】: "<<setw(5)<<base<<endl;
		char** MatrixA = stra.FillMatrix(base);
		char** MatrixB = stra.FillMatrix(base);

		cout<<" | 原本矩阵:";
		cout<<" 运行时间:"; 
		stra.addition = 0;
		stra.multiplication = 0; 
		runtime = clock();
		char** MatrixC = stra.MUL(MatrixA,MatrixB, base,base,base, false,false);
		runtime = clock() - runtime;
		for (int i = 0; i < base; ++i)delete []MatrixC[i];delete []MatrixC;
		cout<<setiosflags(ios::right)
		    <<setw(print_size_clocks)<<runtime<<" Clocks.."
		  	<<setw(print_size_seconds)<<runtime/CLOCKS_PER_SEC<<" Seconds";
		  	
		stra.reverse = true;
		stra.ReverseMatrix(MatrixB,base);

		cout<<" | 转置矩阵:";
		cout<<" 运行时间:"; 
		stra.addition = 0;
		stra.multiplication = 0; 
		runtime = clock();
		MatrixC = stra.MUL(MatrixA,MatrixB, base,base,base, true,true);
		runtime = clock() - runtime;
		for (int i = 0; i < base; ++i)delete []MatrixC[i];delete []MatrixC;
		cout<<setiosflags(ios::right)
		    <<setw(print_size_clocks)<<runtime<<" Clocks.."
		  	<<setw(print_size_seconds)<<runtime/CLOCKS_PER_SEC<<" Seconds\n";
	} 
}
int main(){
	while (true){
	  cout<<"==============================================分割线===================================================\n";
		int choice;
		cout<<"[1].检验\n"<<"[2].矩阵规模实验\n[3].分治下限实验\n[4].三种算法比较\n[5].输入指定规模与算法\n[6].矩阵转置实验\n[7].退出程序\n"
		    <<"请输入实验模式[]:";
		cin>>choice;
		switch (choice){
			default: 
			case 1:{
				int size;
				cout<<"使用普通乘法求出的结果，验证分治算法和Strassen算法求出的结果。\n"
				    <<"请输入矩阵规模（建议使用偶数规模）:";
				cin>>size;
				RandomChecking<int>(size);
				break;
			}
			case 2:{
				const int initial_matrix_size = 64;
				const int maximum_matrix_size = 16384;
				const int parition = 128;
			  DataTypeExperiment(initial_matrix_size,maximum_matrix_size, parition); 
				break;
			}
			case 3:{
				const int initial_parition = 1;
				const int maximum_parition = 2048;
				const int matrix_size = 2048;
				PartitionExperiment(initial_parition,maximum_parition, matrix_size);
				break;
			}
			case 4:{
				const int initial_matrix_size = 64;
				const int maximum_matrix_size = 16384;
				const int partition = 128;
				AlgorithmExperiment(initial_matrix_size,maximum_matrix_size,partition);
				break;
			}
			case 5:{
				OneChoiceTesting();
				break;
			}
			case 6:{
				const int initial_matrix_size = 128;
				const int maximum_matrix_size = 8192;
				ReverseTesting(initial_matrix_size,maximum_matrix_size);
				break;
			}
			case 7:{
  			system("Pause");
  			system("Pause");
				break;
			} 
		} 
	}
	return 0;
}
