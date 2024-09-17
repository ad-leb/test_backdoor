#include "defs.h"



int str_split (unsigned char* from, unsigned char** to, int max)
{
	int							cnt;


	for (cnt = 0; cnt < max; cnt++) {
		while ( *from <= 0x20 )	from++;
		to[cnt] = from;
		while ( *from > 0x20 )	from++;
		*from++ = 0;
		if ( *from == 0 || *from == 0x0a )	break;
	};
	to[cnt + 1] = NULL;


	return cnt;
}
