import sys
from math import comb

def solution(n,m):
    return comb(n+m,m)

if __name__=="__main__":
    n = int(sys.argv[1])
    m = int(sys.argv[2])
    print("The solution is: " +str(solution(n,m)))
