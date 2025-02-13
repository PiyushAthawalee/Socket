#include "client_lib.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(1);
    }

    int portno = atoi(argv[2]);
    int sockfd = connect_to_server(argv[1], portno);

    chat(sockfd);

    return 0;
}
    close(sockfd);
    return 0;
}
