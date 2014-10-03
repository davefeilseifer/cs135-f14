#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	char* simple_string = argv[1];
	size_t str_max = strlen(simple_string);

	printf( "argv[0]: %s\n", argv[0] );
	printf( "string: %s\n", simple_string );

	for( int i = 0; i < str_max / 2; i++ )
	{
		char tmp = simple_string[i];
		simple_string[i] = simple_string[str_max-i-1];
		simple_string[str_max-i-1] = tmp;
	}

	printf( "reversed? %s\n", simple_string );
	
	return 0;
}
