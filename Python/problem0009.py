import sys

def solution(n):
    for i in range(1,n+1):
        for j in range(1,n+1-i):
            k = n-i-j
            if i*i+j*j==k*k:
                return i*j*k

if __name__=="__main__":
    n = int(sys.argv[1])
    print("The solution is: " + str(solution(n)))
