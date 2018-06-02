/*
题目描述
有一种古典加密方法就是按照字母表顺序，把每个字母循环右移k位，从而转换为加密的另一个字母。
例如偏移2位，即A对应C，B对应D，……X对应Z，Y对应A，Z对应B；
同样a对于c，b对应d，……x对应z，y对应a，z对应b。
当前设定加密规则是：循环右移4位，
对于输入的字符，只对字母进行加密，字母区分大小写，
其他字符例如数字、标点符号等不做加密，直接输出。

输入
第一行输入T表示有T个测试实例
第二行输入一个字符串，字符串可以包含字母、数字、标点符号等
以此类推输入下一个数据

输出
输出加密后的字符串

样例输入
2
SZU1983
1949,china

样例输出
WDY1983
1949,glmre
*/
# include <stdio.h>
# include <string.h>
int encrypt( char str[] )
{
	int i,l = strlen(str);
	for ( i = 0 ; i < l ; i++ )
	{
		if      ( str[i] >= 'A' && str[i] <= 'Z' )
			str[i] = 'A' + ( str[i] - 'A' + 4 ) %26;

		else if ( str[i] >= 'a' && str[i] <= 'z' )
			str[i] = 'a' + ( str[i] - 'a' + 4 ) %26;
	}
	printf("%s\n",str);
	return 1;
}
int main()
{
	int t;
	char str[99];
	scanf("%d",&t);
	while ( t-- )
	{
		scanf("%s",str);
		encrypt(str);
	}
	return 0;
}