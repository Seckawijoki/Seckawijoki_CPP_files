# include <stdio.h>
int main()
{
	char c;
/* Note that getchar reads from stdin and
is line buffered; this means it will
not return until you press ENTER. */
	while ( ( c = getchar() ) != EOF )
	{
		printf("%c",c);
	}
	return 0;
}
