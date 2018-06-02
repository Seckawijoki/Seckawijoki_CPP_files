# include <iostream>
# include <cstdio>
# include <time.h>
using namespace std;

const int maxSize = 14;
bool queenIsSet[maxSize][maxSize];
int size = 10;
int count = 0;
void setSize( int length ){
	size = length;
}
void display(){
	printf("��%2d���⣺\n", count);
	for ( int i = 0 ; i < size ; ++i ){
		for ( int j = 0 ; j < size ; ++j )
			if ( queenIsSet[j][i] )
				printf("Q ");
			else
				printf("_ ");
		printf("\n");
	}
}
void reset(){
	for ( int i = 0 ; i < size ; ++i )
	for ( int j = 0 ; j < size ; ++j )
		queenIsSet[i][j] = false;
}

bool isCorrect( int x0, int y0 ) {
	int x, y;
	for (x = x0, y = 0; y < size; ++y)
		if (queenIsSet[x][y] == true && y != y0)
			return false;// �ж���
	for (y = y0, x = 0; x < size; ++x)
		if (queenIsSet[x][y] == true && x != x0)
			return false;// �ж���
	for (x = x0 - 1, y = y0 - 1; x >= 0 && y >= 0; --x, --y)
		if (queenIsSet[x][y] == true)
			return false;// �ж����Ϸ�
	for (x = x0 + 1, y = y0 + 1; x < size && y < size; ++x, ++y)
		if (queenIsSet[x][y] == true)
			return false;// �ж����·�
	for (x = x0 - 1, y = y0 + 1; x >= 0 && y < size; --x, ++y)
		if (queenIsSet[x][y] == true)
			return false;// �ж����·�
	for (x = x0 + 1, y = y0 - 1; x < size && y >= 0; ++x, --y)
		if (queenIsSet[x][y] == true)
			return false;// �ж����Ϸ�
	return true;// ���򷵻�
}
void traceBack( int y0 ){
	int i, k;
	if (y0 == size) {// �ݹ�����������õ�һ���⣬����Ļ����ʾ
		//++count;
		return;
	}
	for (i = 0; i < size; i++) {
		if (isCorrect(i, y0)) {// ���queenIsSet[i][y0]���Է��ûʺ�
			queenIsSet[i][y0] = true;// ���ûʺ�
			traceBack(y0 + 1);// �ݹ��������������ռ���
			queenIsSet[i][y0] = false;// ���������ʵ�ֻ��ݵ���һ��
		}
	}
}
bool traceBack_Manlifa( int x0, int y0 ){
	int i, k;
	if (y0 >= size) {// �ݹ����������
		return isCorrect(x0, y0);
	}
	for (i = 0; i < size; i++) {
			queenIsSet[y0][i] = true;// ���ûʺ�
			traceBack_Manlifa(i, y0 + 1);// �ݹ��������������ռ���
			queenIsSet[y0][i] = false;// ���������ʵ�ֻ��ݵ���һ��
	}
	return true;
}
int main(){
	long startTime, endTime;
	for ( int length = 4 ; length <= maxSize  ; ++length ){
		setSize(length);
		reset(); 
		startTime = clock();
		traceBack(0);
		endTime = clock();
		printf("����ģn = %2dʱ�����ݷ����N�ʺ�������ʱ(ms)��%d\n", length, (endTime - startTime) );
	}
	printf("======================================================================\n");
	for ( int length = 4 ; length <= maxSize  ; ++length ){
		setSize(length);
		reset(); 
		startTime = clock();
		traceBack_Manlifa(0, 0);
		endTime = clock();
		printf("����ģn = %2dʱ�����������N�ʺ�������ʱ(ms)��%d\n", length, (endTime - startTime) );
	}
	
}

