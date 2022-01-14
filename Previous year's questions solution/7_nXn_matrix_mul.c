/*
Program : 7
Author  : Debottam
Topic   : Write a C program using OpenMP features to find the product of two nxn matrices. 
            The program should then find the sum of all the elements of the product matrix. 
*/
#include <stdio.h>
#include <omp.h>
#define N 3
int A[3][3];
int B[3][3];
int C[3][3];
int main()
{
   int i,j,k,l=1,s=0;
   int m= omp_get_num_procs();
   omp_set_num_threads(m);
   
   // Generating sample dataset
   for (i= 0; i< N; i++)
   {
        for (j= 0; j< N; j++)
        {
            A[i][j] = l;
            l++;
            B[i][j] = l;
            l++;
        }
   }
   printf("Matrix A: \n");
   for (i= 0; i< N; i++)
   {
        for (j= 0; j< N; j++)
            printf("%d\t",A[i][j]);
        printf("\n");
   }

   printf("Matrix B: \n");
   for (i= 0; i< N; i++)
   {
        for (j= 0; j< N; j++)
            printf("%d\t",B[i][j]);
        printf("\n");
   }

   #pragma omp parallel for shared(A,B,C) private(i,j,k)
   for (i = 0; i < N; ++i) 
   {
        for (j = 0; j < N; ++j) 
        {
            for (k = 0; k < N; ++k)
                C[i][j] += A[i][k] * B[k][j];
   	    }
   }
   printf("Product matrix C: \n");
   for (i= 0; i< N; i++)
   {
        for (j= 0; j< N; j++)
        {
            printf("%d\t",C[i][j]);
            s=s+C[i][j];
        }
   	    printf("\n");
    }
    printf("Sum of all elements of the product matrix = %d",s);
    return 0;
}