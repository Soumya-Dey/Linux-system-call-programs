/*
Program : 12
Author  : Soumili
Topic   : Write a C program using OpenMP features to 
            find the column wise average of a matrix in linear time complexity. 
*/

#include<stdio.h>
#include<omp.h>
int main()
{
    int i,j,k,m,sum,avgc;    
    int A[3][3]={1,2,3,
           4,5,6,
           7,8,9};
    omp_set_dynamic(0);
    m=omp_get_num_procs();
    omp_set_num_threads(m);
    #pragma omp parallel for shared(A) private(i,j,sum,avgc)
    for(i=0;i<3;i++)
    {
        sum =0;
        for(j=0;j<3;j++)
        {
            sum=sum+A[j][i];
        }
        avgc=sum/3;
        printf(" Average of %d column is %d from thread %d of %d\n",i+1,avgc,omp_get_thread_num(),omp_get_num_threads());
    }
    return 0;
}