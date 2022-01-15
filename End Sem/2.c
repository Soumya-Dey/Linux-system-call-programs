#include<stdio.h>
#include<omp.h>

int DATA = 30;
int main(){
    int id;
    omp_set_dynamic(0);
    #pragma omp parallel num_threads(3)
    {
        id = omp_get_thread_num();

        // Reader thread 1
        if(id == 0){
                #pragma omp critical
                {
                    printf(" Reader thread 1. DATA = %d", DATA);
                    fgetc(stdin);
                }
        }
        // Reader thread 2
        else if(id == 1){
                #pragma omp critical
                {
                    printf(" Reader thread 2. DATA = %d", DATA);
                    fgetc(stdin);
                }
        }
        // Writer thread
        else{
                #pragma omp critical
                {
                    DATA *= 2;
                    printf(" Writer thread. Doubling the value, DATA = %d", DATA);
                    fgetc(stdin);
                }
        }
    }
    return 0;
}
