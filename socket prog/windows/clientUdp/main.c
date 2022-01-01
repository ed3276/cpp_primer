#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <winsock2.h>
#include <WS2tcpip.h>
int main()
{
    int s;;
    int len=0;
    char servName[] = "192.168.1.7";
    int servPort = 5678;
    char string[] = "Hello, how are you?";
    char buffer[256+1];
    struct sockaddr_in servAddr;

#if 0
    if(argc!=4)
    {
        printf("Error: 3 arguments are needed.\n");
        exit(1);
    }
    servName=argv[1];
    servPort=atoi(argv[2]);
    string=argv[3];
#endif // 0

    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2,2),&wsa) != 0)
    {
        printf("WSAStartup error\n");
        return 0;
    }
    memset(&servAddr,0,sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    //inet_pton(AF_INET,servName,&servAddr.sin_addr);
    servAddr.sin_addr.s_addr = inet_addr(servName);
    servAddr.sin_port = htons(servPort);

    if((s=socket(PF_INET,SOCK_DGRAM,0))<0)
    {
        perror("Error: socket failed!");
        exit(1);
    }

    sendto(s,string,strlen(string),0,(struct sockaddr*)&servAddr,sizeof(servAddr));
    printf("I am waiting for echo message ...\n");
    len = recvfrom(s,buffer,sizeof(buffer),0,NULL,NULL);
    buffer[len]='\0';
    printf("Echo string received: \n%s\n\n",buffer);

    closesocket(s);

    WSACleanup();
    return 0;
}
