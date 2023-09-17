#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

long sol_P015(int n);

long binom(int n, int k);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    long solution = sol_P015(n);
    end = clock();
    printf("The solution to %s is %li which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

long sol_P015(int n){
    // Finds the number of paths moving only down and right from the top left to the bottom right of an n x n grid.
    long result = 0;
    result = binom(2*n, n);
    return result;
}

long binom(int n, int k){
    // Computer n choose k i.e. n!/((n-k)!k!)
    if(k > n){
        return 0;
    }
    if((k==0) || (k == n)){
        return 1;
    }
    unsigned long result = 1;
    for (long i = k+1; i < n+1; i++)
    {
        result *=  i;
    }
    for (long i = 1; i < n - k + 1; i++)
    {
        result /= i;
    }
    printf("%li\n", result);
    printf("%lu\n", sizeof(long long));
    return result;
}
