/*
Program : 3
Author  : Anish
Topic   : Write a C program using OpenMP features to create two parallel threads. 
            The first thread should insert the first ‘N’ natural numbers into a queue in sequence, 
            and the second thread should remove the numbers from the queue. 
*/
#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("\n ENTER THE VALUE OF N \n");
    scanf("%d",&n);
    
    int id,d,Q[n],rear=-1,front=0,i=1;
    omp_set_dynamic(0);

    #pragma omp parallel num_threads(2)
    {
        id=omp_get_thread_num();

        if(id==0) //insert
        {
            while(1)
            {
                #pragma omp critical
                {
                    if(rear<n-1)
                    {
                        Q[++rear]=i;
                        printf("\n INSERTED ITEM IS %d",i);
                        i++;
                    }
                    else 
                        printf("\n  NO SPACE");
                    fgetc(stdin);
                }
            }
        }
        else
        while(1) //pop
        {
            #pragma omp critical
            {
                if(front<=rear)
                {
                    d=Q[front];
                    front++;
                    printf("\n DELETED ITEM IS %d",d);
                }
                else 
                    printf("\n  NO ITEMS TO DELETE");
                fgetc(stdin);
            }
        }
    }
    return 0;
}