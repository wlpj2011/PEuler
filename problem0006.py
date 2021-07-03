import sys

def solution(n):
    squareSum = (n*n*(n+1)*(n+1))//4
    sumSquare = 0
    for i in range(1,n+1):
        sumSquare+=i*i
    return squareSum - sumSquare

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " + str(solution(n)))
