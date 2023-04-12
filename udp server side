#include <stdio.h>      // Default System Calls
#include <stdlib.h>     // Needed for OS X
#include <string.h>     // Needed for Strlen
#include <sys/socket.h> // Needed for socket creating and binding
#include <netinet/in.h> // Needed to use struct sockaddr_in
#include <time.h>       // To control the timeout mechanism

#define EXPR_SIZE   1024
#define BUFLEN      512
#define TRUE        1
#define SERVERLEN   1024

int main(int argc, char **argv){

    struct sockaddr_in myaddr;  // address of the server
    struct sockaddr_in claddr;  // address of the client
    char buf[BUFLEN];
    int fd;
    long recvlen;
    socklen_t clientlen;



    if((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
        perror("cannot create socket");
        return 0;
    }

    memset((char *)&myaddr, 0, sizeof(myaddr));
    myaddr.sin_family = AF_INET;
    myaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myaddr.sin_port = htons(0);

    if(bind(fd, (struct sockaddr *)&myaddr, sizeof(myaddr)) < 0){
        perror("cannot bind");
        return 0;
    }
    clientlen = sizeof(claddr);

    while (TRUE) {
        recvlen = recvfrom(fd, buf, BUFLEN, 0, (struct sockaddr *)&claddr, &clientlen);
        if (recvlen < 0) {
            perror("cannot recvfrom()");
            return 0;
        }
        printf("Received %ld bytes\n",recvlen);
        buf[recvlen] = 0;
        printf("Received message: \"%s\"\n",buf);

    }

    return 0;
}
