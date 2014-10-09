#include <stdio.h>

int main()
{
	int  x 		= 42;
	int* xPtr 	= &x;
	
	printf( "x's value is: %d\n", x );
	printf( "value of xPtr is: 0x%08x\n", xPtr );
	printf( "value of xPtr is: %d\n", xPtr );

	// de-reference the pointer
	printf( "value at memory location is: %d\n", *xPtr );

	printf( "===============================\n" );

	// do something with the pointed-to value
	x++;
	printf( "value at memory location is: %d\n", *xPtr );
	
	printf( "===============================\n" );
		
	// do something to the pointer
	xPtr++;
	printf( "value of xPtr is: 0x%08x\n", xPtr );
	printf( "value of xPtr is: %d\n", xPtr );
	printf( "value at memory location is: %d\n", *xPtr );	
}
