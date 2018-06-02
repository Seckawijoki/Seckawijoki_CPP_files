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
	printf("第%2d个解：\n", count);
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
			return false;// 判断列
	for (y = y0, x = 0; x < size; ++x)
		if (queenIsSet[x][y] == true && x != x0)
			return false;// 判断行
	for (x = x0 - 1, y = y0 - 1; x >= 0 && y >= 0; --x, --y)
		if (queenIsSet[x][y] == true)
			return false;// 判断左上方
	for (x = x0 + 1, y = y0 + 1; x < size && y < size; ++x, ++y)
		if (queenIsSet[x][y] == true)
			return false;// 判断右下方
	for (x = x0 - 1, y = y0 + 1; x >= 0 && y < size; --x, ++y)
		if (queenIsSet[x][y] == true)
			return false;// 判断左下方
	for (x = x0 + 1, y = y0 - 1; x < size && y >= 0; ++x, --y)
		if (queenIsSet[x][y] == true)
			return false;// 判断右上方
	return true;// 否则返回
}
void traceBack( int y0 ){
	int i, k;
	if (y0 == size) {// 递归结束条件。得到一个解，在屏幕上显示
		//++count;
		return;
	}
	for (i = 0; i < size; i++) {
		if (isCorrect(i, y0)) {// 如果queenIsSet[i][y0]可以放置皇后
			queenIsSet[i][y0] = true;// 放置皇后
			traceBack(y0 + 1);// 递归深度优先搜索解空间树
			queenIsSet[i][y0] = false;// 这句代码就是实现回溯到上一层
		}
	}
}
bool traceBack_Manlifa( int x0, int y0 ){
	int i, k;
	if (y0 >= size) {// 递归结束条件。
		return isCorrect(x0, y0);
	}
	for (i = 0; i < size; i++) {
			queenIsSet[y0][i] = true;// 放置皇后
			traceBack_Manlifa(i, y0 + 1);// 递归深度优先搜索解空间树
			queenIsSet[y0][i] = false;// 这句代码就是实现回溯到上一层
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
		printf("当规模n = %2d时，回溯法求解N皇后问题用时(ms)：%d\n", length, (endTime - startTime) );
	}
	printf("======================================================================\n");
	for ( int length = 4 ; length <= maxSize  ; ++length ){
		setSize(length);
		reset(); 
		startTime = clock();
		traceBack_Manlifa(0, 0);
		endTime = clock();
		printf("当规模n = %2d时，蛮力法求解N皇后问题用时(ms)：%d\n", length, (endTime - startTime) );
	}
	
}

