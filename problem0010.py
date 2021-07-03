import sys
from tools import isPrime

def solution(n):
    sum = 0
    for i in range(2,n+1):
        if isPrime(i):
            sum += i
    return sum

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: "+str(solution(n)))
