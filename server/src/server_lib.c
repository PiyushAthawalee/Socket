#include "server_lib.h"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int setup_server(int portno) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Binding failed");
    }

    listen(sockfd, 5);

    return sockfd;
}

void handle_new_connection(int sockfd, fd_set *read_fds, int *fdmax, char client_names[FD_SETSIZE][16]) {
    int newsockfd;
    socklen_t clilen;
    struct sockaddr_in cli_addr;
    char buffer[255];

    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0) {
        error("Error on accept");
    } else {
        FD_SET(newsockfd, read_fds);
        if (newsockfd > *fdmax) {
            *fdmax = newsockfd;
        }
        bzero(buffer, 255);
        read(newsockfd, buffer, 255);  // read client's name
        strncpy(client_names[newsockfd], buffer, 16);
        printf("New connection from %s on socket %d\n", client_names[newsockfd], newsockfd);
    }
}

void handle_client_message(int i, fd_set *read_fds, int fdmax, char client_names[FD_SETSIZE][16]) {
    char buffer[255];
    int n = read(i, buffer, 255);
    if (n <= 0) {
        if (n == 0) {
            printf("%s (socket %d) hung up\n", client_names[i], i);
        } else {
            error("Error reading from socket");
        }
        close(i);
        FD_CLR(i, read_fds);
    } else {
        char message[300];
        snprintf(message, 300, "%s: %s", client_names[i], buffer);

        for (int j = 0; j <= fdmax; j++) {
            if (FD_ISSET(j, read_fds) && j != i && j != 0) {
                if (write(j, message, strlen(message)) < 0) {
                    error("Error writing to socket");
                }
            }
        }
    }
}
