#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd = open(argv[1], O_RDONLY);
    if(fd < 0){
        exit(1);
    }
	 
	int size = lseek(fd, 0, SEEK_END);

	printf("File size: %d\n", size);
	 
	close(fd);

	return 0;
}