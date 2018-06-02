# include <stdio.h>
//1
/* 
 * bitXor - ������ʹ��~��&��ʵ����� 
 *   ����: bitXor(4, 5) = 1
 *   ����Ĳ�����: ~ &
 *   ����������Ŀ: 14
 *   ��ֵ: 1
 */
int bitXor( int x, int y )
{
	//����� 
	return ~( ~( x & ~y ) & ~( ~x & y ) );
	// return ( ~x & y ) ^ ( x & ~y );
}
/* 
 * tmin - ������С�Ķ����Ʋ��� 
 *   ����Ĳ�����: ! ~ & ^ | + << >>
 *   ����������Ŀ: 4
 *   ��ֵ: 1
 */
int tmin()
{
	return 1<<31;
}
//2
/*
 * isTmax - ���x�����Ķ����Ʋ��룬����1�����򣬷���0
 *   ����Ĳ�����: ! ~ & ^ | +
 *   ����������Ŀ: 10
 *   ��ֵ: 2
 */
int isTmax( int x )
{
	return !( x + tmin() + 1 );
}
/* 
 * allOddBits - �����������λ��Ϊ1�򷵻�1;���򷵻�0
 *   ���ӣ� allOddBits(0xFFFFFFFD) = 1, allOddBits(0xAAAAAAAA) = 0
 *   ����Ĳ�����: ! ~ & ^ | + << >>
 *   ����������Ŀ: 12
 *   ��ֵ: 2
 */
int allOddBits( int x )
{
	int y = 0xAA;
	y = ( y << 8 ) | y;
	y = ( y << 16 ) | y;
	return !( ( x & y ) ^ y );
}
/* 
 * negate - ����-x 
 *   ����: negate(1) = -1.
 *   ����Ĳ�����: ! ~ & ^ | + << >>
 *   ����������Ŀ: 5
 *   ��ֵ: 2
 */
int negate( int x )
{
	return ~x + 1;
} 
//3
/* 
 * isAsciiDigit - ���x��ascii���е�0~9(48~57)(0x30~0x39)������1;���򷵻�0
 *   ����: isAsciiDigit(0x35) = 1.
 *         isAsciiDigit(0x3a) = 0.
 *         isAsciiDigit(0x05) = 0.
 *   ����Ĳ�����: ! ~ & ^ | + << >>
 *   ����������Ŀ: 15
 *   ��ֵ: 3
 */
int isAsciiDigit( int x )
{
	int y = 1 << 31;
	return!( ((x + ~0x2F) & y) | ((0x3A + ~x) & y) );
}
/* 
 * conditional - ʵ��x?y:z 
 *   ����: conditional(2,4,5) = 4
 *   ����Ĳ�����: ! ~ & ^ | + << >>
 *   ����������Ŀ: 16
 *   ��ֵ: 3
 */
int conditional( int x, int y, int z )
{
	return ((~!!x + 1) & y) | ((~!x + 1) & z);
}
/* 
 * isLessOrEqual - ���x<=y����1���򷵻�0 
 *   ����: isLessOrEqual(4,5) = 1.
 *   ����Ĳ�����: ! ~ & ^ | + << >>
 *   ����������Ŀ: 24
 *   ��ֵ: 3
 */
int isLessOrEqual( int x, int y )
{
	int sx = !!(x >> 31); 
	int sy = !!(y >> 31);
	int z = y + (~x + 1);
	int s = !(z >> 31);
	return ( !(sx ^ sy) & s) | ( (sx ^ sy) & sx );
}
//4
/* 
 * logicalNeg - ʵ�֣�������Ĺ���
 *   ����: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   ����Ĳ�����: ~ & ^ | + << >>
 *   ����������Ŀ: 12
 *   ��ֵ: 4 
 */
int logicalNeg( int x )
{
	return ~( x | 0 ) + 1;
}
/* howManyBits - ���ؽ�X��ʾΪ�����������С��Чλ����
 *  ����: howManyBits(12) = 5
 *        howManyBits(298) = 10
 *        howManyBits(-5) = 4
 *        howManyBits(0)  = 1
 *        howManyBits(-1) = 1
 *        howManyBits(0x80000000) = 32
 *  ����Ĳ�����: ! ~ & ^ | + << >>
 *  ����������Ŀ: 90
 *  ��ֵ: 4
 */
