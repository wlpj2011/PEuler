#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P020(int n);

int sum(int *intlist, int listlength);

void multiply(int *intlist, int listlength, int mult, int numdigitsmult);


int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P019(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P020(int n){
    // Computes the sum of the digits of n! draws heavily on 016, just modifiying the multiplication function to work numbers that aren't just 1 digit
    // Also changes the size estimate to use Stirling's factorial approximation
    int result = 0;
    double size = pow(2.0, (double)n); //Change this to stirling's formula
    int numdigits = 1 + (int)log10(size);

    int *digits = malloc(numdigits * sizeof(int));
    digits[0] = 1;
    for (int i = 1; i < numdigits; i++){
        digits[i] = 0;
    }

    for (int i = 1; i < n+1; i++){
        int numdigitsi = (int) log10(i); 
        multiply(digits, numdigits, i, numdigitsi);
    }

    result = sum(digits, numdigits);

    free(digits);

    return result;
}

void multiply(int *digits, int numdigits, int mult, int numdigitsmult){
    // mult should be in the range 0 <= mult <= 9
    int carries = 0;
    if(numdigitsmult == 1){
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
    else {
        //Need to extract the digits of mult and carry out multiplcation with them
    }
}

int sum(int *digits, int numdigits){
    int result = 0;
    for (int i = 0; i < numdigits; i++){
        result += digits[i];
    }
    return result;
}