#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char c;
    int fd;
    int totalLine = 0;
    int totalWord = 0;
    long int totalChar = 0;

    int i = 1;
    while(argv[i] != NULL){
        int lineCount = 1;
        int wordCount = 1;
        int charCount = 0;

        fd = open(argv[i], O_RDONLY);

        if(fd < 0){
            printf("Error opening %s", argv[i]);
            i++;
            continue;
        }

        while(read(fd, &c, 1) > 0){
            if(c == ' ') wordCount++;
            else if(c == '\n') {
                lineCount++;
                wordCount++;
            }
        }
        printf("%d ", lineCount);
        printf("%d ", wordCount);
        printf("%ld ", lseek(fd, 0, SEEK_END));
        printf("%s\n", argv[i]);
        totalLine += lineCount;
        totalWord += wordCount;
        totalChar += lseek(fd, 0, SEEK_END);
        close(fd);
        i++;
    }
    printf("%d ", totalLine);
    printf("%d ", totalWord);
    printf("%ld ", totalChar);
    printf("total\n");

    return 0;
}