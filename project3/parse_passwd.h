#ifndef _PARSE_PASSWD_H_
#define _PARSE_PASSWD_H_

/**
	parse_passwd:

	A function to parse the passwd file provided for the assignment

	const char* filename: a string that is the filename for the passwd file
		(for this assignment, unless you are doing the challenges, this should be "passwd")

	int num_words: an integer (passed by reference) that is set by the function
		that equals the number of passwords in the file

	char** usernames: an array of strings (char*) (passed by reference) that when the function
		is completed will contain each the usernames in the file

	char** hashes: an array of strings (char*) (passed by reference) that when the function
		is completed will contain each the crypted passwords of each user in the file

	char** fullnames: an array of strings (char*) (passed by reference) that when the function
		is completed will contain each the full names of the users in the file

	**note: usernames, hashes, and fullnames go together, so hashes[2] is the crypted
		password for usernames[2] and so on...

	returns: nothing (void)

**/

void parse_passwd( const char* filename, int &num_records, char** &usernames, char** &hashes, char** &fullnames );

#endif
