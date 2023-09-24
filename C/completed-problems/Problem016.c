#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P016(int n);

int sum(int *intlist, int listlength);

void multiply(int *intlist, int listlength, int mult);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P016(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P016(int n){
    // Finds the sum of the digits of 2^n
    int result = 0;
    double size = pow(2.0, (double)n);
    int numdigits = 1 + (int)log10(size);

    int *digits = malloc(numdigits * sizeof(int));
    digits[0] = 1;
    for (int i = 1; i < numdigits; i++){
        digits[i] = 0;
    }

    for (int i = 0; i < n; i++){
        multiply(digits, numdigits, 2);
    }

    result = sum(digits, numdigits);

    free(digits);

    return result;
}

void multiply(int *digits, int numdigits, int mult){
    // mult should be in the range 0 <= mult <= 9
    int carries = 0;
    for (int i = 0; i < numdigits; i++)
    {
        digits[i] *= mult;
        digits[i] += carries;
        carries = 0;
        while (digits[i] > 9)
        {
            digits[i] -= 10;
            carries += 1;
        }
    }
}

int sum(int *digits, int numdigits){
    int result = 0;
    for (int i = 0; i < numdigits; i++){
        result += digits[i];
    }
    return result;
}
