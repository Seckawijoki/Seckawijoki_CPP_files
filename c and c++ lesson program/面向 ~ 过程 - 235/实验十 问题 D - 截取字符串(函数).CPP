# include <stdio.h>
# include <string.h>
int substr( char str1[] , char str2[] ,int index )
{
	int i,k,y;
	y = strlen(str1);
	k = strlen(str1) - index;
	if ( index >= y )
		return 0;
	else
		for ( i = 0 ; i < k ; i ++ )//从后面复制。不能用"strncpy()"。
			str2[i] = str1[i+index];
	str2[i] = '\0';//必须加。不然就“烫烫烫烫”
	return 1;

}
int main()
{
	int i = 0,n,x,k;
	char str1[33],str2[33];
	scanf("%d",&n);
	while ( n-- )
	{
		getchar();//过滤输入n的回车。
		gets(str1);
		scanf("%d",&x);
		if ( x < 0 )
		{
			printf("IndexError\n");//乱！乱！先判断x正负。
			continue;
		}
		k = substr(str1,str2,x);
		if ( k == 0 )
		{
			printf("IndexError\n");//在主函数输出为好。
			continue;
		}
		printf("%s\n",str2);
	}
	return 0;
}