int howManyBits( int x )
{
//	printf("0x%8X\n",x);
	int sum = 1;
	if ( x & tmin() )//positive
		x = x ^ ~0;
	else//negative 
		x = x ^ 0;
//	printf("0x%8X\n",x);
	while ( x )
	if ( isLessOrEqual(sum,31) )
	{
		x = x >> 1;
		sum = sum + 1;
	} 
	return sum;
}
unsigned float_to_unsigned_of_hexadecimal( unsigned uf )
{
//	printf("0x%8X\n",uf);
	unsigned temporary = uf;
	unsigned offset;
	unsigned bits = -1;
	unsigned result = 0;
	if ( uf & 1 << 31 )
		result = 1 << 31;
	while ( temporary )
	{
		++bits;
		temporary = temporary >> 1;
	}
//	printf("%d\n",bits);
	temporary = (uf & ( (1 << bits) - 1) ) << (23 - bits);
//	printf("0x%8X\n",temporary);
	offset = ( bits + 128 ) << 23;
	result += offset + temporary;
	return result;
}
//float
/* 
 * 	 float_twice - ��unsinged��ʾ�ĸ����������ƵĶ����Ķ�����unsigned��
 *   �����ͽ�����ᱻ��Ϊunsigned���أ����ǻ��ʾΪ�����Ƶĵ����ȸ���ֵ��
 *   ����Ĳ�����: �κ����������޷����������������� ||, &&, also if, while
 *   ����������Ŀ: 30
 *   ��ֵ: 4
 */
unsigned float_twice( unsigned uf )
{
//	printf("0x%8X\n",uf);
	unsigned zero = 0x7F << 23;
	printf("0x%8X\n",zero);
	if ( !(uf + ~zero + 1) )return uf;
	uf = uf << 1;
	unsigned temporary = uf;
	unsigned offset;
	unsigned bits = -1;
	unsigned result = 0;
	if ( uf & 0x80000000 )
		result = 0x80000000;
	while ( temporary )
	{
		++bits;
		temporary = temporary >> 1;
	}
	printf("%d\n",bits);
	temporary = (uf & ( (1 << bits) - 1) ) << (23 - bits);
	printf("0x%8X\n",temporary);
	offset = ( bits + 128 ) << 23;
	result += offset + temporary;
	return result;
}
/* 
 * 	 float_i2f - ����int x��unsigned�������Ķ�������ʽ
 *   �����ͽ�����ᱻ��Ϊunsigned���أ����ǻ��ʾΪ�����Ƶĵ����ȸ���ֵ
 *   ����Ĳ�����: �κ����������޷����������������� ||, &&, also if, while
 *   ����������Ŀ: 30
 *   ��ֵ: 4
 */
unsigned float_i2f( int x )
{
	unsigned positive;
	unsigned temporary;
	unsigned offset;
	unsigned bits = -1;
	unsigned result = 0;
	if ( x >> 31 )positive = negate(x);
	else positive = x;
//	printf("0x%8X\n",x);
//	printf("0x%8X\n",positive);
	temporary = positive;
	if ( x & 1 << 31 )
		result = 1 << 31;
	while ( temporary )
	{
		++bits;
		temporary = temporary >> 1;
	}
//	printf("%d\n",bits);
	temporary = (positive & ( (1 << bits) - 1) ) << (23 - bits);
	if ( !temporary && !bits )return x;
//	printf("0x%8X\n",temporary);
	offset = ( bits + 128 ) << 23;
	result += offset + temporary;
	return result;	
}
/* 
 *   float_f2i - ����unsigned uf��������+�Ķ�������ʽ
 *   �����ͽ�����ᱻ��Ϊunsigned���أ����ǻ��ʾΪ�����Ƶĵ����ȸ���ֵ
 *   �κγ�����Χ������Ӧ�÷��� 0x80000000u.
 *   ����Ĳ�����: �κ����������޷����������������� ||, &&, also if, while
 *   ����������Ŀ: 30
 *   ��ֵ: 4
 */
