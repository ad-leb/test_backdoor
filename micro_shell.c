#include "strs.c"
#include "defs.h"



void execstr (unsigned char*);

int micro_shell ()
{
	unsigned char				buffer[BUFLEN];
	int							len = 1;
	int							status = 0;
	unsigned char				tmp_buf[16];
	int							tmp_len;



	while ( len > 0 ) {
		for (int i = 0; i < BUFLEN; i++)	buffer[i] = 0;

		if ( write(1, str_prompt, len_prompt) != len_prompt )					return 1;
		len = read(0, buffer, BUFLEN);

		if ( !fork() )		execstr(buffer);
		wait(&status);
	}																			if(!~len)return 2;



	return 0;
}
