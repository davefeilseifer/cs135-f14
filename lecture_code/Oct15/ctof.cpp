#include <stdio.h>

// Answer to question 6

float ctof( float c )
{
	float f = ((float) 9/ 5) * c + 32;
	return f;
}


// Answer to question 7
int main()
{
	for( int i = 0; i < 10; i++ )
	{
		// read in a float (Celsius)
		float c;
		scanf( "%f", &c );

		// output Farenheit
		float f = ctof( c );
		printf( "%f\n", f );
	}

	return 0;
}

