#include "defs.h"



int str_split (unsigned char*, unsigned char**, int);


void execstr (unsigned char* str)
{
	unsigned char*				argv[VALCNT];


	str_split(str, argv, VALCNT);
	execv((char*) argv[0], (char**) argv);
}
