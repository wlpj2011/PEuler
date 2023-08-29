#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

long sol_P003(long n);

bool is_prime(long n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    long n = atol(argv[1]);
    start = clock();
    int solution = sol_P003(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

long sol_P003(long n){
    // Computes the largest prime factor of n
    long result = 0;

    for (long i = 2; i < n+1; i ++){
        if((n%i == 0)&&(is_prime(i))){
            result = i;
            n /= i;
            printf("%li\n", result);
        }
    }

        return result;
}

bool is_prime(long n){
    // returns true if n is prime and false otherwise
    if(n == 1){
        return false;
    }
    for (long i = 2; i < (long) ceil(sqrt((double)n))+1; i++){
        if(n == i){
            return true;
        }
        if(n % i == 0){
            return false;
        }
    }
    return true;
}