#include <stdio.h>
#include <omp.h>

void f1(){
    printf("Function 1");
}
void f2(){
    printf("Function 2");
}
void f3(){
    printf("Function 3");
}

int main(){
    omp_set_dynamic(0);
    m = omp_get_num_procs();
    omp_set_num_threads(m);

    printf("Parallel\n------------");
    #pragma omp parallel sections{
        
    }

    for(i = 0; i < 10; i++){
        sum += A[i];
        printf("\n%d from thread %d of %d", sum, omp_get_thread_num(), omp_get_num_threads());
    }

    printf("\n\nSum = %d\n", sum);

    return 0;
}