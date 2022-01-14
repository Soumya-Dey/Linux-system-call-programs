#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int id;
    int fd;

    id = fork();
    if(id < 0)
        printf("Error in fork\n");
    else if(id == 0){
        // child process 1: creating the file
        printf("Child Process 1\n");
        char c;
        
        fd = open(argv[1], O_WRONLY | O_CREAT);
        if (fd < 0){
            printf("Error in opening the file\n");
            exit(1);
        }
        
        printf("Enter the contents of write to the file (press / to stop): \n");
        do{
            write(fd, &c, 1);
            read(0, &c, 1);
        }
        while(c != '/');
        
        close(fd);
    } else {
        wait(NULL);

        id = fork();
        if(id < 0)
            printf("Error in fork\n");
        else if(id == 0){
            // child process 2: showing the contents of the file
            printf("Child Process 2\n");
            char c;
            
            fd = open(argv[1], O_RDONLY);
            if (fd < 0){
                printf("Error in opening the file\n");
                exit(1);
            }
            
            printf("\nThe contents of the file: \n");
            while(read(fd, &c, 1) > 0)
                write(0, &c, 1);
            
            close(fd);
        } else {
            wait(NULL);
        }
    }
	
	return 0;
}