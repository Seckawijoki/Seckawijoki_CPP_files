# include <stdio.h>
# include <stdlib.h>
# include <string.h>
int catstring( char *s1, char *s2, int len1, int len2 )
{
	char mybuf[256];
	if ( ( len1 + len2 ) > 256 ){
		printf("Exceed the maximum number of elements!\n");
		return -1;
	}
	memcpy(mybuf,s1,len1);
	memcpy(mybuf + len1, s2, len2);
	printf("Copy %d + %d = %d bytes to mybuf!\n",len1,len2,len1+len2);
	return 0;
}
int main()
{
	char* *argv = new char* [5];
	scanf("%s%c%s%c%s%c%s%c",argv[1],argv[2],argv[3],argv[4]);
	catstring(argv[1],argv[2],atoi(argv[3]),atoi(argv[4]));
	return 0;
}
