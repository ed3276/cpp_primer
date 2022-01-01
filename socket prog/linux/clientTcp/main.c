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
    int s;
    int len=0;
    char servName[] = "176.122.136.190";
    int servPort = 1234;
    char string[256] = "Hello, how are you?";
    char buffer[1024+1];
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

    if((s=socket(PF_INET,SOCK_STREAM,0))<0)
    {
        perror("Error: socket failed!");
        exit(1);
    }
    printf("start connecting to the %s ...\n",servName);
    connect(s,(struct sockaddr*)&servAddr,sizeof(servAddr));
    printf("connect is OK\n");

    int size = 10000;
    memset(string,0,sizeof(string));
    sprintf(string,"%d",size);
    printf("I have %d string to send, are you ready?\n",size);
    send(s,string,strlen(string),0);
    printf("I am waiting for echo message ...\n");
    len = recv(s,buffer,sizeof(buffer),0);
    buffer[len]='\0';
    printf("Echo string received %d characters: %s\n\n",strlen(buffer),buffer);
    printf("starting tranfer...\n");
    for(int i=0;i<size;++i)
    {
        memset(string,0,sizeof(string));
        sprintf(string,"Hello, how are you %d / %d ?",i+1,size);

        send(s,string,strlen(string),0);
        printf("I am waiting for %d echo message ...\n",i+1);
        len = recv(s,buffer,sizeof(buffer),0);
        buffer[len]='\0';
        printf("Echo string received %d characters: \n%s\n\n",strlen(buffer),buffer);
        //Sleep(10);
    }
    closesocket(s);

    WSACleanup();
    return 0;
}
