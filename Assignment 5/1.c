#include <stdio.h>
#include <omp.h>

int factorial(int n){
    int f = 1, i;

    #pragma omp parallel for reduction(*:f)
    for(i = 1; i <= n; i++){    
        f *= i;    
    }

    return f;
}

int main(){
    int n, i, sum = 1;
    omp_set_dynamic(0);

    printf("Enter the value of N = ");
    scanf("%d", &n);

    int m = omp_get_num_procs();
    omp_set_num_threads(m);


    #pragma omp parallel for reduction(+:sum)
    for(i = 2; i <= n; i++){
        sum += factorial(i);
    }

    printf("Sum = %d\n", sum);
    
    return 0;
}