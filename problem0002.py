import sys
from tools import fibo

def solution(n):
    result = 0
    postit = dict()
    for i in range(800):
        ifib = fibo(i,postit)
        if ifib < n  and ifib % 2 ==0:
            # print(ifib)
            result += ifib
        elif ifib > n:
            return result

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " + str(solution(n)))

