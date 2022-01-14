#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

#define MAX 8

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
    omp_set_dynamic(0);

    #pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();

        if(id == 0){
            while(1){
                #pragma omp critical
                {
                    if(!isFull()){
                        insert(num);
                        printf("Inserted %d to Queue", num);
                        num++;
                    } else {
                        printf("Queue is full");
                        num = 1;
                    }

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