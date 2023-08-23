import sys
from tools import isPrime

def solution1(n):
    largest = 1
    for i in range(2,n):
        if n%i==0 and isPrime(i):
            largest=i
            # print(largest)
    return largest

def solution2(n,factors):
    for i in range(2,n):
        if n%i==0 and isPrime(i):
            factors.append(i)
            m = int(n/i)
            return solution2(m,factors)
    return n

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " + str(solution2(n,[])))
