#include <stdio.h>
#include <omp.h>

int main(){
    int a[] = {2, 8, -5}, b[] = {6, -6, 9};
    int i, dot = 0, cross[3];

    omp_set_dynamic(0);
    int m = omp_get_num_procs();
    omp_set_num_threads(m);

    #pragma omp parallel for private(i) reduction(+:dot)
    for(i = 0; i < 3; i++){
   	    dot += a[i] * b[i];
    }

    #pragma omp parallel
    cross[0] = (a[1] * b[2]) - (a[2] * b[1]);
    cross[1] = (a[2] * b[0]) - (a[0] * b[2]);
    cross[2] = (a[0] * b[1]) - (a[1] * b[0]);

    printf("\nDot product = %d\n", dot);

    printf("Cross product = [  ");
    for (i = 0; i < 3; i++){
        printf("%d  ",cross[i]);
   	}
   	printf("]\n");

   	return 0;
}