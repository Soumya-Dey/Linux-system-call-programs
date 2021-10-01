#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd;
    char buffer[fd];
    long int bytes;

    int i = 1;
    while(argv[i] != NULL){
        fd = open(argv[i], O_RDONLY);

        if(fd < 0){
            printf("Error opening %s", argv[i]);
            i++;
            continue;
        }

        bytes = read(fd, buffer, sizeof(buffer)-1);
        write(0, buffer, bytes);

        close(fd);
        i++;
    }

    return 0;
}