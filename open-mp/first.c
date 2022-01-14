#include <stdio.h>
#include <omp.h>

int main(){
    printf("No. of processor: %d\n", omp_get_num_procs());
    printf("Max No. of threads: %d\n", omp_get_max_threads());
    return 0;
}