#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P004(int n);

bool is_palindrome(int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P004(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P004(int n){
    // Computes the largest palindrome that is a product of n digit numbers
    int result = 0;

    for (int i = (int) powf(10.0f, (float) (n-1)); i < (int) powf(10.0f, (float) n); i++){
        for (int j = (int) powf(10.0f, (float) (n-1)); j < (int) powf(10.0f, (float) n); j++){
            if((i*j > result) && (is_palindrome(i*j))){
                result = i * j;
            }
        }
    }

    return result;
}

bool is_palindrome(int n){
    int numdigits = ceilf(log10f(0.1f + (float)n));
    int digitarray[numdigits];
    for (int i = numdigits - 1; i > -1; i--)
    {
        int powten = (int)powf(10.0f, (float)i);
        digitarray[i] = n / powten;
        n -= powten * digitarray[i];
    }

    for (int i = 0; i < numdigits / 2; i++){
        if(digitarray[i] != digitarray[numdigits - i - 1]){
            return false;
        }
    }
    return true;
}