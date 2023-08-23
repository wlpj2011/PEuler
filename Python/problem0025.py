import sys
from tools import digitSum
from math import log10,ceil,sqrt

def solution(n):
    return ceil((log10(n*sqrt(5)-1/2))/log10((1+sqrt(5))/2))

if __name__=="__main__":
    # Only works up to n=307
    n = float(sys.argv[1])
    print("The solution is: " +str(solution(10**n)))