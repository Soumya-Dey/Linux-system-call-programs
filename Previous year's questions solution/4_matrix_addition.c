/*
Program : 4
Author  : Gyan
Topic   : Write a C program using OpenMP features to find the sum of 
            two matrices in linear time. The program should then find row wise 
            average of the sum matrix.
*/

#include<stdio.h>
#include<omp.h>

int main()
{
    int n, m, i, j, sum;
    omp_set_dynamic(0);
    m = omp_get_num_threads();
    omp_set_num_threads(m);

    printf("enter the dimension of the matrix:");
    scanf("%d", &n);

    int a[n][n], b[n][n], c[n][n], avg[n];

    printf("enter matrix a :: \n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
            scanf("%d", &a[i][j]);
    }

    printf("enter matrix b :: \n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
            scanf("%d", &b[i][j]);
    }

    for(i = 0 ; i < n ; i++)
    {
        #pragma parallel for shared(a, b, c) private(j)
        for(j = 0 ; j < n ; j++)
            c[i][j] = a[i][j] + b[i][j];
    }
    
    for(i = 0 ; i < n ; i++)
    {
        sum = 0;
        #pragma parallel for shared(c, sum) private(j)
        for(j = 0 ; j < n ; j++)
            sum += c[i][j];
        avg[i] = sum / n;
    } 

    printf("sum matrix ::  \n");
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
            printf("%d \t", c[i][j]);
        printf("\n");
    }  

    printf("row wise avg ::  ");
    for(j = 0 ; j < n ; j++)
        printf("%d \t", avg[j]);
    
    return 0;
}