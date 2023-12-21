#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P011(int n, int length);

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    int length = atoi(argv[2]);
    start = clock();
    int solution = sol_P011(n, length);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P011(int n, int length){
    // Finds the greatest product of n adjacent numbers in the grid in the in Problem011.txt with dimensions length x length
    FILE *fptr;
    
    int result = 0;

    fptr = fopen("/Users/William/PEuler/TextInputs/Problem011.txt","r");
    if(fptr == NULL) {
        printf("Not able to open Problem011.txt.\n");
        exit(1);
    }

    int digits[length][length];

    rewind(fptr);
    for (int i = 0; i < length; i++){
        for (int j = 0; j < length; j++){
            fscanf(fptr, "%2d", &digits[i][j]);
        }
    }

    for (int i = 0; i < length - n; i++){
        for (int j = 0; j < length - n; j++){
            if( digits[i][j]* digits[i+1][j]* digits[i+2][j]* digits[i+3][j] > result){
                result =  digits[i][j] *  digits[i + 1][j] *  digits[i + 2][j] *  digits[i + 3][j];
            }
            if( digits[i][j]* digits[i][j+1]* digits[i][j+2]* digits[i][j+3] > result){
                result =  digits[i][j] *  digits[i][j + 1] *  digits[i][j + 2] *  digits[i][j + 3];
            }
            if( digits[i][j]* digits[i+1][j+1]* digits[i+2][j+2]* digits[i+3][j+3] > result){
                result =  digits[i][j] *  digits[i + 1][j + 1] *  digits[i + 2][j + 2] *  digits[i + 3][j + 3];
            }
            if( digits[i+3][j]* digits[i+2][j+1]* digits[i+1][j+2]* digits[i][j+3] > result){
                result =  digits[i + 3][j] *  digits[i + 2][j + 1] *  digits[i + 1][j + 2] *  digits[i][j + 3];
            }
        }
    }

    fclose(fptr);

    return result;
}

