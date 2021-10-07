#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int id;
    id = fork();
    
    if(id < 0)
        printf("Error in fork\n");
    else if(id == 0){
        printf("Child Process - pid: %d, ppid: %d\n\n", getpid(), getppid());

        char *argv[] = {"./hello", NULL};
        int err = execv("./hello", argv);
        if(err == -1) printf("Error in execv\n %d", err);
    } else {
        printf("Parent Process - pid: %d\n\n", getpid());
    }

    return 0;
}