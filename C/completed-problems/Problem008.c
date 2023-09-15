#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

long sol_P007(int n, int length);


int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: %s int n int length\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    int length = atoi(argv[2]);
    start = clock();
    long solution = sol_P007(n,length);
    end = clock();
    printf("The solution to %s is %li which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

long sol_P007(int n, int length){
    // Finds the greatest product of n adjacent digits out of the first length digits in the file. Give an error if length is too long.
    FILE *fptr;

    long result = 1;

    fptr = fopen("/Users/William/Desktop/PEuler/TextInputs/Problem008.txt","r");

    if(fptr == NULL) {
        printf("Not able to open Problem008.txt.\n");
        exit(1);
    }

    char digits[length];

    rewind(fptr);
    fread(digits, sizeof(char), length, fptr);

    long product = 1;
    for (int j = 0; j < length - n - 1; j++)
    {
        product = 1;
        for (int k = 0; k < n; k++){
            product *= (digits[j + k] - '0');
        }
        if(result < product){
            result = product;
        }
    }

    fclose(fptr);

    return result;
}

