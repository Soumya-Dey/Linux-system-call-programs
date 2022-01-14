#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <omp.h>

#define MAX 10

int arr[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;

int peek() {
   return arr[front];
}

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

            arr[++rear] = data;
            itemCount++;
        }
}

int removeData() {
        int data = arr[front++];
            
        if(front == MAX) {
            front = 0;
        }
            
        itemCount--;
        return data; 
}

void produce(int el){
    // #pragma omp critical
    // {
        insert(el);
        printf("Produced %d\n", el);
    // }
}

void consume(){
    // #pragma omp critical
    // {
        int n = removeData();
        printf("Consumed %d\n", n);
    // }
}

int main() {
    int id, el = 1;
    printf("Element at front: %d\n", peek());

    #pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();

        if(id == 0){
            while(1){
                #pragma omp critical
                {
                    if(!isFull()){
                        produce(el);
                        el++;
                    } else {
                        printf("Quese full. Cannot produce.");
                    }
                    fgetc(stdin);
                }
            }
        } else {
            while(1){
                #pragma omp critical
                {
                    if(!isEmpty()){
                        consume();
                    } else {
                        printf("Quese Empty. Cannot consume.");
                    }
                    fgetc(stdin);
                }
            }
        }
    }

    printf("Element at front: %d\n", peek());

    return 0;
}