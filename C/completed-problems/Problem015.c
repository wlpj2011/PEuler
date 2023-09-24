#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <inttypes.h>

long sol_P015(int n);

unsigned long center_binom(int n);

long binom_recurse(int n, int k);

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
    printf("The solution to %s is %lu which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

long sol_P015(int n){
    // Finds the number of paths moving only down and right from the top left to the bottom right of an n x n grid.
    long result = 0;
    // result = center_binom(n);
    result = binom_recurse(2*n, n);
    return result;
}

unsigned long center_binom(int n){
    // Computer n choose k i.e. n!/((n-k)!k!)
    int k = n/2;
    if (k > n)
    {
        return 0;
    }
    if((k==0) || (k == n)){
        return 1;
    }
    unsigned long result = 1;
    for (unsigned long i = 1; i < n+1; i++)
    {
        result *=  (n+i);
        result /= i;
    }
    return result;
}

long binom_recurse(int n, int k){
    if (k > n)
    {
        return 0;
    }
    if((k==0) || (k == n)){
        return 1;
    }
    return binom_recurse(n - 1, k) + binom_recurse(n - 1, k - 1);
}