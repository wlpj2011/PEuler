#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

int sol_P019(int n);

bool is_leap_year(int n);

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

int sol_P019(int n){
    // Counts the number of Sundays that occur on the first of the month during the twentieth century
    // The input is not necessary here, but I don't feel like removing it
    int result = 0;

    int numberofdaysinmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int dayoftheweek = 0;
    int dayofthemonth = 0;
    int monthoftheyear = 0;
    for (int i = 1901; i < 2001; i++)
    {
        monthoftheyear = 0;
        dayofthemonth = 0;
        if (is_leap_year(i))
        {
            for (int day = 0; day < 366; day++){

                if((dayofthemonth == 1) && (dayoftheweek == 6)){
                    result += 1;
                }

                dayoftheweek++;
                if (dayoftheweek == 7)
                {
                    dayoftheweek = 0;
                }
                dayofthemonth++;
                if (dayofthemonth == numberofdaysinmonth[monthoftheyear]){
                    monthoftheyear++;
                    dayofthemonth = 0;
                }
            }
        }
        else{
            for (int day = 0; day < 365; day++){
                if((dayofthemonth == 1) && (dayoftheweek == 6)){
                    result += 1;
                }

                dayoftheweek++;
                if (dayoftheweek == 7)
                {
                    dayoftheweek = 0;
                }
                dayofthemonth++;
                if (((dayofthemonth == numberofdaysinmonth[monthoftheyear]) &&( monthoftheyear != 2) )|| (dayofthemonth == 29)){
                    monthoftheyear++;
                    dayofthemonth = 0;
                }
            }
        }

    }

    return result;
}

bool is_leap_year(int n){
    if(n % 4){
        if(n % 100){
            if(n%400){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}