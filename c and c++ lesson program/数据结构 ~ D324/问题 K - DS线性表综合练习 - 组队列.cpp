# include <iostream>
# include <queue>
using namespace std;
int main()
{
	int n, i;
	return 0;
}
/*
题目描述
组队列是队列结构中一种常见的队列结构，在很多地方有着广泛应用。
组队列是是指队列内的元素分组聚集在一起。组队列包含两种命令：
1、 ENQUEUE，表示当有新的元素进入队列，首先会检索是否有同一组的元素已经存在，
	如果有，则新元素排在同组的最后，如果没有则插入队列末尾。
2、 DEQUEUE，表示队列头元素出队
3、 STOP，停止操作

建议使用C++自带的队列对象queue，编程更方便

输入
第1行输入一个t(t<=10)，表示1个队列中有多少个组
第2行输入一个第1组的元素个数和数值
第3行输入一个第2组的元素个数和数值，

以此类推输入完n组之后，开始输入多个操作命令(<200)，
例如输入ENQUEUE 100，表示把元素100插入队列
最后输入STOP，表示输入命令结束

输出
经过命令操作后队列的最终结果

样例输入
2
3 101 102 103
3 201 202 203
ENQUEUE 101
ENQUEUE 201
ENQUEUE 102
ENQUEUE 202
ENQUEUE 103
ENQUEUE 203
DEQUEUE
DEQUEUE
DEQUEUE
STOP

样例输出
201 202 203
*/

