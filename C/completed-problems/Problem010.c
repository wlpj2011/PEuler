#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

long sol_P010(int n);

bool is_prime(int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    long solution = sol_P010(n);
    end = clock();
    printf("The solution to %s is %li which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

long sol_P010(int n){
    // Finds the sum of the primes below n.
    long result = 0;

    for (int i = 1; i < n; i++)
    {
        if(is_prime(i)){
            result += i;
        }
    }

    return result;
}

bool is_prime(int n){
    // returns true if n is prime and false otherwise
    if(n == 1){
        return false;
    }
    for (int i = 2; i < (int) ceil(sqrt((double)n))+1; i++){
        if(n == i){
            return true;
        }
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

