#include <stdio.h>
#include <omp.h>

int main(){
    int A[10] = {0,1,2,3,4,5,6,7,8,9}, i, m, sum = 0;
    omp_set_dynamic(0);
    m = omp_get_num_procs();
    omp_set_num_threads(m);

    printf("Parallel\n------------");
    #pragma omp parallel for reduction(+:sum)

    for(i = 0; i < 10; i++){
        sum += A[i];
        printf("\n%d from thread %d of %d", sum, omp_get_thread_num(), omp_get_num_threads());
    }

    printf("\n\nSum = %d\n", sum);

    return 0;
}