
/*
Program : 6
Author  : Anish
Topic   : Write a C program using OpenMP features to implement one reader 
        and one writer threads. The reader thread should display the value 
        of a global variable, whereas the writer thread should increment the 
        value of the global variable. Both the threads should run infinitely. 
*/

#include<stdio.h>
#include<omp.h>

int main()
{
    int a=10,id;
    omp_set_dynamic(0);
    #pragma omp parallel num_threads(2)
    {
        id=omp_get_thread_num();
        if(id==0) //reader
        {
            while(1)
            {
                #pragma omp critical
                {
                    printf("\n READER THREAD %d",a);
                }
            }
        }
        else
        {
            while(1) //writer
            {
                #pragma omp critical
                {
                    ++a;
                    printf("\n WRITER THREAD");
                }
            }
        }
    }
    return 0;
}