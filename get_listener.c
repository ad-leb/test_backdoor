#include "defs.h"


int get_listener ()
{
	int							sd;
	struct sockaddr_in			addr;



	for (int i = 0; i < sizeof(addr); i++)		*((char*)&addr + i) = 0;
		addr.sin_family				= AF_INET;
		addr.sin_port				= htons(PORT);
		addr.sin_addr.s_addr		= htonl(ADDR);

	sd = socket(AF_INET, SOCK_STREAM, 0);										if(!~sd)return -1;
	if ( bind(sd, (struct sockaddr*) &addr, sizeof(addr)) == -1 )				return -1;
	if ( listen(sd, 0) == -1 )													return -1;



	return sd;
}
