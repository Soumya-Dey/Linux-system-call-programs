#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
  
int main(int argc, char* argv[])
{
    int c;
    if(argc>=2){
        for(c = 1; c < argc; c++){
            write(0, argv[c], strlen(argv[c]));
        }
    }

    return 0;
}