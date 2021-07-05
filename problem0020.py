import sys
from tools import digitSum
from math import factorial

def solution(n):
    return digitSum(factorial(n))
    
if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " +str(solution(n)))
