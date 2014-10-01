#ifndef _PARSE_DICT_H_
#define _PARSE_DICT_H_

/**
	get_words:

	A function to parse the "words" dictionary file provided for the assignment

	int num_words: an integer (passed by reference) that is set by the function
		that equals the number of words in the dictionary

	char** words: an array of strings (char*) (passed by reference) that when the function
		is completed will contain each word in the dictionary file

	returns: nothing (void)

**/

void get_words( int &num_words, char** &words );

#endif
