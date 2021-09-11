// #include<stdio.h>
// #include<sys/types.h>
// #include<sys/socket.h>
// #include<netdb.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #include<time.h>
// int main(int argc,char *argv[])
// {
// int sd,ad;
// char buff[1024];
// struct sockaddr_in cliaddr,servaddr;
// struct hostent *h;
// h=gethostbyname(argv[1]);
// bzero(&servaddr,sizeof(servaddr));

// /*Socket address structure*/ 
// servaddr.sin_family=AF_INET;
// memcpy((char*)&servaddr.sin_addr.s_addr,h->h_addr_list[0],h->h_length);
// servaddr.sin_port=htons(1507);

//              /*TCP socket is created, an Internet socket address structure is filled with                 
//             wildcard address & server’s well  known port*/   
// sd=socket(AF_INET,SOCK_STREAM,0);

//             /*Connect establishes connection with the server using server IP address*/
// 	connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
// recv(sd,buff,sizeof(buff),0);
// printf("Day time of server is: %s\n",buff); 
// return 0;
// }

#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    int sd, ad;
    char buff[1024];
    struct sockaddr_in cliaddr, servaddr;
    struct hostent *h;
    h = gethostbyname(argv[1]);
    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    memcpy((char *)&servaddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
    servaddr.sin_port = htons(1507);
    sd = socket(AF_INET, SOCK_STREAM, 0);

    connect(sd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    recv(sd, buff, sizeof(buff), 0);
    printf("Day time of server is: %s\n", buff);
    return 0;
}
