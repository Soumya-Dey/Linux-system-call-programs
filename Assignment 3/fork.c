#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int id;
    id = fork();
    
    if(id < 0)
        printf("Error in fork\n");
    else if(id == 0){
        // calling the myEcho program and passing the argument array to it
        // myEcho program will print the arguments in command line
        int err = execv("./myEcho", argv);
        if(err == -1) printf("Error in execv\n %d", err);
    } else {
        wait(NULL);
    }

    return 0;
}