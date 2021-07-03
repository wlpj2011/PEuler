import sys
from tools import isPalin

def solution(n):
    largest = 1
    for i in range(n):
        for j in range(n):
            k = i*j
            if k > largest and isPalin(k):
                largest = k
    return largest

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: "+ str(solution(n)))
