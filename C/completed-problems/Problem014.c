#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P014(int n);

long collatz(long n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P014(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P014(int n){
    // Finds the longest chain produced by the Collatz map that has a seed < n
    int result = 0;
    int current_chain_length = 0;
    int longest_chain_length = 0;
    long current_value = 0;
    for (int i = 1; i < n; i++)
    {
        current_chain_length = 0;
        current_value = (long) i;
        do{
            current_value = collatz(current_value);
            current_chain_length += 1;
            if(current_value < 1){
                printf("current value: %li\n", current_value);
                exit(1);
            }
        } while (current_value != 1);
        if (longest_chain_length < current_chain_length)
        {
            longest_chain_length = current_chain_length;
            result = i;
        }
    }

    return result;
}

long collatz(long n){
    if((n % 2) == 0){
        return n / 2;
    }
    return n * 3 + 1;
}
