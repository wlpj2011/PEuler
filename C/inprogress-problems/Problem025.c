#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P025(int n);


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P025(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P025(int n){
    // Returns the index of the first Fibonacci number with at least n digits
    int result = 0;
    result = (int)ceil((log10(pow(10.0, (double)n) * sqrt(5.0) - 0.5)) / log10((1.0 + sqrt(5.0)) / 2));
    return result;
}
