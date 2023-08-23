import sys
from tools import digitSum

def solution(n):
    return digitSum(2**n)
    
if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " +str(solution(n)))
