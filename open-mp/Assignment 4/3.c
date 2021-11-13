#include <stdio.h>
#include <omp.h>

int main(){
	int mat[3][3], det = 0, i, j;

    omp_set_dynamic(0);
    int m = omp_get_num_procs();
    omp_set_num_threads(m);

	printf("\nEnter elements:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("matrix[%d][%d] = ", i, j);
	       	scanf("%d", &mat[i][j]);
        }
    }  

	printf("\nMatrix:\n");
	for(i = 0; i < 3; i++){
	   	for(j = 0; j < 3 ; j++){
	     	printf("%2d ",mat[i][j]);
        }
	    printf("\n");
	}

	#pragma omp parallel for shared(mat) private(i) reduction(+:det)
	for(i = 0; i < 3; i++)
		det += (mat[0][i]*(mat[1][(i+1)%3]*mat[2][(i+2)%3] - mat[1][(i+2)%3]*mat[2][(i+1)%3]));

	printf("\nDeterminant = %d\n",det);

	return 0;
}
