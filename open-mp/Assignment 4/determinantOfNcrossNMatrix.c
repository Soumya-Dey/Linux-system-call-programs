#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <omp.h>

#define   SIZE   10

int main(){
	 float mat[SIZE][SIZE], ratio, det = 1;
	 int i,j,k,n;

	 printf("Enter Matrix Dimension = ");
	 scanf("%d", &n);

	 printf("\nEnter Elements: \n");
	 for(i = 0; i < n; i++){
		for(j = 0; j < n;j++){
			printf("mat[%d][%d] = ", i, j);
			scanf("%f", &mat[i][j]);
		}
	 }

     printf("\nMatrix: \n");
	 for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%0.2f\t", mat[i][j]);
		}
		printf("\n");
	 }

	 for(i = 0; i < n; i++){
		  if(mat[i][i] == 0.0){
			   printf("Mathematical Error!");
			   exit(0);
		  }

		  for(j = i + 1; j < n; j++){
			   ratio = mat[j][i] / mat[i][i];

			   for(k = 0; k < n; k++){
			  		mat[j][k] = mat[j][k] - ratio * mat[i][k];
			   }
		  }
	 }

     #pragma omp parallel for shared(mat) private(i) reduction(*:det)
	 for(i = 0; i < n; i++){
        det *= mat[i][i];
     }

	 printf("\nDeterminant of given matrix is: %0.3f\n", det);

	 return 0;
}