int float_f2i( unsigned uf )
{
	int result = 0;
	int bits = ((uf >> 23) & 0xFF );
	if ( !( bits ^ 0xFF ) )return 0x80000000u;
	bits -= 127;
	int value = ( (uf >> (24 - bits)) & ((1 << bits - 1) - 1) ) + (1 << bits - 1);
//	printf("0x%8X\n",bits);
//	printf("0x%8X\n",value);
	if ( !value && !bits )return 0;
	result = value;
	if ( uf & 1 << 31 )result = negate(result);
	return result;
}
int main()
{
	int x, y, z;
	//--------------------------------------------//	
	x = 4; y = 5;
	printf("bitXor(%d,%d) = %d\n",x,y,bitXor(x,y));
	//--------------------------------------------//
	printf("tmin() = %d\n",tmin());
	//--------------------------------------------//
	x = 2147483647; y = 2147483646;
	printf("isTmax(%d) = %d\n",x,isTmax(x));
	printf("isTmax(%d) = %d\n",y,isTmax(y));
	//--------------------------------------------//
	x = 0xFFFFFFFD; y = 0xAAAAAAAA; z = 0x7FFFFFFF;
	printf("allOddBits[%11d(0x%X)] = %d\n",x,x,allOddBits(x));
	printf("allOddBits[%11d(0x%X)] = %d\n",y,y,allOddBits(y));
	printf("allOddBits[%11d(0x%X)] = %d\n",z,z,allOddBits(z));
	//--------------------------------------------//
	x = 75; y = -15;
	printf("negate(%d) = %d\n",x,negate(x));
	printf("negate(%d) = %d\n",y,negate(y));
	//--------------------------------------------//
	x = 48; y = 57; z = 58;
	printf("isAsciiDigit(%2d) = %d\n",x,isAsciiDigit(x));
	printf("isAsciiDigit(%2d) = %d\n",y,isAsciiDigit(y));
	printf("isAsciiDigit(%2d) = %d\n",z,isAsciiDigit(z));
	x = 47; y = -33; z = 125;
	printf("isAsciiDigit(%2d) = %d\n",x,isAsciiDigit(x));
	printf("isAsciiDigit(%2d) = %d\n",y,isAsciiDigit(y));
	printf("isAsciiDigit(%2d) = %d\n",z,isAsciiDigit(z));
	//--------------------------------------------//
	x = 2; y = 4; z = 5;
	printf("conditional(%d,%d,%d) = %d\n",x,y,z,conditional(x,y,z));
	x = 0; y = 4; z = 5;
	printf("conditional(%d,%d,%d) = %d\n",x,y,z,conditional(x,y,z));
	//--------------------------------------------//
	x = 4; y = 5;
	printf("isLessOrEqual(%d,%d) = %d\n",x,y,isLessOrEqual(x,y));
	x = 5; y = 5;
	printf("isLessOrEqual(%d,%d) = %d\n",x,y,isLessOrEqual(x,y));
	x = 6; y = 5;
	printf("isLessOrEqual(%d,%d) = %d\n",x,y,isLessOrEqual(x,y));
	x = 0x80000000; y = 0x7FFFFFFF;
	printf("isLessOrEqual(%d,%d) = %d\n",x,y,isLessOrEqual(x,y));
	//--------------------------------------------//
 	x = 12; y = 298; z = -5;
 	printf("howManyBits[%11d(0x%8X)] = %2d\n",x,x,howManyBits(x));
 	printf("howManyBits[%11d(0x%8X)] = %2d\n",y,y,howManyBits(y));
 	printf("howManyBits[%11d(0x%8X)] = %2d\n",z,z,howManyBits(z));
 	x = 0; y = -1; z = 0x80000000;
 	printf("howManyBits[%11d(0x%8X)] = %2d\n",x,x,howManyBits(x));
 	printf("howManyBits[%11d(0x%8X)] = %2d\n",y,y,howManyBits(y));
 	printf("howManyBits[%11d(0x%8X)] = %2d\n",z,z,howManyBits(z));
	//--------------------------------------------//
	//============================================//
	float f, g, h;
	f = 511.2f; g = 255.6f; h = 127.8f;
 	printf("float_twice[%9.9f(0x%8X)] = 0x%8X\n",f,(unsigned)f,float_twice(f));
 	printf("float_twice[%9.9f(0x%8X)] = 0x%8X\n",g,(unsigned)g,float_twice(g));
 	printf("float_twice[%9.9f(0x%8X)] = 0x%8X\n",h,(unsigned)h,float_twice(h));
	x = 0x3F800000;
	printf("float_twice[%11d(0x%8X)] = 0x%8X\n",x,x,float_twice(x));
	//============================================//
	x = -255; y = 255; z = 0x3F800000;
 	printf("float_i2f[%11d(0x%8X)] = 0x%8X\n",x,x,float_i2f(x));
 	printf("float_i2f[%11d(0x%8X)] = 0x%8X\n",y,y,float_i2f(y));
	printf("float_i2f[%11d(0x%8X)] = 0x%8X\n",z,z,float_i2f(z));
	//============================================//
	x = 0x43FF0000; y = 0xC3FF0000; z = 0x7FFFFFFF;
 	printf("float_f2i[0x%8X] = %11d(0x%8X)\n",x,float_f2i(x),float_f2i(x));
 	printf("float_f2i[0x%8X] = %11d(0x%8X)\n",y,float_f2i(y),float_f2i(y));
 	printf("float_f2i[0x%8X] = %11d(0x%8X)\n",z,float_f2i(z),float_f2i(z));
	x = 0xFFFFFFFF; y = 1;
 	printf("float_f2i[0x%8X] = %11d(0x%8X)\n",x,float_f2i(x),float_f2i(x));
	printf("float_f2i[0x%8X] = %11d(0x%8X)\n",y,float_f2i(y),float_f2i(y));
	return 0;
}

