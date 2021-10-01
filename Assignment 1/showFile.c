/*
Soumya Dey
Roll: 537
*/

/*
Question 4:

Write a C program by using C system calls to display the contents of a text file. If the text file does not exist then create it with 0 length.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd;
    char buffer[fd];
    long int bytes;

    fd = open(argv[1], O_RDONLY | O_CREAT);
    if (fd < 0){
        exit(1);
    }

    printf("The contents of file: \n\n");
    bytes = read(fd, buffer, sizeof(buffer)-1);
    write(0, buffer, bytes);
    
    close(fd);

    return 0;
}

/* 
----------------------------------
Output:
----------------------------------

$ gcc showFile.c -o showFile
$ ./showFile copy-of-file1.txt

The contents of file:

Hello World!
I am Soumya...
*/