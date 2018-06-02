# include <stdio.h>
int main()
{
    int a[3][3],t,b,c,i,j,tg;
    scanf("%d",&t);
    while ( t-- )
    {
        tg = 0;
        for ( i = 0 ; i < 3 ; i++ )
            for ( j = 0 ; j < 3 ; j++ )
                scanf("%d",&a[i][j]);
        for ( i = 0 ; i < 3 ; i++ )
        {
            if ( (a[i][0] >= a[i][1]) && (a[i][0] > a[i][2]) )
			{
				if ( (a[i][0] < a[(i+1)%3][0]) && (a[i][0] < a[(i+2)%3][0]) )
				{
					tg++;
					printf("%d 0 %d\n",i,a[i][0]);
				}
			
			}
			else if ( (a[i][1] > a[i][0]) && (a[i][1] > a[i][2]) )
			{
				if ( (a[i][1] < a[(i+1)%3][1]) && (a[i][1] < a[(i+2)%3][1]) )
				{
					tg++;
					printf("%d 1 %d\n",i,a[i][1]);
				}
			}

            else if ( a[i][2] > a[i][0] && a[i][2] > a[i][1] )
			{
				if ( (a[i][2] < a[(i+1)%3][2]) && (a[i][2] < a[(i+2)%3][2]) )
				{
					tg++;
					printf("%d 2 %d\n",i,a[i][2]);
				}
			}
		}
		if ( tg == 0 )
			printf("-1\n");
			
	}
    return 0;
}