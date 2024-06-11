#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main() {

int sockfd,sport,eport,result;
char ip[16];

printf("Target IP: ");
scanf("%s", &ip);

printf("\nstarting port: ");
scanf("%d", &sport);

printf("\nending port: ");
scanf("%d", &eport);

struct sockaddr_in sr_addr;

sr_addr.sin_family = AF_INET;
sr_addr.sin_addr.s_addr = inet_addr(ip);

for(int i = sport; i < eport; i++) {
sr_addr.sin_port = htons(i);
sockfd = socket(AF_INET, SOCK_STREAM, 0);

result = connect(sockfd, (struct sockaddr *) &sr_addr, sizeof(sr_addr));

if(result >= 0) {

printf("open port; %d \n", i);

}
close(sockfd);
}

return EXIT_SUCCESS;

}
