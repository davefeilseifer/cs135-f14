#include <stdio.h>
#include <string.h>


int main()
{
	// declare to strings

	char* str1 = new char[30];
	char* str2 = new char[30];
	
	// read in two strings from the console

	scanf( "%s", str1 );
	scanf( "%s", str2 );

	// print out the strings
	//printf( "string 1: %s string 2: %s\n", str1, str2 );

	// create an array of strings
	//char ** arrayOfStrings = new char*[3];
	char * arrayOfStrings[3];

	for( int i = 0; i < 3; i++ )
	{
		arrayOfStrings[i] = new char[60];
		arrayOfStrings[i][0] = '\0';
	}

	// put in the new array of strings

	// str1 followed by str 2
	sprintf( arrayOfStrings[0], "%s%s", str1, str2 );

	// str2 followed by str 1
	sprintf( arrayOfStrings[1], "%s%s", str2, str1 );

	// str1, replace 2nd of str1 with 0th of str2
	sprintf( arrayOfStrings[2], "%s", str1 );
	arrayOfStrings[2][2] = str2[0];

	return 0;
}




