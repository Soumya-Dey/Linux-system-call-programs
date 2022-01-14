#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

struct node
{
    int dat;
    struct node *next;
};
typedef struct node node;

int count = 0;

int  enqueue(node **head, int d);
int  dequeue(node **head);
void disp(node *head);
void producer();
void consumer();

int main()
{
    node *head = NULL;
    int id;
    omp_set_dynamic(0);
    #pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();
        if(id == 0)
        {
            while(1)
            {
                producer(&head);
                fgetc(stdin);
            }
        }
        else
        {
            while(1)
            {
                consumer(&head);
                fgetc(stdin);
            }
        }
    }
    return 0;
}
void producer(node **head)
{
    #pragma omp critical
    {
        int x = enqueue(head, count+1);
        if(!x)
            printf("producer failed! memory full! \n");
        else
        {
            count++;
            printf("produced %d \n", count);
        }
    }
}
void consumer(node **head)
{
    #pragma omp critical
    {
        int x = dequeue(head);
        if(!x)
            printf("nothing left to consume!! \n");
        else   
            printf("consumed %d \n", x);
    }
}
int enqueue(node **head, int d)
{
    node *nn = (node *)malloc(sizeof(node));
    
    if(nn == NULL)//allocation failed
        return 0;

    nn->dat = d;
    nn->next = NULL;
    
    if(*head == NULL)
        *head = nn; 
    else
    {
        node *ptr = *head;
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = nn;
    }
    return 1;
}
int dequeue(node **head)
{
    int tmp;
    node *n;
    if(*head == NULL)//empty
        return 0;
    else
    {
        n = *head;
        tmp = (*head)->dat;

        *head = (*head)->next;
        free(n);
        return tmp;
    }
}
void disp(node *head)
{
    node *p = head;
    printf("List : ");
    while(p != NULL)
    {
        printf("%d ", p->dat);
        p = p->next;
    }
    printf("\n");
}