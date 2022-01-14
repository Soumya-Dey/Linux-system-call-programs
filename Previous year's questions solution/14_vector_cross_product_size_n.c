/*
Program : 14
Author  : Debottam
Topic   : Write a C program using OpenMP features to find the cross product 
            of two vectors of size n each in constant time complexity. 
            [Hint: Cross product C[i] = (A[i]*B[i])]
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
	
    #pragma omp parallel for shared(C) private(i)
    for(i=0;i<N;i++)
    {
   	    C[i]=A[(i+1)%N]*B[(i+2)%N]-A[(i+2)%N]*B[(i+1)%N];
    }
    
    printf("Cross product, C = ");
    for (i= 0; i< N; i++)
        printf("%d\t",C[i]);

    printf("\n");
    return 0;
 }