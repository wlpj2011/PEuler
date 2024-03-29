#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P012(int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P012(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P012(int n){
    // Finds the first triangular number with more than n divisors.
    int result = 0;

    int num_divisors = 0;
    int i = 1;
    while (num_divisors < n+1)
    {
        result += i;
        num_divisors = 0;
        for (int j = 0; j < result + 1; j++){
            if((result % j) == 0){
                num_divisors += 1;
            }
        }
        i++;
    }

    return result;
}

