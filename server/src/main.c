#include "server_lib.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Port not provided\n");
        exit(1);
    }

    int sockfd, portno;
    fd_set read_fds, temp_fds;
    int fdmax;

    char client_names[FD_SETSIZE][16];  // array to store client names

    portno = atoi(argv[1]);
    sockfd = setup_server(portno);

    FD_ZERO(&read_fds);
    FD_ZERO(&temp_fds);
    FD_SET(sockfd, &read_fds);
    fdmax = sockfd;

    while (1) {
        temp_fds = read_fds;

        if (select(fdmax + 1, &temp_fds, NULL, NULL, NULL) == -1) {
            error("Select error");
        }

        for (int i = 0; i <= fdmax; i++) {
            if (FD_ISSET(i, &temp_fds)) {
                if (i == sockfd) {
                    handle_new_connection(sockfd, &read_fds, &fdmax, client_names);
                } else {
                    handle_client_message(i, &read_fds, fdmax, client_names);
                }
            }
        }
    }

    close(sockfd);
    return 0;
}
