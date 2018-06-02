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
	    <<setw(MatrixSize*4+3)<<"\n����A:"
	    <<setw(MatrixSize*4+3)<<"����B:\n"; 
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
	    <<setw(MatrixSize*4+3)<<setiosflags(ios::left)<<"��ͨ����˷�:"
	    <<setw(MatrixSize*4+3)<<setiosflags(ios::left)<<"���ξ����㷨:"
	    <<setw(MatrixSize*4+3)<<setiosflags(ios::left)<<"Strassen�㷨:\n";
  stra.PrintMatrix(R1,R2,R3, MatrixSize);
  cout<<"��ͨ����˷�:"
      <<" | ����ʱ����:"<<setw(print_size_seconds)<<runtime_mul
	    <<" | �ӷ�����:"<<setw(print_size_seconds)<<add_mul
	    <<" | �˷�����:"<<setw(print_size_seconds)<<mul_mul<<endl;
  cout<<"���ξ����㷨:"
      <<" | ����ʱ����:"<<setw(print_size_seconds)<<runtime_divAndConq
	    <<" | �ӷ�����:"<<setw(print_size_seconds)<<add_divAndConq
	    <<" | �˷�����:"<<setw(print_size_seconds)<<mul_divAndConq<<endl;
  cout<<"Strassen�㷨:"
      <<" | ����ʱ����:"<<setw(print_size_seconds)<<runtime_strassen
	    <<" | �ӷ�����:"<<setw(print_size_seconds)<<stra.addition
	    <<" | �˷�����:"<<setw(print_size_seconds)<<stra.multiplication<<endl;
		    
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
	cout<<"�������ģ��: "<<setw(5)<<MatrixSize<<endl;
	
	srand(time(0));
	//*******************Strassen multiplication test
	cout<<" | Strassen�㷨:";
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
	  	<<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
	  	<<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	
	//*******************conventional multiplication test
	cout<<" | ���ξ����㷨:";
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
	  	<<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
	  	<<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	    
} 
void DataTypeExperiment(int initial_matrix_size, int maximum_matrix_size, int partition){
	int type;
	cout<<"\n+++++++++��������ʵ��+++++++++\n"; 
	cout<<"\nStrassen�㷨������㷨�ıȽϡ�\n";
	cout<<"1.bool\n2.char\n3.int\n4.long\n5.float\n6.double\n"
			<<"��ѡ����Ҫʵ��ľ���Ԫ����������:";
	cin>>type; 

	cout<<"\n//"<<setfill(title_fill_char)<<setw(title_fill_size)<<title_fill_char;
	switch ( type ){
		case 1:cout<<"bool����";break;
		default:
		case 2:cout<<"char����";break;
		case 3:cout<<"int����";break;
		case 4:cout<<"long����";break;
		case 5:cout<<"float����";break;
		case 6:cout<<"double����";break;
	}
	cout<<setfill(title_fill_char)<<setw(title_fill_size)<<title_fill_char<<"//\n";
	cout<<"\nʵ�齫��";
	int base;
	for ( base = initial_matrix_size ; base*2 <= maximum_matrix_size ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"��Щ��ģ�ľ������ʵ�顣\nÿ�������ֻ����1�Ρ�\n";
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
	cout<<"\n+++++++++��������ʵ��+++++++++\n"; 

	int run_times = 1;
	cout<<"\nʵ�齫��";
	int base;
	for ( base = initial_partition ; base*2 <= maximum_partition ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"��Щ���������µ�Strassen�㷨������㷨����ʵ�顣\n";
	cout<<"\n�������ģ��:"<<MatrixSize<<endl;
	cout<<"ʵ��ʹ��char������Ϊ����Ԫ���������͡�\n"; 
	srand(time(0));
	cout<<"��Strassen�㷨��\n";
	for ( base = initial_partition ; base <= maximum_partition ; base *= 2 ){
	  cout<<"��������:"<<setfill(' ')<<setw(3)<<base<<endl;
	  cout<<" | ����ʱ��:";
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
	     	<<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
	  	  <<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	}
	cout<<"�����ξ����㷨��\n";
	for ( base = initial_partition ; base <= maximum_partition ; base *= 2 ){
	  cout<<"��������:"<<setfill(' ')<<setw(3)<<base<<endl;
	  cout<<" | ����ʱ��:";
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
	     	<<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
	  	  <<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	}
}
void AlgorithmExperiment(int initial_matrix_size, int maximum_matrix_size, int partition){
	Strassen_class<char> stra;
	stra.partition = partition;
	clock_t startTime, endTime;
	srand(time(0));
	cout<<"\n++++++++++++++++++�����㷨ʵ��++++++++++++++++++\n"; 
	cout<<"\nʵ�齫��";
	int base;
	for (base = initial_matrix_size ; base*2 <= maximum_matrix_size ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"��Щ��ģ�ľ������ʵ�顣\n";

	for (base = initial_matrix_size; base <= maximum_matrix_size; base *= 2){
	  cout<<setfill(' '); 
	  cout<<"\n�������ģ��: "<<setw(5)<<base<<endl;

		cout<<" | Strassen�㷨:";
		cout<<" | ����ʱ��:"; 
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
		    <<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
		    <<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;

		cout<<" | ���ξ����㷨:";
		cout<<" | ����ʱ��:"; 
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
		    <<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
		    <<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;

		cout<<" | ��ͨ����˷�:";
		cout<<" | ����ʱ��:"; 
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
		    <<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
		    <<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
	} 
}
void OneChoiceTesting(){
	cout<<"\n-------------����ʵ��-------------\n"; 
	Strassen_class<char> stra; 
	clock_t runtime;
	int algorithm, size;
	cout<<"[1].Strassen�㷨\n"<<"[2].���ξ����㷨\n[3].��ͨ����˷�\n";
	cout<<"��ѡ��ʵ����㷨��";
	cin>>algorithm;
	cout<<"����������ģ��";  
	cin>>size;
	char** MatrixA = stra.FillMatrix(size);
	char** MatrixB = stra.FillMatrix(size);
	char** MatrixC;
	runtime = clock();
	switch (algorithm){
		default:
		case 1:{
			cout<<"......����ʹ��Strassen�㷨����ģΪ["<<size<<'x'<<size<<"]�ľ���˷�����......\n";
		  cout<<"Strassen�㷨������ʱ�䣺"; 
			MatrixC = stra.Strassen(size,MatrixA,MatrixB,true,true);
			break;
		}
		case 2:{
			cout<<"......����ʹ�÷��ξ����㷨����ģΪ["<<size<<'x'<<size<<"]�ľ���˷�����......\n";
		  cout<<"���ξ����㷨������ʱ�䣺"; 
			MatrixC = stra.DivAndConq(size,MatrixA,MatrixB,true,true);
			break;
		}
		case 3:{
			cout<<"......����ʹ����ͨ����˷�����ģΪ["<<size<<'x'<<size<<"]�ľ���˷�����......\n";
		  cout<<"��ͨ����˷�������ʱ�䣺"; 
			MatrixC = stra.MUL(MatrixA,MatrixB,size,size,size,true,true);
			break;
		}
	}
	runtime = clock() - runtime;
	for (int i = 0; i < size; ++i)delete []MatrixC[i];delete []MatrixC;
	cout<<setiosflags(ios::right)
	    <<setw(print_size_clocks)<<runtime<<" Clocks.."
	  	<<setw(print_size_seconds)<<runtime/CLOCKS_PER_SEC<<" Seconds"
	    <<" | �ӷ�����:"<<setiosflags(ios::scientific)<<stra.addition
	    <<" | �˷�����:"<<setiosflags(ios::scientific)<<stra.multiplication<<endl;
}
void ReverseTesting(int initial_matrix_size, int maximum_matrix_size){
	Strassen_class<char> stra;
	clock_t runtime;
	srand(time(0));
	cout<<"\n++++++++++++++++++����ת��ʵ��++++++++++++++++++\n"; 
	cout<<"\nʵ�齫��";
	int base;
	for (base = initial_matrix_size ; base*2 <= maximum_matrix_size ; base *= 2 ){
		cout<<base<<','; 
	} 
	cout<<base<<"��Щ��ģ�ľ��������ͨ����˷�ʵ�顣\n";
	cout<<"\nʵ�齫�ֿ���B�����ת��������ʵ��Ƚϡ�\n"; 

	for (base = initial_matrix_size; base <= maximum_matrix_size; base *= 2){
	  cout<<setfill(' '); 
	  cout<<"\n�������ģ��: "<<setw(5)<<base<<endl;
		char** MatrixA = stra.FillMatrix(base);
		char** MatrixB = stra.FillMatrix(base);

		cout<<" | ԭ������:";
		cout<<" ����ʱ��:"; 
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

		cout<<" | ת�þ���:";
		cout<<" ����ʱ��:"; 
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
	  cout<<"==============================================�ָ���===================================================\n";
		int choice;
		cout<<"[1].����\n"<<"[2].�����ģʵ��\n[3].��������ʵ��\n[4].�����㷨�Ƚ�\n[5].����ָ����ģ���㷨\n[6].����ת��ʵ��\n[7].�˳�����\n"
		    <<"������ʵ��ģʽ[]:";
		cin>>choice;
		switch (choice){
			default: 
			case 1:{
				int size;
				cout<<"ʹ����ͨ�˷�����Ľ������֤�����㷨��Strassen�㷨����Ľ����\n"
				    <<"����������ģ������ʹ��ż����ģ��:";
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
