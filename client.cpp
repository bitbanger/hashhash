#include "common.h"
#include <cstring>

using namespace hashhash;

int main(int argc, char **argv) {
	if(argc < 2) {
		printf("USAGE: %s <hostname>\n", argv[0]);
		return RETVAL_INVALID_ARG;
	}

	int srv_fd;
	if(!rslvconn(&srv_fd, argv[1], PORT_MASTER_CLIENTS)) {
		printf("FATAL: Couldn't resolve or connect to host: %s\n", argv[1]);
		return RETVAL_CONN_FAILED;
	}

	char mesg[512];
	memset(&mesg, 0, sizeof mesg);
	sprintf(mesg, "This is a sample sentence");
	write(srv_fd, mesg, sizeof mesg);
}
