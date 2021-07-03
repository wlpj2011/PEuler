import sys
from tools import isPrime

def solution(n):
    numPrimes = 0
    for i in range(2,10000*n+1):
        if isPrime(i):
            numPrimes +=1
        if numPrimes == n:
            return i
    return numPrimes

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: "+str(solution(n)))
