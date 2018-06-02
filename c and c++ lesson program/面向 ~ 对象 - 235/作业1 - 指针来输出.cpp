/*
编写程序，将用户输入的n个整数存放到数组a中，
n由用户指定。然后利用指针操作依次输出该数组每个元素的值。 
*/
# include <stdio.h>
int main()
{
	int i,n;
	int a[9999];
	int *pa;
	scanf("%d",&n);
	pa = a;
	for ( i = 0 ; i < n ; i ++ )
	{
		scanf("%d",&a[i]);
		printf("a[%d] = %d\n",i,*(pa+i));
	}
	return 0;
}