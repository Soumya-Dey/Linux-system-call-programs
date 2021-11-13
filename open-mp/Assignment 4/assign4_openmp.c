#include<stdio.h>
#include<omp.h>
int main()
{
	int mat[3][3],i,j,m;
  	int det=0;
	printf("\nInput elements:");
        for(i=0;i<3;i++)
        {
            	for(j=0;j<3;j++)
            	{
	           	scanf("%d",&mat[i][j]);
           	}
        }  
	printf("\nThe Original Matrix is :\n");
	for(i=0;i<3;i++)
	{
	   	for(j=0;j<3 ;j++)
	     		printf("%2d",mat[i][j]);
	    	printf("\n");
	}
	m=omp_get_num_procs();
	omp_set_num_threads(m);
	#pragma omp parallel for shared(mat) private(i) reduction(+:det)
	for(i=0;i<3;i++)
		det = det + (mat[0][i]*(mat[1][(i+1)%3]*mat[2][(i+2)%3] - mat[1][(i+2)%3]*mat[2][(i+1)%3]));
	printf("\nThe Determinant value is: %d\n",det);
	return 0;
}
