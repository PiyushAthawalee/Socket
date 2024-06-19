#ifndef SERVER_LIB_H
#define SERVER_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

// Function prototypes
void error(const char *msg);
int setup_server(int portno);
void handle_new_connection(int sockfd, fd_set *read_fds, int *fdmax, char client_names[FD_SETSIZE][16]);
void handle_client_message(int i, fd_set *read_fds, int fdmax, char client_names[FD_SETSIZE][16]);

#endif // SERVER_LIB_H
