/*
Program : 11
Author  : Gyan
Topic   : Write a C program using OpenMP features to find the determinant of a 3x3 matrix.
*/

#include <stdio.h>
#include <omp.h>
int main()
{
    int i, m, D=0;
    int a[3][3] = { {1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 10}};

    m = omp_get_num_procs();
    omp_set_num_threads(m);


    #pragma omp parallel for shared(a, D) private(i)
    for(i=0;i<3;i++)
   	    D += a[0][i] *( a[1][(i+1)%3] * a[2][(i+2)%3] - a[1][ (i+2)%3] * a[2][(i+1)%3 ]);

    printf("\nDeterminant = %d\n",D);
   	return 0;
}