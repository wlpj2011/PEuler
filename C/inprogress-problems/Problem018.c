#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P018(int n);


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P018(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P018(int n){
    // Finds the number of letters used to write out all the numbers from 1 to n
    int result = 0;
    FILE *fptr;

    fptr = fopen("/Users/William/Desktop/PEuler/TextInputs/Problem018.txt","r");

    if(fptr == NULL) {
        printf("Not able to open Problem018.txt.\n");
        exit(1);
    }
    rewind(fptr);

    int *digits[n];
    for (int i = 0; i < n; i ++){
        digits[i] = malloc((i + 1) * sizeof(int));
    }


    fclose(fptr);
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < i; j++){
            fscanf(fptr, "%2d", &digits[i][j]);
        }
    }

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < i; j++){
            printf("%2d ", digits[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        free(digits[i]);
    }
    return result;
}
