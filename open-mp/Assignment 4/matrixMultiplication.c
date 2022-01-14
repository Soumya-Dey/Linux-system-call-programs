#include <stdio.h>
#include <omp.h>

int main(){
   int a[3][3], b[3][3], c[3][3];
   int i,j,k,l=1;

   omp_set_dynamic(0);
   int m = omp_get_num_procs();
   omp_set_num_threads(m);

   for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            a[i][j] = l;
            b[i][j] = 10 - l;
            l++;
        }
   }

   printf("\nA: \n");
	for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
                printf("%d ", a[i][j]);
        }
        printf("\n");
   }
   printf("\nB: \n");
   for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
                printf("%d ", b[i][j]);
        }
        printf("\n");
   }

   #pragma omp parallel for shared(a, b, c) private(i, j, k) 
   for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            int sum = 0;
            #pragma omp parallel for private(k) reduction(+:sum)
            for (k = 0; k < 3; ++k){
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
   }

   printf("\nC: \n");
   for (i= 0; i< 3; i++){
        for (j= 0; j< 3; j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
   }

   return 0;
}