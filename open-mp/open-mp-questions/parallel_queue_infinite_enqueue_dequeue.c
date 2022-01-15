#include<stdio.h>
#include<omp.h>
#include<stdlib.h>
int main()
{
    int n,a,num = 0;
    printf("\n ENTER THE VALUE OF N \n");
    scanf("%d",&n);
    int id,d,Q[n],rear=-1,front=-1;
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
                        Q[++rear]=num;
                        printf("\n INSERTED ITEM IS %d",num);
                        num++;
                    }
                    else
                        printf("\n NO SPACE");
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
                    if(front == rear && front != -1)
                    {
                        d=Q[front];
                        front = -1;
                        rear = -1;
                        printf("\n DELETED ITEM IS %d",d);
                    }
                    if(front<rear)
                    {
                        d=Q[front];
                        front++;
                        printf("\n DELETED ITEM IS %d",d);
                    }
                    else
                        printf("\n NO ITEMS TO DELETE");
                    fgetc(stdin);
                }
            }
        }
    }
    
    return 0;
}