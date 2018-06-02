# include <iostream> 
using namespace std; 
# define OK     1
# define ERROR  0
class SequenceList 
{ 
private: 
    int *array; 
    int length; 
public: 
    SequenceList() 
    { 
        array = NULL; 
        length = 0; 
    } 
    SequenceList( int *list, int size ) 
    { 
        int i; 
        length = size; 
        array = new int [length+1]; 
        for ( i = 1 ; i <= length ; ++i ) 
            array[i] = list[i]; 
    } 
    ~SequenceList() 
    { 
        delete [] array; 
    } 
	int SqList_Bisearching( int item, int *times, int *position )
	{
		int i;
		int low = 1;
		int high = length;
		int middle = length + 1;
		*times = 0;
		*position = 0;
		while ( low <= high )
		{
			++ *times;
			middle = ( low + high )/2;
			/**/ if ( item == array[middle] )
			{
				*position = middle;
				return OK;
			}
			else if ( item <  array[middle] )
				high = middle - 1;
			else if ( item >  array[middle] )
				low = middle + 1;
		}
		*position = 0;
		return ERROR;
	}
};
int main()
{
	int n, t, i, strayer, result;
	int *list, *questing_time, *locating_site;
	questing_time = new int ();
	locating_site = new int ();
	cin>>t;
	while ( t-- )
	{
		cin>>n;
		list = new int [n+1];
		for ( i = 1 ; i <= n ; ++i )
			cin>>list[i];
		SequenceList sequencial(list,n);
		cin>>strayer;
		result = sequencial.SqList_Bisearching(strayer,questing_time,locating_site);
		cout<<result<<' '<<*locating_site<<' '<<*questing_time<<endl;
	}
	delete [] list;
	delete questing_time;
	delete locating_site;
	return 0;
}
/*
题目描述
1、问题描述
在一个有序序列中，折半查找一个关键字；返回查找是否成功，如果成功，输入关键字所在的位置和查找次数。
 
2、查找算法
⑴、n个对象从小到大存放在有序顺序表BinList中，Key为给定值
⑵、设low、high指向待查元素所在区间的下界、上界，即low=1, high=BinListLen
⑶、设mid指向待查区间的中点，即mid=(low+high)/2?
⑷、让Key与mid指向的记录关键字比较
若Key=BinList[mid]，查找成功，结束
若Key<BinList[mid]，则high=mid-1       [上半区间]
若Key>BinList[mid]，则low=mid+1        [下半区间]
⑸、重复⑶、⑷操作，直至low>high时，查找失败。
 
输入
⑴、第一行：测试次数。
⑵、每个样本分2行：
第一行：第一个数字n表示样本数目，其后跟n个样本；
第二行：查找的关键字的值。

输出
查找是否成功（1—表示成功，0表示不成功），所在位置（0—表示不成功），查找次数。

样例输入
2
5 2 3 4 5 7
4
6 1 2 3 4 6 8
7

样例输出
1 3 1
0 0 3
*/
