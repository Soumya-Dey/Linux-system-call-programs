#include <stdio.h>
#include <omp.h>

int MAXSIZE = 8;       
int stack[8];     
int top = -1;            

int isEmpty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isFull() {

   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

int pop() {
   int data;
	
   if(!isEmpty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int data) {

   if(!isFull()) {
      top = top + 1;   
      stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}

int main(){
    int id, num;
    omp_set_dynamic(0);

    #pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();

        if(id == 0){
            while(1){
                #pragma omp critical
                {
                    if(!isFull()){
                        printf("Enter a number to push\n");
                        scanf("%d", &num);
                        push(num);
                    } else {
                        printf("Stack is full");
                    }

                    fgetc(stdin);
                }
            }
        } else {
            while(1){
                #pragma omp critical
                {
                    if(!isEmpty()){
                        printf("Deleted item = %d\n", pop());
                    } else {
                        printf("Stack is empty");
                    }
                    
                    fgetc(stdin);
                }
            }
        }
    }

    return 0;
}