#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	char c;
    int n;
    printf("Enter value of N: ");
    scanf("%d", &n);
        
	int fd = open(argv[1], O_WRONLY | O_CREAT);
	if (fd < 0){
	    exit(1);
	}
	 
    int i = 1;
	printf("Enter the contents of write to the file (CTRL+Z to stop): \n\n");
	while(read(0, &c, 1) > 0){
		if(i % n == 0)
            write(fd, &c, 1);

        i++;
    }
	 
	close(fd);
	
	return 0;
}