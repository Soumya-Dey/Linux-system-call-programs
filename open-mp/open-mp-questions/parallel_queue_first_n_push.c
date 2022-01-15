#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

#define MAX 20

int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

bool isEmpty() {
   return itemCount == 0;
}

bool isFull() {
   return itemCount == MAX;
}

int size() {
   return itemCount;
}  

void insert(int data) {

   if(!isFull()) {
	
      if(rear == MAX-1) {
         rear = -1;            
      }       

      intArray[++rear] = data;
      itemCount++;
   }
}

int removeData() {
   int data = intArray[front++];
	
   if(front == MAX) {
      front = 0;
   }
	
   itemCount--;
   return data;  
}

int main(){
    int id, num = 1;

    int n;
    printf("Enter value of N = ");
    scanf("%d",&n);

    omp_set_dynamic(0);

    #pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();

        if(id == 0){
            while(1){
                #pragma omp critical
                {
                    if(num <= n){
                        insert(num);
                        printf("Inserted %d to Queue", num);
                        num++;
                    } else {
                        printf("Already entered first %d natural numbers", n);
                    }

                    // for infinite insertion
                    // if(!isFull()){
                    //     insert(num);
                    //     printf("Inserted %d to Queue", num);
                    //     num++;
                    // } else {
                    //     printf("Queue Full");
                    // }

                    fgetc(stdin);
                }
            }
        } else {
            while(1){
                #pragma omp critical
                {
                    if(!isEmpty()){
                        printf("Deleted item = %d\n", removeData());
                    } else {
                        printf("Queue is empty");
                        num = 1;
                    }
                    
                    fgetc(stdin);
                }
            }
        }
    }

    return 0;
}