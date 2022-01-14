/*
Program : 8
Author  : Debottam
Topic   : Write a C program using OpenMP features to find the cross 
            product of two vectors in constant time complexity.
*/
#include <stdio.h>
#include <omp.h>
int main()
{
    int A[]={3,-5,4},i;
    int B[]={2,6,5},C[3],D=0;
    int m= omp_get_num_procs();
    omp_set_num_threads(m);
	
    #pragma omp parallel for shared(C) private(i)
    for(i=0;i<3;i++)
    {
   	    C[i]=A[(i+1)%3]*B[(i+2)%3]-A[(i+2)%3]*B[(i+1)%3];
    }

    printf("Cross product, C = ");
    for (i= 0; i< 3; i++)
        printf("%d\t",C[i]);
        
     printf("\n");
     return 0;
 }