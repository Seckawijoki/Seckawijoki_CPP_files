# include <stdio.h>
int main()
{
	int a = 1,*pi;
	char b = 'a',*pc;
	long c = 1,*pl;
	pi = &a;
	pc = &b;
	pl = &c;
	printf("pi = &int(a)\n");
	printf("pc = &char(b)\n");
	printf("pl = &long(c)\n\n");
	printf("pi = %d\n",pi);
	printf("pc = %d\n",pc);
	printf("pl = %d\n\n",pl);

	pi++;    //pi的值将是+4 (int型占4byte)
	printf("pi++ , pi = %d\n",pi);

	pi -= 2;    // pi的值将是-4*2,即-8
	printf("pi -= 2 , pi = %d\n",pi);

	pc++;      // pc的值将是+1
	printf("pc++ , pc = %d\n",pc);

	pc -= 2;   // pc的值将是-2*1,即-2 (char型占4byte)
	printf("pc -= 2 , pc = %d\n",pc);

	pl++;       // pl的值将是+4
	printf("pl++; , pl = %d\n",pl);

	pl -= 2;    // pi的值将是-4*2,即-8 (long型占4byte)
	printf("pl -= 2; , pl = %d\n\n",pl);

	return 0;
}
/*======================================
			pi = &int(a)
			pc = &char(b)
			pl = &long(c)

			pi = 1638208
			pc = 1638200
			pl = 1638192

			pi++ ,    pi = 1638212	// pi的值将是+4 (int型占4byte)
			pi -= 2 , pi = 1638204	// pi的值将是-4*2,即-8
			pc++ ,    pc = 1638201	// pc的值将是+1
			pc -= 2 , pc = 1638199	// pc的值将是-2*1,即-2 (char型占4byte)
			pl++  ,   pl = 1638196	// pl的值将是+4
			pl -= 2  ,pl = 1638188	// pi的值将是-4*2,即-8 (long型占4byte)

			Press any key to continue
======================================*/