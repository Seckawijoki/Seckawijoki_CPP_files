# include <stdio.h>
# include <time.h> 
//#include <stdlib.h>
//srand( time( NULL ) );
int main() 
{ 
    int x,y,z,end,n,i,start = clock();
	char t; 
    kaishidedifang: 
	n = 0;
//	x = srand();
//	x = x %100 + 1;
    end = clock(); 
    z = (end - start) %23 + 6; 
    for ( i = 0 ; x != 1 && i <= ( z + 15 ) * ( z + 35 ) ; i++ ); 
    { 
        end = clock(); 
        x = (end - start) %78 + 4; 
    } 
	for ( i = 0 ; x != 1 && i <= ( z + 36 ) * ( z + 13 ) ; i++ ); 
    { 
        end = clock(); 
        x = (end - start) %69 + 4; 
    } 
    printf("\n现在电脑想了一个数。"); 
    printf("你来猜是多少?_?："); 
//  if ( getchar() == '\n' ) 
//      printf("x = %d",x); 
    for ( i = 1 ; i <= 10 ; i++ ) 
    { 
        scanf("%d",&y); 
        if ( y == x ) 
        { 
            //printf(" \\(^o^)/~ 哇，你猜了%d次，才被你猜中。膜拜大神！！\n",n+1); 
            printf("╮(╯▽╰)╭，还是没有猜中，重新来咯~\n");
            printf("继续？( y or n / Y or N )");
			scanf("%*c%c",&t);
			if ( t ==  'y' || t == 'Y' && t != '\n')
				goto kaishidedifang;
			else
				return 0;
            break; 
        } 
        if ( y > x && i != 10 ) 
        { 
            n++; 
            printf("( ⊙ o ⊙ )啊噢，数太大了哦。再猜一猜，你还有%d次机会啊：",10 - n); 
        } 
        if ( y < x && i != 10 ) 
        { 
            n++; 
            printf("(⊙o⊙)……哦噢，数太小了哦。再猜猜看，侬仲有%d次机会哦：",10 - n); 
        } 
        if ( i == 10 ) 
        { 
            printf("不行哦，猜了10次都没猜准。╮(╯▽╰)╭。告诉你正确答案是%d。\n",x); 
            printf("呵呵，O(∩_∩)O~，重新来过一次吧！\n"); 
            goto kaishidedifang; 
            break; 
        } 
    } 
    return 0; 
} 
