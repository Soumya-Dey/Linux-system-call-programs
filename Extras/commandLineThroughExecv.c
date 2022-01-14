#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int id, source;
	id = fork();

	if (id == 0){
		printf("line | word | bytes | file_name\n");
		// char* c[] = {"/bin/wc","-w", "-l", "-c", argv[1],NULL};
		char* c[] = {"/bin/ls",NULL};

    	execv(c[0],c);
	}
	else if(id > 0){
		wait(NULL);
		printf("\n---------------------------------------\n");
		printf("IN the Parent process!!\n");
		printf("\n---------------------------------------\n");

		
		printf("Exiting...\n");
	}
	return 0;
}