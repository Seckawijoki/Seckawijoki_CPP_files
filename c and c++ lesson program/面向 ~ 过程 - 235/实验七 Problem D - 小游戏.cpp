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
    printf("\n���ڵ�������һ������"); 
    printf("�������Ƕ���?_?��"); 
//  if ( getchar() == '\n' ) 
//      printf("x = %d",x); 
    for ( i = 1 ; i <= 10 ; i++ ) 
    { 
        scanf("%d",&y); 
        if ( y == x ) 
        { 
            //printf(" \\(^o^)/~ �ۣ������%d�Σ��ű�����С�Ĥ�ݴ��񣡣�\n",n+1); 
            printf("�r(�s���t)�q������û�в��У���������~\n");
            printf("������( y or n / Y or N )");
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
            printf("( �� o �� )���ޣ���̫����Ŷ���ٲ�һ�£��㻹��%d�λ��ᰡ��",10 - n); 
        } 
        if ( y < x && i != 10 ) 
        { 
            n++; 
            printf("(��o��)����Ŷ�ޣ���̫С��Ŷ���ٲ²¿���ٯ����%d�λ���Ŷ��",10 - n); 
        } 
        if ( i == 10 ) 
        { 
            printf("����Ŷ������10�ζ�û��׼���r(�s���t)�q����������ȷ����%d��\n",x); 
            printf("�Ǻǣ�O(��_��)O~����������һ�ΰɣ�\n"); 
            goto kaishidedifang; 
            break; 
        } 
    } 
    return 0; 
} 
