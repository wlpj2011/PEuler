#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sol_P002(int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P002(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P002(int n){
    // Computes the sum of even value Fibonacci numbers less than n
    int result = 0;
    int fibon = 2;
    int fibon_1 = 1;
    int fibon_2 = 1;
    int temp = 0;
    while (fibon < n)
    {
        temp = fibon;
        fibon = fibon + fibon_1;
        fibon_1 = temp;
        if(fibon_1 % 2 == 0){
            result += fibon_1;
        }
    }
    return result;
}