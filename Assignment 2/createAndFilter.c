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
	while(read(0, &c, 1) > 0){
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            write(fd, &c, 1);
    }
	 
	close(fd);
	
	return 0;
}