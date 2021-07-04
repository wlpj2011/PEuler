import sys
from tools import factors,sumnPowk

def solution(n):
    i = 200000
    while len(factors(sumnPowk(i,1))) < n:
        i+=1
    return sumnPowk(i,1)

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " + str(solution(n)))
