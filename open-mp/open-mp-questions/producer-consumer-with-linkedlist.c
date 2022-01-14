#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// A linked list node
struct Node{
  int data;
  struct Node *next;
};

struct Node* head = NULL;

void insertLast(struct Node** head_ref, int new_data){
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;  /* used in step 5*/

    /* 2. put in the data  */
    new_node->data  = new_data;

    /* 3. This new node is going to be the last node, so make next of
          it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;
    return;
}

struct Node* deleteFirst(struct Node** head_ref) {
    if (*head_ref == NULL){
       printf("List is empty!");
       return NULL;
    }

   //save reference to first link
   struct Node *temp = *head_ref;
	
   //mark next to first link as first 
   *head_ref = temp->next; // Changed head
	
   //return the deleted link
   return temp;
}

// This function prints contents of linked list starting from head
void printList(struct Node *node){
  while (node != NULL)
  {
     printf("%d -> ", node->data);
     node = node->next;
  }
  printf("NULL");
}

void produce(int el){
    // #pragma omp critical
    // {
        insertLast(&head, el);
        printf("\nProduced %d\n", el);
    // }
}

void consume(){
    // #pragma omp critical
    // {
        struct Node *temp = deleteFirst(&head);
        printf("\nConsumed %d\n", temp->data);
        free(temp);
    // }
}

/* Driver program to test above functions*/
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