#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P007(int n);

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
    int solution = sol_P007(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P007(int n){
    // Finds the nth prime number
    int result = 0;
    int numPrimes = 0;
    int i = 0;
    while (numPrimes < n+1)
    {
        if(is_prime(i)){
            result = i;
            numPrimes += 1;
        }
        i+=1;
    }
    result = i-1;
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