#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int id, fd;
    char c;
        
	fd = open("sample.txt", O_WRONLY | O_CREAT);
	if (fd < 0){
	    exit(1);
	}
	 
	printf("Enter the contents of write to the file (press / to stop): \n");
    read(0, &c, 1);
    while(c != '/'){
        write(fd, &c, 1);
        read(0, &c, 1);
    }

    close(fd);

    id = fork();
    if(id < 0)
        printf("Error in fork\n");
    else if(id == 0){
        printf("Inside Child Process\n");
        fd = open("sample.txt", O_RDONLY);
        if(fd < 0){
            exit(1);
        }
	 
        int size = lseek(fd, 0, SEEK_END);
        printf("File size: %d\n", size);
        
        close(fd);
    } else {
        wait(NULL);
    }
	
	return 0;
}