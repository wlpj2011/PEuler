#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P009(int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P009(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P009(int n){
    // Finds the product of a pythagorean triple with sum n
    int result = 0;

    int k = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1 - i; j++){
            k = n - i - j;
            if(i*i + j*j == k*k){
                result = i * j * k;
            }
        }
    }

    return result;
}

