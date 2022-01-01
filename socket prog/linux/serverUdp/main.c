#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>

int main()
{
    int s;
    int len;
    char buffer[256];
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    int clntAddrLen;
    memset(&servAddr,0,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if((s=socket(PF_INET,SOCK_DGRAM,0))<0)
    {
        perror("Error: socket failed!");
        exit(1);
    }
    if(bind(s,(struct sockaddr*)&servAddr,sizeof(servAddr))<0)
    {
        perror("Error: bind failed!");
        exit(1);
    }

    while(1)
    {
        len = recvfrom(s,buffer,sizeof(buffer),0,(struct sockaddr*)&clntAddr,&clntAddrLen);
        sendto(s,buffer,len,0,(struct sockaddr*)&clntAddr,sizeof(clntAddr));
    }
    return 0;
}
