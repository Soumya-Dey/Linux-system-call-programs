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
        int err = execv("./myEcho", argv);
        if(err == -1) printf("Error in execv\n %d", err);
    } else {
        wait(NULL);
    }

    return 0;
}