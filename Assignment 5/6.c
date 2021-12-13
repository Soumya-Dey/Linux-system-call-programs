#include <stdio.h>
#include <omp.h>

int main(){
    int i, j, n;
    double sum;
    
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

    #pragma omp parallel for shared(a) private(i, j, sum)
    for (i = 0; i < n; i++){
        sum = 0.0;
        for (j = 0; j < n; j++){
            sum += a[i][j];
        }
        printf("Row %d => Average = %.2f [thread %d of %d]\n", i, sum / n, omp_get_thread_num(),omp_get_num_threads());
    }


    return 0;
}