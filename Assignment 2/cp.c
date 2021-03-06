#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd, fd1;
    int i;
    char c;

    fd = open(argv[1], O_RDONLY);
    fd1 = open(argv[2], O_WRONLY | O_CREAT);
    if (fd < 0 || fd1 < 0){
        exit(1);
    }

    while(read(fd, &c, 1) > 0){
        write(fd1, &c, 1);
    }
    
    close(fd);
    close(fd1);

    return 0;
}