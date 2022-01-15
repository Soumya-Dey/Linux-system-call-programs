#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

struct Node{
  int data;
  struct Node *next;
};

struct Node* head = NULL;

void insertLast(struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data  = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL){
       *head_ref = new_node;
       return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

struct Node* deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL){
       printf("List is empty!");
       return NULL;
    }

   struct Node *temp = *head_ref;
	
   *head_ref = temp->next;
	
   return temp;
}

void printList(struct Node *node){
  while (node != NULL)
  {
     printf("%d -> ", node->data);
     node = node->next;
  }
  printf("NULL");
}

void produce(int el){
    insertLast(&head, el);
    printf("\nProduced %d\n", el);
}

void consume(){
    struct Node *temp = deleteFirst(&head);
    printf("\nConsumed %d\n", temp->data);
    free(temp);
}

int main(){
    int id, el = 1;

    #pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();

        if(id == 0){
            while(1){
                #pragma omp critical
                {
                    produce(el);
                    el++;
                    printf("List: ");
                    printList(head);
                    fgetc(stdin);
                }
            }
        } else {
            while(1){
                #pragma omp critical
                {
                    consume();
                    printf("List: ");
                    printList(head);
                    fgetc(stdin);
                }
            }
        }
    }

    return 0;
}