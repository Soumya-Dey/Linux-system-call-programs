#include<stdio.h>
#include<omp.h>

int main(){
    int num = 5, id;
    omp_set_dynamic(0);

    #pragma omp parallel num_threads(2)
    {
        id = omp_get_thread_num();

        // Reader thread
        if(id == 0){
            while(1){
                #pragma omp critical
                {
                    printf(" Reader thread. Value = %d", num);
                    fgetc(stdin);
                }
            }
        }
        // Writer thread
        else{
            while(1){
                #pragma omp critical
                {
                    num++;
                    printf(" Writer thread. Incrementing Value, Value = %d", num);
                    fgetc(stdin);
                }
            }
        }
    }
    
    return 0;
}