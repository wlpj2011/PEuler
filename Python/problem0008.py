import sys

def solution(n,j):
    largest = 1
    for i in range(len(n)-j-1):
        prod = 1
        for k in range(j):
            prod *= int(n[i+k])
        if largest < prod:
            largest = prod
    return largest

if __name__=="__main__":
    n = sys.argv[1]
    print("The solution is: " + str(solution(n,13)))
