#include "defs.h"



int become_daemon ()
{
	
	switch ( fork() ) {
		case -1:								return 1;
		case  0:								break;
		default:								_exit(0);
	}

	if ( !~setsid() )							return 2;

	switch ( fork() ) {
		case -1:								return 1;
		case  0:								break;
		default:								_exit(0);
	}

	if ( !~umask(0) )							return 3;
	if ( !~chdir("/") )							return 4;
	if ( close(0) || close(1) || close(2) )		return 5;

	switch ( fork() ) {
		case -1:								return 1;
		case  0:								break;
		default:								_exit(0);
	}


	return 0;
}
