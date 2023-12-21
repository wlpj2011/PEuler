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
    // Finds that largest sum of a path from top to bottom in the triangle in Problem018.txt
    int result = 0;
    FILE *fptr;

    fptr = fopen("/Users/William/Desktop/PEuler/TextInputs/Problem018.txt","r");

    if(fptr == NULL) {
        printf("Not able to open Problem018.txt.\n");
        exit(1);
    }
    rewind(fptr);

    int *digits[n]; //Create structure to hold the digits
    for (int i = 0; i < n; i ++){
        digits[i] = malloc((i + 1) * sizeof(int));
    }

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < i+1; j++){
            fscanf(fptr, "%2d", &digits[i][j]);
        }
    }

    fclose(fptr);

    int tempresult = 0;
    int path = 0;
    int currentposition = 0;
    for (int i = 0; i < (1 << (n-1)); i++)
    {
        path = i;
        tempresult = digits[0][0];
        currentposition = 0;

        for (int j = 0; j < n-1; j++){
            if(path % 2){
                currentposition++;
                tempresult += digits[j + 1][currentposition];
            }
            else
            {
                tempresult += digits[j + 1][currentposition];
            }
            path = (path >> 1);
        }
        if(tempresult > result){
            result = tempresult;
        }
    }

    for (int i = 0; i < n; i++) //Free the memory of the structure holding the digits
    {
        free(digits[i]);
    }
    return result;
}
