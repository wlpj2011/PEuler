#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

long sol_P013(int k, int n);

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: %s int n int k\n", argv[0]); //k is number of digits, n is number of numbers in file.
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    start = clock();
    long solution = sol_P013(k, n);
    end = clock();
    printf("The solution to %s is %li which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

long sol_P013(int k, int n){
    // Finds the first k digits of the sum of the first n numbers in the text file.
    long result = 0;
    FILE *fptr;

    fptr = fopen("/Users/William/PEuler/TextInputs/Problem013.txt","r");
    if(fptr == NULL) {
        printf("Not able to open Problem011.txt.\n");
        exit(1);
    }

    long new_num;

    rewind(fptr);
    for (int i = 0; i < n; i++){
        fscanf(fptr, "%13ld", &new_num);
        result += new_num;
        while (getc(fptr) != '\n'){}
    }

    result = result / (10 * 10 * 10 * 10);
    fclose(fptr);
    return result;
}

