#include "defs.h"



int become_daemon ();
int get_listener ();
int micro_shell ();

int main (int argc, char* argv[], char* env[])
{
	int							ld, ad;


	
	if ( !~become_daemon() )													return 1;
	ld = get_listener();														if (!~ld)return 2;
	while ( 1 ) {
		ad = accept(ld, NULL, NULL);											if (!~ad)continue;
		if ( !fork() ) {
			if ( dup2(ad, FLOW_IN) != FLOW_IN )									return 4;
			if ( dup2(ad, FLOW_OUT) != FLOW_OUT )								return 5;
			if ( dup2(ad, FLOW_ERR) != FLOW_ERR )								return 6;
			return micro_shell();
		}
	}



	return 0;
}
