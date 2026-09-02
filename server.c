#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main()
{
    int server_sock, client_sock;
    struct sockaddr_in server_addr;
    char buf[100];

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(9000);

    bind(server_sock,
         (struct sockaddr *)&server_addr,
         sizeof(server_addr));

    listen(server_sock, 5);

    printf("Waiting for client connection...\n");

    client_sock = accept(server_sock, NULL, NULL);

    read(client_sock, buf, sizeof(buf));

    printf("Client Message: %s\n", buf);

    write(client_sock, "Hello Client", 13);

    close(client_sock);
    close(server_sock);

    return 0;
}
