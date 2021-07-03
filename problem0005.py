import sys
from tools import isPrime
from math import log,pow,floor

def solution(n):
    result = 1
    for i in range(2,n+1):
        if isPrime(i):
            result*=pow(i,int(floor(log(n,i))))
    return int(result)

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " + str(solution(n)))
