
/*
Program : 2
Author  : Gyan
Topic   : Write a C program using OpenMP features to create three parallel threads. 
            The first thread should display the value of a global variable, ‘X’; the 
            second thread should increment the value of the same global variable, ‘X’ 
            and the third thread should decrement the value of ‘X’. 
*/

#include<stdio.h>
#include<omp.h>

int main()
{
    int a=0,id;
    omp_set_dynamic(0);
    #pragma omp parallel num_threads(3)
    {
        id=omp_get_thread_num();
        if(id == 0)
        {
            while(1)
            {
                #pragma omp critical
                    printf("Data =  %d\n",a);
            }
        }
        else if(id == 1)
        {
            while(1)
            {
                #pragma omp critical
                {
                    a++;
                    printf("Increment \n");
                }
            }
        }
        else
        {
            while(1)
            {
                #pragma omp critical
                {
                    a--;
                    printf("Decrement \n");
                }
            }
        }
    }
    return 0;
}