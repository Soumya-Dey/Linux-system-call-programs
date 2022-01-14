/*
Program : 1
Author  : Anish
Topic   : Write a C program using OpenMP features to create two parallel threads. 
            The first thread should push the first ‘N’ natural numbers into a stack 
            in sequence, and the second thread should pop the numbers from the stack. 
*/

#include<stdio.h>
#include<omp.h>
#include<stdlib.h>

int main()
{
    int n,a;
    printf("\n ENTER THE VALUE OF N \n");
    scanf("%d",&n);
    int id,d,Q[n],top=-1;
    omp_set_dynamic(0);

    #pragma omp parallel num_threads(2)
    {
        id=omp_get_thread_num();
        if(id==0) //push
        {
            while(1)
            {
                #pragma omp critical
                {
                    if(top<n-1)
                    {
                        printf("\n ENTER A NUMBER \n");
                        scanf("%d",&a);
                        Q[++top]=a;
                        printf("\n INSERTED ITEM IS %d",a);
                    }
                    else 
                        printf("\n  NO SPACE");
                    fgetc(stdin);
                }
            }
        }
        else
        {
            while(1) //pop
            {
                #pragma omp critical
                {
                    if(top!=-1)
                    {
                        d=Q[top];
                        top--;
                        printf("\n DELETED ITEM IS %d",d);
                    }
                    else 
                        printf("\n  NO ITEMS TO DELETE");
                    fgetc(stdin);
                }
            }
        }
    }
    return 0;
}