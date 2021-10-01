/*
Soumya Dey
Roll: 537
*/

/*
Question 2:

Write a C program by using the system calls to make a copy of the text file created in (1).
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd1, fd2;
    char buffer[1024];
    long int n1;

    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[2], O_WRONLY | O_CREAT);
    if(fd1 < 0 || fd2 < 0){
        exit(1);
    }

    printf("Copying the contents of file1 to file2... \n\n");
    while((n1 = read(fd1, buffer, 1024)) > 0){
        if(write(fd2, buffer, n1) != n1){
            exit(1);
        }
    }
    
    close(fd1);
    close(fd2);

    return 0;
}

/* 
----------------------------------
Output:
----------------------------------

$ gcc copyFile.c -o copyFile
$ ./copyFile file1.txt copy-of-file1.txt

Copying the contents of file1 to file2...

$ cat copy-of-file1.txt

Hello World!
I am Soumya...
*/
