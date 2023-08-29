#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sol_P001(int n);

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Usage: %s int n\n", argv[0]);
        exit(1);
    }
    clock_t start, end;
    double cpu_time_used;
    int n = atoi(argv[1]);
    start = clock();
    int solution = sol_P001(n);
    end = clock();
    printf("The solution to %s is %i which took %f seconds to compute.\n", argv[0], solution, ((double) (end - start))/CLOCKS_PER_SEC);
    exit(0);
}

int sol_P001(int n){
    int result = 0;
    for (int i = 0; i < n; i++){
        if((i%3==0) || (i%5 == 0)){
            result += i;
        }
    }
        return result;
}