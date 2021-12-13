#include <stdio.h>
#include <omp.h>

int series(int n) {
    int s1, s2;

    if (n < 0) return 1;
    else if (n == 1 || n == 2) return n; 
    else {
        #pragma omp task shared(s1)
        s1 = series(n - 1);

        #pragma omp task shared(s2)
        s2 = series(n - 2);

        #pragma omp taskwait
        return s1 * s2;
    }
}


int main(){
 int n;

 printf("Enter the value of N = ");
 scanf("%d", &n);
 printf("%dth term of the series = %d\n", n, series(n));

 return 0;
}