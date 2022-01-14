
/*
Program : 10
Author  : Gyan
Topic   : 10.Write a C program using OpenMP features to find the sum 
            of the first ‘n’ terms of the following series: 
            X.(X+1) + (X+1).(X+2) + (X+2)(X+3) + …
            Where, ‘X’ and ‘n’ are two values input by the user.
*/

#include<stdio.h>
#include<omp.h>


int main()
{
    int x, n, sum, i, m;

    omp_set_dynamic(0);
    m = omp_get_num_threads();
    omp_set_num_threads(m);

    printf("enter value of x and n:: ");
    scanf("%d%d", &x, &n);

    sum = 0;
    #pragma parallel for reduction(+:sum)
    for(i = 0 ; i < n ; i++)
        sum += (x+i)*(x+i+1);

    printf("The sum of the series is :: %d \n", sum);

    return 0;
}