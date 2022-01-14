#include <stdio.h>
#include <omp.h>

int main(){
    int A[10], B[10] = {0,1,2,3,4,5,6,7,8,9}, C[10] = {0,1,2,3,4,5,6,7,8,9}, i, m, k;
    omp_set_dynamic(0);
    m = omp_get_num_procs();
    omp_set_num_threads(m);

    printf("Parallel\n------------");
    #pragma omp parallel for shared(A, B, C) private(i)

    for(i = 0; i < 10; i++){
        A[i] = B[i] + C[i];
        printf("\nB[%d] + C[%d] = %d + %d = %d = A[%d] from thread %d of %d", i, i, B[i], C[i], A[i], i, omp_get_thread_num(), omp_get_num_threads());
    }

    return 0;
}