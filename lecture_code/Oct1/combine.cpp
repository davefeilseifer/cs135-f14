#include <stdio.h>
#include <string.h>

int main( int argc, char* argv[] )
{
	char* str1 = argv[1];
	char* str2 = argv[2];

	char new_string[100];
	//new_string[0] = '\0';

	sprintf(new_string,"%s%s", str1, str2 );

	printf( "new_string: %s\n", new_string );

	return 0;
}
