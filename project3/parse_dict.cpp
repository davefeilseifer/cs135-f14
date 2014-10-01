#include "parse_dict.h"
#include <stdio.h>
#include <string.h>

void get_words( int &num_words, char** &words )
{
	const char* dict_filename = "words";
	FILE* dict_file = fopen( dict_filename, "r" );

	char word[1024];
	int word_count = 0;

	// while we're not at the end of a file
	while( fgets(word, sizeof word, dict_file) != NULL )
	{
		// increment word count;
		word_count++;
		// read in a string from a file (single word)
		int args = fscanf( dict_file, "%s", word );
		args++;
	}

	// close and re-open the file (to move the read pointer to the beginning
	// TODO: make this less dumb
	fclose(dict_file);	
	dict_file = fopen( dict_filename, "r" );

	num_words = word_count;
	words = new char*[num_words];

	int i = 0;
	while( fgets(word, sizeof word, dict_file) != NULL )
	{
		// initialize words[i] to be a good size;
		words[i] = new char[1024];

		// read in a string from a file (single word)
		int args = fscanf( dict_file, "%s", words[i] );
		args++;

		// increment i
		i++;
	}

	printf( "successfully read in [%d] words from [%s]\n", num_words, dict_filename );
	fclose(dict_file);	

}
