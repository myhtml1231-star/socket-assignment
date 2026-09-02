#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int sock;
    struct sockaddr_in server_addr;
    char buf[100];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9000);

    inet_pton(AF_INET, "127.0.0.1",
              &server_addr.sin_addr);

    connect(sock,
            (struct sockaddr *)&server_addr,
            sizeof(server_addr));

    write(sock, "Hello Server", 13);

    read(sock, buf, sizeof(buf));

    printf("server message: %s\n", buf);

    close(sock);

    return 0;
}
