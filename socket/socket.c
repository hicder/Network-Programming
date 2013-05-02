#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    getaddrinfo("www.google.com", "80", &hints, &res);
    int sockfd;
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    printf("The sockfd is: %d\n", sockfd);
    int status;
    status = connect(sockfd, res->ai_addr, res->ai_addrlen);
    if (status != -1) {
        printf("Successfully connected to www.google.com\n");
    }
//    printf("The status is: %d\n",status);
    return 0;
}