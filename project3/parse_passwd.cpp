#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parse_passwd.h"

int countlines(const char *filename)
{
	// count the number of lines in the file called filename                                    
	FILE *fp = fopen(filename,"r");
	int ch=0;
	int lines=0;

	if (fp == NULL)
	{

		return 0;
	}

	lines++;
	while ((ch = fgetc(fp)) != EOF)
	{
		if (ch == '\n')
		lines++;
	}
	fclose(fp);

	return lines;
}



void parse_passwd( const char* filename, int &num_records, char** &usernames, char** &hashes, char** &fullnames )
{
	// is the file defined?
	if( filename == NULL )
	{
		fprintf( stderr, "no filename specified, exiting\n" );
		exit(-1);
	}

	num_records = countlines(filename)-1;

	// open the passwd file
	FILE* passwd_file = fopen( filename, "r" );

	// will the file open?	
	if( passwd_file == NULL )
	{	
		fprintf( stderr, "could not find the file: [%s], exiting\n", filename );
		exit(-1);
	}
	
	// initialize each array
	usernames = new char*[num_records];
	hashes = new char*[num_records];
	fullnames = new char*[num_records];

	char tmp1[100], tmp2[100], tmp3[100];

	// for each line of the file
	for( int i = 0; i < num_records; i++ )
	{
		usernames[i] = new char[100];
		hashes[i] = new char[100];
		fullnames[i] = new char[100];

		// read in the line
		int num_items = fscanf(passwd_file, "%99[^:]:%99[^:]:%99[^:]:%99[^:]:%99[^:]:%s\n", usernames[i], hashes[i], tmp1,tmp2,fullnames[i],tmp3);
//		int num_items = fscanf(passwd_file, "%99[^:]:%99[^:]:%99[^:]:%99[^:]:%99[^:]:%99[^:]\n", usernames[i], hashes[i], tmp1,tmp2,fullnames[i],tmp3);
		if ( num_items != 6 )
		{
			fprintf(stderr,"some error parsing [%s] file (%d != 6), exiting\n", filename,num_items );
			exit(4);
		}
		printf( "[%s] [%s] [%s]\n", usernames[i], hashes[i], fullnames[i] );

	}

	// close the file
	fclose( passwd_file );

}
