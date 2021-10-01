/*
Soumya Dey
Roll: 537
*/

/*
Question 1:

Write a C program by using the system calls to create a new text file by accepting the text from the standard input.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char c;
        
	int fd = open(argv[1], O_WRONLY | O_CREAT);
	if (fd < 0){
	    exit(1);
	}
	 
	printf("Enter the contents of write to the file (CTRL+Z to stop): \n\n");
	while(read(0, &c, 1) > 0)
		write(fd, &c, 1);
	 
	close(fd);
	
	return 0;
}

/* 
----------------------------------
Output:
----------------------------------

$ gcc createFile.c -o createFile
$ ./createFile file1.txt

Enter the contents of write to the file (CTRL+Z to stop):

Hello World!
I am Soumya...
^Z
[7]+  Stopped                 ./createFile file1.txt

$ cat file1.txt

Hello World!
I am Soumya...
*/



