# include <stdio.h>
ADT List
{
	InitList( &L );
	DestroyList( &L );
	ClearList( &L );
	ListEmpty( L );
	ListLength( L );
	GetElem( L, i, &e );
	LocateElem( L, e, compare() );
	PriorElem( L, cur_e, &pre_e );
	NextElem( L, cur_e, &pre_e );
	ListInsert( &L, i, e );
	ListDelete( &L, i, &e );
	ListTraverse( L, visit() );
}ADT List

void MergeList ( List La , List Lb , List &Lc )
{
	InitList( Lc );
	i = j = 1;
	k = 0;
	La_len = ListLength( La );
	Lb_len = ListLength( Lb );
	while ( ( i <= La_len ) && ( j <= Lb_len ) )
	{
		GetElem( La, i, ai );
		GetElem( Lb, j, bj );
		if ( ai <= bj )
		{
			ListInsert( Lc, ++k, ai );
			++i;
		}
		else
		{
			ListInsert( Lc, ++k, bj );
			++j;
		}
	}
	while ( i <= La_len )
	{
		GetElem( La, i++, ai );
		ListInsert( Lc, ++k, ai );
	}
	while ( j <= Lb_len )
	{
		GetElem( Lb, j++, bj );
		ListInsert( Lc, ++k, bj );
	}
}
int main()
{
	return 0;	
}