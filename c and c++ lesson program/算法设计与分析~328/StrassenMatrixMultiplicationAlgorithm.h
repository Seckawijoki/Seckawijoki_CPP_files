#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
template<typename T>
class Strassen_class{
public:
  int partition;//分治门槛，小于这个值时不再进行递归计算，而是采用常规矩阵计算方法
  long long addition;
  long long multiplication;
  bool reverse;
	Strassen_class(){
		partition = 128;
		addition = 0;
		multiplication = 0;
		reverse = false;
	}
  T**  ADD(T** MatrixA, T** MatrixB, int MatrixSize);
  T**  ADD_For_free(T** MatrixA, T** MatrixB, int MatrixSize);
  T**  SUB(T** MatrixA, T** MatrixB, int MatrixSize);
  T**  MUL(T** MatrixA,T** MatrixB, int s1,int s2,int s3,  bool free1,bool free2);
  T**  DivAndConq(int N, T **MatrixA, T **MatrixB, bool free1, bool free2);//朴素算法实现
  T**  Strassen(int N, T **MatrixA, T **MatrixB, bool free1, bool free2);//Strassen算法实现
  T**  FillMatrix(int length, int max);//随机产生矩阵 
  void PrintMatrix(T** Matrix, int MatrixSize);
  void PrintMatrix(T** MatrixA,T** MatrixB, int MatrixSize);
  void PrintMatrix(T** MatrixA,T** MatrixB,T** MatrixC, int MatrixSize);
  void ReverseMatrix(T** Matrix, int MatrixSize);
};
template<typename T>
T** Strassen_class<T>::ADD(T** MatrixA, T** MatrixB, int MatrixSize){
	addition = addition + MatrixSize * MatrixSize;
  T** MatrixResult = new T*[MatrixSize];
  for (int i = 0; i < MatrixSize; ++i){
  	MatrixResult[i] = new T[MatrixSize];
    for (int j = 0; j < MatrixSize; ++j){
      MatrixResult[i][j] =  MatrixA[i][j] + MatrixB[i][j];
    }
  }
  return MatrixResult;
}
template<typename T>
T** Strassen_class<T>::ADD_For_free(T** MatrixA, T** MatrixB, int MatrixSize){
  T** MatrixResult = ADD(MatrixA, MatrixB, MatrixSize);
  for (int i = 0; i < MatrixSize; ++i)delete []MatrixA[i];delete []MatrixA;
  for (int i = 0; i < MatrixSize; ++i)delete []MatrixB[i];delete []MatrixB;
  return MatrixResult;
}
template<typename T>
T** Strassen_class<T>::SUB(T** MatrixA, T** MatrixB, int MatrixSize){
	addition = addition + MatrixSize * MatrixSize;
  T** MatrixResult = new T*[MatrixSize];
  for ( int i = 0; i < MatrixSize; ++i){
  	MatrixResult[i] = new T[MatrixSize];
    for ( int j = 0; j < MatrixSize; ++j){
      MatrixResult[i][j] = MatrixA[i][j] - MatrixB[i][j];
    }
  }
  return MatrixResult;
}
template<typename T>
T** Strassen_class<T>::MUL(T** MatrixA,T** MatrixB, int s1,int s2,int s3, bool free1,bool free2){
	addition = addition + s1*s3 * (s2-1);
	multiplication = multiplication + s1*s3 * s2;
  T** MatrixResult = new T*[s1];
  if ( reverse ){
  	for (int i = 0; i < s1; ++i){
	  	MatrixResult[i] = new T[s3];
	    for (int j = 0; j < s3; ++j){
	      MatrixResult[i][j] = 0;
	      for (int k = 0; k < s2; ++k){
	        MatrixResult[i][j] = MatrixResult[i][j] + MatrixA[i][k] * MatrixB[j][k];
	      }
	    }
	  }
  } else {
  	for (int i = 0; i < s1; ++i){
	  	MatrixResult[i] = new T[s3];
	    for (int j = 0; j < s3; ++j){
	      MatrixResult[i][j] = 0;
	      for (int k = 0; k < s2; ++k){
	        MatrixResult[i][j] = MatrixResult[i][j] + MatrixA[i][k] * MatrixB[k][j];
	      }
	    }
	  }
  }
  
  if ( free1 ){
    for (int i = 0; i < s1; ++i)delete []MatrixA[i];delete []MatrixA;
  }
  if ( free2 ){
    for (int i = 0; i < s2; ++i)delete []MatrixB[i];delete []MatrixB;
  }
  return MatrixResult;
}
/*
  朴素矩阵算法 
*/
template<typename T>
T** Strassen_class<T>::DivAndConq(int N, T** MatrixA, T** MatrixB, bool free1, bool free2){
  if ( N <= partition ){
	return MUL(MatrixA,MatrixB, N,N,N, free1,free2);
  } else if (N%2 == 0){
		int newSize = N/2;
	
	  T** A = new T *[newSize];T** B = new T *[newSize];T** C = new T *[newSize];T** D = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  A[i] = new T[newSize];B[i] = new T[newSize];C[i] = new T[newSize];D[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
	      A[i][j] = MatrixA[i][j];B[i][j] = MatrixA[i][j + newSize];C[i][j] = MatrixA[i + newSize][j];D[i][j] = MatrixA[i + newSize][j + newSize];
		  }
		}
		if ( free1 ){
	    for (int i = 0; i < N; ++i)delete []MatrixA[i];delete []MatrixA;
		}
			  
	  T** E = new T *[newSize];T** F = new T *[newSize];T** G = new T *[newSize];T** H = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  E[i] = new T[newSize];F[i] = new T[newSize];G[i] = new T[newSize];H[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
		    E[i][j] = MatrixB[i][j];F[i][j] = MatrixB[i][j + newSize];G[i][j] = MatrixB[i + newSize][j];H[i][j] = MatrixB[i + newSize][j + newSize];
		  }
		}
		if ( free2 ){
	    for (int i = 0; i < N; ++i)delete []MatrixB[i];delete []MatrixB;
		}
	
	  T** C11;T** C12;T** C21;T** C22;
	  T** R1;T** R2;
		//here we calculate C11,C12,C21,C22 matrices .
		//C11 = A * E + B * G
		R1 = DivAndConq(newSize, A,E, false,false);
		R2 = DivAndConq(newSize, B,G, false,false);
		C11 = ADD_For_free(R1,R2, newSize); 

		//C12 = A * F + B * H
		R1 = DivAndConq(newSize, A,F, true,false);
		R2 = DivAndConq(newSize, B,H, true,false);
		C12 = ADD_For_free(R1,R2, newSize);
		
		//C21 = C * E + D * G
		R1 = DivAndConq(newSize, C,E, false,true);
		R2 = DivAndConq(newSize, D,G, false,true);
		C21 = ADD_For_free(R1,R2, newSize);
		
		//C22 = C * F + D * H
		R1 = DivAndConq(newSize, C,F, true,true);
		R2 = DivAndConq(newSize, D,H, true,true);
		C22 = ADD_For_free(R1,R2, newSize);
		
		T** MatrixC = new T*[N];for (int i = 0; i < N; ++i)MatrixC[i] = new T[N];
		for (int i = 0; i < newSize ; ++i){
		  for (int j = 0 ; j < newSize ; ++j){
		    MatrixC[i][j] = C11[i][j];
		    MatrixC[i][j + newSize] = C12[i][j];
		    MatrixC[i + newSize][j] = C21[i][j];
		    MatrixC[i + newSize][j + newSize] = C22[i][j];
		  }
		}

		for (int i = 0; i < newSize; ++i){
		  delete[] C11[i];delete[] C12[i];delete[] C21[i];delete[] C22[i];
		}
		delete[] C11;delete[] C12;delete[] C21;delete[] C22;
    return MatrixC;
  } else {
		int newSize = N/2;
	
	  T** A = new T *[newSize];T** B = new T *[newSize];T** C = new T *[newSize];T** D = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  A[i] = new T[newSize];B[i] = new T[newSize];C[i] = new T[newSize];D[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
	      A[i][j] = MatrixA[i][j];B[i][j] = MatrixA[i][j + newSize];C[i][j] = MatrixA[i + newSize][j];D[i][j] = MatrixA[i + newSize][j + newSize];
		  }
		}
		if ( free1 ){
	    for (int i = 0; i < N; ++i)delete []MatrixA[i];delete []MatrixA;
		}
			  
	  T** E = new T *[newSize];T** F = new T *[newSize];T** G = new T *[newSize];T** H = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  E[i] = new T[newSize];F[i] = new T[newSize];G[i] = new T[newSize];H[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
		    E[i][j] = MatrixB[i][j];F[i][j] = MatrixB[i][j + newSize];G[i][j] = MatrixB[i + newSize][j];H[i][j] = MatrixB[i + newSize][j + newSize];
		  }
		}
		if ( free2 ){
	    for (int i = 0; i < N; ++i)delete []MatrixB[i];delete []MatrixB;
		}
	
	  T** C11;T** C12;T** C21;T** C22;
	  T** R1;T** R2;
		//here we calculate C11,C12,C21,C22 matrices .
		//C11 = A * E + B * G
		R1 = DivAndConq(newSize, A,E, false,false);
		R2 = DivAndConq(newSize, B,G, false,false);
		C11 = ADD_For_free(R1,R2, newSize); 

		//C12 = A * F + B * H
		R1 = DivAndConq(newSize, A,F, true,false);
		R2 = DivAndConq(newSize, B,H, true,false);
		C12 = ADD_For_free(R1,R2, newSize);
		
		//C21 = C * E + D * G
		R1 = DivAndConq(newSize, C,E, false,true);
		R2 = DivAndConq(newSize, D,G, false,true);
		C21 = ADD_For_free(R1,R2, newSize);
		
		//C22 = C * F + D * H
		R1 = DivAndConq(newSize, C,F, true,true);
		R2 = DivAndConq(newSize, D,H, true,true);
		C22 = ADD_For_free(R1,R2, newSize);
		
		T** MatrixC = new T*[N];for (int i = 0; i < N; ++i)MatrixC[i] = new T[N];
		for (int i = 0; i < newSize ; ++i){
		  for (int j = 0 ; j < newSize ; ++j){
		    MatrixC[i][j] = C11[i][j];
		    MatrixC[i][j + newSize] = C12[i][j];
		    MatrixC[i + newSize][j] = C21[i][j];
		    MatrixC[i + newSize][j + newSize] = C22[i][j];
		  }
		}

		for (int i = 0; i < newSize; ++i){
		  delete[] C11[i];delete[] C12[i];delete[] C21[i];delete[] C22[i];
		}
		delete[] C11;delete[] C12;delete[] C21;delete[] C22;
    return MatrixC;
  }
}
/*
  Strassen矩阵乘法
*/
template<typename T>
T** Strassen_class<T>::Strassen(int N, T** MatrixA, T** MatrixB, bool free1, bool free2){
  if ( N <= partition ){
    return MUL(MatrixA,MatrixB, N,N,N, free1,free2);
  } 
  else if (N%2 == 0){
		int newSize = N/2;

	  T** A = new T *[newSize];T** B = new T *[newSize];T** C = new T *[newSize];T** D = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  A[i] = new T[newSize];B[i] = new T[newSize];C[i] = new T[newSize];D[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
	      A[i][j] = MatrixA[i][j];B[i][j] = MatrixA[i][j + newSize];C[i][j] = MatrixA[i + newSize][j];D[i][j] = MatrixA[i + newSize][j + newSize];
		  }
		}
	  if ( free1 ){
	 	  for (int i = 0; i < N; ++i)delete []MatrixA[i];delete []MatrixA;
	  }

	  T** E = new T *[newSize];T** F = new T *[newSize];T** G = new T *[newSize];T** H = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  E[i] = new T[newSize];F[i] = new T[newSize];G[i] = new T[newSize];H[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
	      E[i][j] = MatrixB[i][j];F[i][j] = MatrixB[i][j + newSize];G[i][j] = MatrixB[i + newSize][j];H[i][j] = MatrixB[i + newSize][j + newSize];
		  }
		}
		if ( free2 ){
	    for (int i = 0; i < N; ++i)delete []MatrixB[i];delete []MatrixB;
	  }

    //making that 1 diminsional pointer based array , a 2D pointer based array
    T** M1;T** M2;T** M3;T** M4;T** M5;T** M6;T** M7;
    T** R1;T** R2;

    //here we calculate M1..M7 matrices .
    //M1=(A+D)*(E+H)
    R1 = ADD(A,D, newSize);
    R2 = ADD(E,H, newSize);
    M1 = Strassen(newSize, R1,R2, true,true); 
    //M2=(C+D)*E
    R1 = ADD(C,D, newSize);
    M2 = Strassen(newSize, R1,E, true,false);
    //M3=A*(F-H)
    R2 = SUB(F,H, newSize);
    M3 = Strassen(newSize, A,R2, false,true);
    //M4=D*(G-E)
    R2 = SUB(G,E, newSize);
    M4 = Strassen(newSize, D,R2, false,true);
    //M5=(A+B)*H
    R1 = ADD(A,B, newSize);
    M5 = Strassen(newSize, R1,H, true,false);
    //M6=(C-A)(E+F)
    R1 = SUB(C,A, newSize);
    R2 = ADD(E,F, newSize);
    M6 = Strassen(newSize, R1,R2, true,true);
    //M7=(B-D)*(G+H)
    R1 = SUB(B,D, newSize);
    R2 = ADD(G,H, newSize);
    M7 = Strassen(newSize, R1,R2, true,true);

    for (int i = 0; i < newSize; ++i){
      delete[] A[i];delete[] B[i];delete[] C[i];delete[] D[i];
      delete[] E[i];delete[] F[i];delete[] G[i];delete[] H[i];
    }
		delete[] A;delete[] B;delete[] C;delete[] D;
		delete[] E;delete[] F;delete[] G;delete[] H;
    T** MatrixC = new T*[N];for (int i = 0; i < N; ++i)MatrixC[i] = new T[N]; 

    //at this point , we have calculated the c11..c22 matrices, and now we are going to
    //put them together and make a unit matrix which would describe our resulting Matrix.
    //组合小矩阵到一个大矩阵    
	  //C11 = M1 + M4 - M5 + M7;
    //C12 = M3 + M5;
    //C21 = M2 + M4;
    //C22 = M1 + M3 - M2 + M6;
    addition += newSize*newSize * 8;
    for (int i = 0; i < newSize ; ++i){
      for (int j = 0 ; j < newSize ; ++j){
        MatrixC[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
        MatrixC[i][j + newSize] = M3[i][j] + M5[i][j];
        MatrixC[i + newSize][j] = M2[i][j] + M4[i][j];
        MatrixC[i + newSize][j + newSize] = M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
      }
    }
    for (int i = 0; i < newSize; ++i){
      delete[] M1[i];delete[] M2[i];delete[] M3[i];delete[] M4[i];delete[] M5[i];delete[] M6[i];delete[] M7[i];
    }
    delete[] M1;delete[] M2;delete[] M3;delete[] M4;delete[] M5;delete[] M6;delete[] M7;

    
	  return MatrixC;
	  
  } else {

		int newSize = N/2;

    T** MatrixC = new T*[N];for (int i = 0; i < N; ++i)MatrixC[i] = new T[N]; 

	  T** A = new T *[newSize];T** B = new T *[newSize];T** C = new T *[newSize];T** D = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  A[i] = new T[newSize];B[i] = new T[newSize];C[i] = new T[newSize];D[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
	      A[i][j] = MatrixA[i][j];B[i][j] = MatrixA[i][j + newSize];C[i][j] = MatrixA[i + newSize][j];D[i][j] = MatrixA[i + newSize][j + newSize];
		  }
		}
		T** L12;T** L21;T** L22;
		if ( N%2 == 1 ){
			L12 = new T*[N-1];for (int i = 0; i < N-1; ++i)L12[i] = new T[1];
			L21 = new T*[1];L21[0] = new T[N-1];
			L22 = new T*[1];L22[0] = new T[0];
			for (int i = 0; i < N-1; ++i)L12[i][0] = MatrixA[N-1][i];
			for (int i = 0; i < N-1; ++i)L21[0][i] = MatrixA[i][N-1];
			L22[0][0] = MatrixA[N-1][N-1];
		}
		
	  T** E = new T *[newSize];T** F = new T *[newSize];T** G = new T *[newSize];T** H = new T *[newSize];
	  for (int i = 0; i < newSize; ++i){
		  E[i] = new T[newSize];F[i] = new T[newSize];G[i] = new T[newSize];H[i] = new T[newSize];
		  for (int j = 0; j < newSize; ++j){
	      E[i][j] = MatrixB[i][j];F[i][j] = MatrixB[i][j + newSize];G[i][j] = MatrixB[i + newSize][j];H[i][j] = MatrixB[i + newSize][j + newSize];
		  }
		}
		
		if ( N%2 == 1 ){
			T** R12 = new T*[N-1];for (int i = 0; i < N-1; ++i)R12[i] = new T[1];
			T** R21 = new T*[1];R21[0] = new T[N-1];
			T** R22 = new T*[1];R22[0] = new T[0];
			for (int i = 0; i < N-1; ++i)R12[i][0] = MatrixB[N-1][i];
			for (int i = 0; i < N-1; ++i)R21[0][i] = MatrixB[i][N-1];
			R22[0][0] = MatrixB[N-1][N-1];
		
		  T** P1;T** P2; 
			//计算因奇数规模带来的分割边缘矩阵的合并
			P2 = MUL(L12,R21, N-1,1,N-1, false,false);
			for (int i = 0; i < N-1; ++i)for (int j = 0; j < N-1; ++j)MatrixC[i][j] = P2[i][j];
			for (int i = 0; i < N-1; ++i)delete []P2[i];delete []P2;
			
			P1 = MUL(MatrixA,R12, N-1,N-1,1, false,false);
			P2 = MUL(L12,R22, N-1,1,1, false,false);
			for (int i = 0; i < N-1; ++i)MatrixC[i][N-1] = P1[i][0] + P2[i][0];
			for (int i = 0; i < N-1; ++i)delete []P1[i];delete []P1;
			for (int i = 0; i < N-1; ++i)delete []P2[i];delete []P2;
			
			P1 = MUL(MatrixA,R12, N-1,N-1,1, false,false);
			P2 = MUL(L12,R22, N-1,1,1, false,false);
		}
		
		if ( free1 ){
			for (int i = 0; i < N; ++i)delete []MatrixA[i];delete []MatrixA;
		}
		if ( free2 ){
	    for (int i = 0; i < N; ++i)delete []MatrixB[i];delete []MatrixB;
		}

    //making that 1 diminsional pointer based array , a 2D pointer based array
    T** M1;T** M2;T** M3;T** M4;T** M5;T** M6;T** M7;
    T** R1;T** R2;

    //here we calculate M1..M7 matrices .
    //M1=(A+D)*(E+H)
    R1 = ADD(A,D, newSize);
    R2 = ADD(E,H, newSize);
    M1 = Strassen(newSize, R1,R2, true,true);

    //M2=(C+D)*E
    R1 = ADD(C,D, newSize);
    M2 = Strassen(newSize, R1,E, true,false);

    //M3=A*(F-H)
    R2 = SUB(F,H, newSize);
    M3 = Strassen(newSize, A,R2, false,true);

    //M4=D*(G-E)
    R2 = SUB(G,E, newSize);
    M4 = Strassen(newSize, D,R2, false,true);

    //M5=(A+B)*H
    R1 = ADD(A,B, newSize);
    M5 = Strassen(newSize, R1,H, true,false);

    //M6=(C-A)(E+F)
    R1 = SUB(C,A, newSize);
    R2 = ADD(E,F, newSize);
    M6 = Strassen(newSize, R1,R2, true,true);

    //M7=(B-D)*(G+H)
    R1 = SUB(B,D, newSize);
    R2 = ADD(G,H, newSize);
    M7 = Strassen(newSize, R1,R2, true,true);

    for (int i = 0; i < newSize; ++i){
      delete[] A[i];delete[] B[i];delete[] C[i];delete[] D[i];
      delete[] E[i];delete[] F[i];delete[] G[i];delete[] H[i];
    }
		delete[] A;delete[] B;delete[] C;delete[] D;
		delete[] E;delete[] F;delete[] G;delete[] H;

    //at this point , we have calculated the c11..c22 matrices, and now we are going to
    //put them together and make a unit matrix which would describe our resulting Matrix.
    //组合小矩阵到一个大矩阵    
	  //C11 = M1 + M4 - M5 + M7;
    //C12 = M3 + M5;
    //C21 = M2 + M4;
    //C22 = M1 + M3 - M2 + M6;
    addition = addition + newSize * newSize * 8;
    for (int i = 0; i < newSize ; ++i){
      for (int j = 0 ; j < newSize ; ++j){
        MatrixC[i][j] += M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
        MatrixC[i][j + newSize] += M3[i][j] + M5[i][j];
        MatrixC[i + newSize][j] += M2[i][j] + M4[i][j];
        MatrixC[i + newSize][j + newSize] += M1[i][j] + M3[i][j] - M2[i][j] + M6[i][j];
      }
    }
    for (int i = 0; i < newSize; ++i){
      delete[] M1[i];delete[] M2[i];delete[] M3[i];delete[] M4[i];delete[] M5[i];delete[] M6[i];delete[] M7[i];
    }
    delete[] M1;delete[] M2;delete[] M3;delete[] M4;delete[] M5;delete[] M6;delete[] M7;

    
	  return MatrixC;
	 
  }

}

