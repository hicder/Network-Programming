#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>



int main(int argc, char * argv[]){
    struct addrinfo hints, *res, *p;
    int status;                         //status when enquiring the website
    char ipstr[INET6_ADDRSTRLEN];
    if (argc < 2) {
        printf("you suck!\n");
        return 1;
    }
    int i;
    for ( i = 1; i < argc; i++) {
        memset(&hints, 0, sizeof hints);
        status = getaddrinfo(argv[i],NULL, &hints, &res);
        if (status != 0) {
            printf("Can't get information for %s\n",argv[i]);
            continue;
        }
        printf("***************Information for %s:****************\n",argv[i]);
        // there may be more than 1 result, so we need to iterate through all of them
        for (p = res; p != NULL; p = p->ai_next) {
            //different family
            void *addr;
            if (p->ai_family == AF_INET) {
                struct sockaddr_in *a4 = (struct sockaddr_in *)p->ai_addr;
                addr = &(a4->sin_addr);
            }
            else if (p->ai_family == AF_INET6){
                struct sockaddr_in6 *a6 = (struct sockaddr_in6 *)p->ai_addr;
                addr = &(a6->sin6_addr);
            }
            
            inet_ntop(p->ai_family, addr,ipstr, sizeof ipstr);
            
            printf("%s\n",ipstr);
        }
        
    }
    return 0;
}