#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>


#define BUFLEN					16384
#define VALLEN					256
#define VALCNT					256


#define ADDR_0					192
#define ADDR_1					168
#define ADDR_2					13
#define ADDR_3					2
#define PORT					4235
#define ADDR					(ADDR_0 << 24) | (ADDR_1 << 16) | (ADDR_2 << 8) | (ADDR_3 << 0)


#define FLOW_IN					0
#define FLOW_OUT				1
#define FLOW_ERR				2
