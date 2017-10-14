//
// Created by joe on 10/7/17.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <fcntl.h>
#define IPADDRESS "192.168.10.107"
#define BUFLEN 64

int udpsockfd;
struct sockaddr_in recvaddr;

int udp_setup_socket(int port) {
	// Open socket
        udpsockfd = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (udpsockfd<0)
        {
            perror("error, could not create socket");
            return -1;
        }
        printf("Socket created\n");
	    fflush(stdout);

	// Setup socket, specify listening interfaces etc
        recvaddr.sin_family = AF_INET;
        recvaddr.sin_port = htons(port);
        recvaddr.sin_addr.s_addr = inet_addr(IPADDRESS);
        memset(recvaddr.sin_zero,'\0',sizeof (recvaddr.sin_zero));

	// Put socket in non blcoking mode
	int flags = fcntl(udpsockfd, F_GETFL);				// Get the sockets flags
	flags |= O_NONBLOCK;								// Set NONBLOCK flag
	if (fcntl(udpsockfd, F_SETFL, flags) == -1){		// Write flags back
        perror("error,fcnctl failed - could not set socket to nonblocking");
        return -1;
	}

    printf("Listening for UDP data on port %d \n",port);
    fflush(stderr);

    return 0;
}

int SendBuffer(unsigned char *buf){
    int addr_len = sizeof(recvaddr);
    int lent = (int) sendto(udpsockfd, buf, BUFLEN , 0, (struct sockaddr *)&recvaddr, (socklen_t) addr_len);

    if (lent < 0){
        perror("Sending");
        return -1;
    }else{
        return lent;
    }
}
int closeSocket(){
    close(udpsockfd);
    return 0;
}



