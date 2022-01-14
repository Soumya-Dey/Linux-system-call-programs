#include <stdio.h>
#include <omp.h>

int x = 5;
void first(){
    #pragma omp critical
    {
        x++;
        printf("Frist function: x=%d\n", x);
    }
}

void second(){
    #pragma omp critical
    {
        x--;
        printf("Second function: x=%d\n", x);
    }
}

int main(){
    #pragma omp parallel sections
    {
        #pragma omp section
            first();

        #pragma omp section
            second();
    }

    printf("\nFinal value: x=%d\n", x);

    return 0;
}