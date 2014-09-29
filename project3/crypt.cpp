#include <stdio.h>
#include <unistd.h>
#include <crypt.h>

int main( int argc, char* argv[] )
{
	// check to make sure that we have the right number of arguments
	if( argc != 6 )
	{
		// print out usage statement
		printf( "usage:\n\n%s username password uid gid fullname\n", argv[0] );

		// all did not end well, so print out nonzero return to exit program with error
		return 1;
	}
	
	// salt file
	char salt[] = "$1$........";

	// code to encrypt the password file
	char* crypted = crypt(argv[2],salt);

	// file format for /etc/passwd for project[3] is:
	// username:salt$pass:uid:gid:fullname:homedir
	printf( "%s:%s:%s:%s:%s:/home/%s\n", argv[1], crypted, argv[3], argv[4], argv[5], argv[1] );
	return 0;
}
