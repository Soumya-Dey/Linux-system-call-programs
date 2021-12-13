#include <stdio.h>
#include <math.h>
#include <omp.h>

int main(){
    int x, n, i, sum = 1;
    omp_set_dynamic(0);

    printf("Enter the values\nx = ");
    scanf("%d", &x);
    printf("N = ");
    scanf("%d", &n);

    int m = omp_get_num_procs();
    omp_set_num_threads(m);

    #pragma omp parallel for reduction(+:sum)
    for(i = 1; i <= n; i++){
        sum += pow(x, i);
    }

    printf("Sum = %d\n", sum);

    return 0;
}