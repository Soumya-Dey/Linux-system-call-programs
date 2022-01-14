#include <stdio.h>
#include <omp.h>

int main(){
    int a2, a3, id;
    omp_set_dynamic(0);

    #pragma omp parallel num_threads(3)
    {
        id = omp_get_thread_num();

        if(id == 0){
            while(1){
                #pragma omp critical
                {
                    a2 = 18;
                    printf("a2 = %d", a2);
                    fgetc(stdin);
                }
            }
        }
        else if(id == 1){
            while(1){
                #pragma omp critical
                {
                    a3 = 7;
                    printf("a3 = %d", a3);
                    fgetc(stdin);
                }
            }
        }
        else{
            while(1){
                #pragma omp critical
                {
                    printf("a2+a3 = %d", a2+a3);
                    fgetc(stdin);
                }
            }
        }
    }
    
    return 0;
}