template<typename T>
T** Strassen_class<T>::FillMatrix(int length, int max = 5){
  T** Matrix = new T*[length];
  for(int row = 0; row<length; ++row){
    Matrix[row] = new T[length];
	  for(int column = 0; column<length; ++column){
	    Matrix[row][column] = rand() %max;
	  }
  }
  return Matrix;
}
template<typename T>
void Strassen_class<T>::PrintMatrix(T **Matrix, int MatrixSize){
  cout<<endl;
  for(int row = 0; row<MatrixSize; ++row){
    for(int column = 0; column<MatrixSize; ++column){
      cout<<setw(4)<<Matrix[row][column];
      if ((column+1)%((MatrixSize)) == 0)
      cout<<endl;
    }
  }
  cout<<endl;
}
template<typename T>
void Strassen_class<T>::PrintMatrix(T **MatrixA,T **MatrixB, int MatrixSize){
  cout<<endl;
  for(int row = 0; row<MatrixSize; ++row){
    for(int column = 0; column<MatrixSize; ++column){
      cout<<setw(4)<<MatrixA[row][column];
    }
    cout<<" | ";
    for(int column = 0; column<MatrixSize; ++column){
      cout<<setw(4)<<MatrixB[row][column];
      if ((column+1)%((MatrixSize)) == 0)cout<<endl;
    }
  }
  cout<<endl;
}
template<typename T>
void Strassen_class<T>::PrintMatrix(T **MatrixA,T **MatrixB,T **MatrixC, int MatrixSize){
  cout<<endl;
  for(int row = 0; row<MatrixSize; ++row){
    for(int column = 0; column<MatrixSize; ++column){
      cout<<setw(4)<<MatrixA[row][column];
    }
    cout<<" | ";
    for(int column = 0; column<MatrixSize; ++column){
      cout<<setw(4)<<MatrixB[row][column];
    }
    cout<<" | ";
    for(int column = 0; column<MatrixSize; ++column){
      cout<<setw(4)<<MatrixC[row][column];
      if ((column+1)%((MatrixSize)) == 0)cout<<endl;
    }
  }
  cout<<endl;
}
template<typename T>
void Strassen_class<T>::ReverseMatrix(T** Matrix, int MatrixSize){
	reverse = !reverse;
	T** temp = new T*[MatrixSize];
	for (int i = 0; i < MatrixSize; ++i){
		temp[i] = new T[MatrixSize];
		for (int j = 0; j < MatrixSize; ++j){
		  temp[i][j] = Matrix[i][j]; 
		}
	}
	for (int i = 0; i < MatrixSize; ++i){
		for (int j = 0; j < MatrixSize; ++j){
		  Matrix[i][j] = temp[j][i]; 
		}
	}
	for (int i = 0; i < MatrixSize; ++i)delete []temp[i];delete []temp;
} 
