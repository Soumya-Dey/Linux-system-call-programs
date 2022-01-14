#include <stdio.h>
#include <omp.h>

int main(){
    int A[10] = {1,2,3,4,5,6,7,8,9,10}, i, m, k;
    omp_set_dynamic(0);
    m = omp_get_num_procs();
    printf("Max No. of threads: %d\n", omp_get_max_threads());

    omp_set_num_threads(6);
    #pragma omp parallel

    printf("Hello from thread no. %d of total %d threads\n", omp_get_thread_num(), omp_get_num_threads());

    return 0;
}