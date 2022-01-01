#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#define SERVER_PORT 1234

int main()
{
    int sc, sd;
    int len;
    char buffer[128];
    struct sockaddr_in servAddr;
    struct sockaddr_in clntAddr;
    int clntAddrLen = sizeof(clntAddr);

    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("WSAStartup error\n");
        return 0;
    }

    memset(&servAddr,0,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SERVER_PORT);
    servAddr.sin_addr.s_addr = htons(INADDR_ANY);

    printf("start building server.\n");
    if((sc=socket(PF_INET,SOCK_STREAM,0))<0)
    {
        perror("Error: socket failed!");
        exit(1);
    }
    else
    {
        printf("socket build is OK.\n");
    }
    if(bind(sc,(struct sockaddr*)&servAddr,sizeof(servAddr))<0)
    {
        perror("Error: bind failed!");
        exit(1);
    }
    else
    {
		printf("bind is OK.\n");
    }

    if(listen(sc,5)!=0)
    {
        perror("Error: listen failed!");
        exit(1);
    }
    else
    {
		printf("listening is OK.\n");
    }
    while(1)
    {
        sd = accept(sc,(struct sockaddr*)&clntAddr,&clntAddrLen);
        printf("waiting for client to send message ...\n");
        len = recv(sd,buffer,sizeof(buffer),0);
        buffer[len] = '\0';
        if(send(sd,buffer,len,0)) {printf("connect is Failure. error code: %d.\n",WSAGetLastError());printf("ERROR INFO: %s\n",strerror(errno));perror("FAIL info:");exit(1);}
        printf("the %d client is coming, I have received a message:\n",sd);
		printf("%s\n\n",buffer);
    }
    return 0;
}
