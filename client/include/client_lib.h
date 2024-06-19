#ifndef CLIENT_LIB_H
#define CLIENT_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

// Function prototypes
void error(const char *msg);
int connect_to_server(const char *hostname, int portno);
void chat(int sockfd);

#endif // CLIENT_LIB_H
