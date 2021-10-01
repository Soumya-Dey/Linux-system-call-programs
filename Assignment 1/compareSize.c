/*
Soumya Dey
Roll: 537
*/

/*
Question 3:

Write a C program to check whether the sizes of the files created in (1) and (2) are same or not.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[2], O_RDONLY);
    if(fd1 < 0 || fd2 < 0){
        exit(1);
    }
	 
	int size1 = lseek(fd1, 0, SEEK_END);
	int size2 = lseek(fd2, 0, SEEK_END);

	printf("1st file: %d\n", size1);
	printf("Copy of 1st file: %d\n", size2);
	printf("\nIs Size same? %s\n", size1 == size2 ? "true" : "false");
	 
	close(fd1);
	close(fd2);

	return 0;
}

/* 
----------------------------------
Output:
----------------------------------

$ gcc compareSize.c -o compareSize
$ ./compareSize file1.txt copy-of-file1.txt

1st file: 28
Copy of 1st file: 28

Is Size same? true
*/
