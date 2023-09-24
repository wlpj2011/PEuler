#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P017(int n);

int wordlength(int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P017(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P017(int n){
    // Finds the number of letters used to write out all the numbers from 1 to n
    int result = 0;

    for (int i = 1; i < n+1; i ++){
        result += wordlength(i);
    }

    return result;
}

int wordlength(int n){
    if( n == 0){
        return 0; // Not strictly true, but makes the code easier and we never need the actual length of 0
    } else if((n == 1) || (n == 2) || (n == 6) || (n ==10 )){
        return 3;
    } else if((n == 4) || (n == 5) || (n == 9)){
        return 4;
    } else if((n == 3) || (n == 7) || (n == 8) || (n == 40) || (n == 50) || (n == 60)){
        return 5;
    } else if((n == 11) || (n == 12) || (n == 20) || (n = 30 || (n == 80) || (n = 90))){
        return 6;
    } else if((n == 15)|| (n == 16) || (n == 70)){
        return 7;
    } else if((n == 13) || (n == 14) || (n == 18) || (n == 19)){
        return 8;
    } else if(n == 17){
        return 9;
    } else if(n < 30){
        return wordlength(20) + wordlength(n - 20);
    } else if(n < 40){
        return wordlength(30) + wordlength(n - 30);
    } else if (n < 50){
        return wordlength(40) + wordlength(n - 40);
    } else if (n < 60){
        return wordlength(50) + wordlength(n - 50);
    } else if (n < 70){
        return wordlength(60) + wordlength(n - 60);
    } else if (n < 80){
        return wordlength(70) + wordlength(n - 70);
    } else if (n < 90){
        return wordlength(80) + wordlength(n - 80);
    } else if (n < 100){
        return wordlength(90) + wordlength(n - 90);
    } else if (n < 1000){
        return wordlength(n / 100) + 10 + wordlength(n % 100);
    } else if (n == 1000)
    {
        return 11;
    }
    return -1;
}