#ifndef _PARSE_PASSWD_H_
#define _PARSE_PASSWD_H_

void parse_passwd( const char* filename, int &num_records, char** &usernames, char** &hashes, char** &fullnames );

#endif
