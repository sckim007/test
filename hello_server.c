#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
 
#define PORT     1010
#define MAXLINE 1024
 
int main()
{
    int sockfd;
    char recv_buffer[MAXLINE]={};
    char send_buffer[MAXLINE]={};
    char *hello = "Hello from server";
    struct sockaddr_in servaddr, cliaddr;

    char host_name[MAXLINE]={};
    if (gethostname(host_name, sizeof(host_name)) != 0)
    {
        printf("gethostname() failure./n");
        exit(1);
    } 
			     
    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family    = AF_INET; // IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    //Bind the socket with the server address
    if ( bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0 )
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    int len, n;
    while(1)
    {
      n = recvfrom(sockfd, (char *)recv_buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) &cliaddr, &len);
      recv_buffer[n] = '\0';
      printf("Client : %s\n", recv_buffer);
      memset(send_buffer, 0, sizeof(send_buffer));
      sprintf(send_buffer, "%s[hostname:%s]\n", hello, host_name); 
      sendto(sockfd, (const char *)send_buffer, strlen(send_buffer), MSG_CONFIRM, (const struct sockaddr *) &cliaddr, len);
      printf("Hello message sent.\n"); 
    }

    return 0;
}
