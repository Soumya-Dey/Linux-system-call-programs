#include <stdio.h>
#include <omp.h>

int main(){
    int i, j, n;
    double sum = 0.0;
    
    printf("Enter matrix dimension = ");
    scanf("%d", &n);
    int a[n][n];

    printf("Enter matrix values\n");
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    omp_set_dynamic(0);
    int m = omp_get_num_procs();
    omp_set_num_threads(m);

    for (i = 0; i < n; i++){
        #pragma omp parallel for reduction(+:sum)
        for (j = 0; j < n; j++){
            sum += a[i][j];
        }
    }

    printf("\nAverage = %.2f\n", sum / (n*n));

    return 0;
}