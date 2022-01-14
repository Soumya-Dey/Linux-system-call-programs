/*
Program : 13
Author  : Debottam
Topic   : Write a C program using Open MP features to find the dot 
            product of two vectors of size n each in constant time complexity. 
            [Hint: Dot product = Ʃ(A[i]*B[i])]
*/

#include <stdio.h>
#include <omp.h>
#define N 3
int main()
{
    int A[]={3,-5,4},i;
    int B[]={2,6,5},C[N],D=0;
    int m= omp_get_num_procs();
    omp_set_num_threads(m);
    #pragma omp parallel for shared(D) private(i)
    for(i=0;i<N;i++)
    {
   	    D=D+(A[i]*B[i]);
    }
	printf("\nDot product, D = A.B = %d\n",D);
	return 0;
}