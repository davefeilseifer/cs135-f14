#include <stdio.h>

int main()
{
	char* simple_string = (char*) "hello world\n";

	int i = 0;
	while( simple_string[i] != '\0' )
	{
		printf( "%d: [%c]\n", i, simple_string[i++] );
	}

	return 0;
}
